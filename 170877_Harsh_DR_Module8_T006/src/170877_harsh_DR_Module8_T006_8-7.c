/*
* File Name     : 170877_harsh_DR_module8_T006_8-7.c
* Description   : malloc accepts a size request without checking its plausibility; free believes that the block it is asked to
                  free contains a valid size field. Improve these routines so they make more pains with error checking.
* Author        : harsh_kerai
* Date          : 04/05/2025
*/
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

#define MAX_ALLOC 10000 // max allowed allocation (example limit)

        typedef long Align;

        union header
        {
                struct
                {
                        union header *ptr;
                        unsigned size;
                } s;

                Align x;
        };

        typedef union header Header;

        static Header base;
        static Header *freep = NULL;

        void *mymalloc(unsigned nbytes);
        void myfree(void *ap);
        static Header *morecore(unsigned nu);

        void *mymalloc(unsigned nbytes)
        {
                Header *p, *prevp;
                unsigned nunits;

                if (nbytes == 0 || nbytes > MAX_ALLOC)
                {
                        printf("Error: Invalid allocation size %u bytes.\n", nbytes);
                        return NULL;
                }

                if (nbytes > UINT_MAX - sizeof(Header))
                {
                        printf("Error: Size overflow.\n");
                        return NULL;
                }

                nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;

                if ((prevp = freep) == NULL)
                {
                        base.s.ptr = freep = prevp = &base;
                        base.s.size = 0;
                }

                for (p = prevp->s.ptr;; prevp = p, p = p->s.ptr)
                {

                        if (p->s.size >= nunits)
                        {
                                if (p->s.size == nunits)
                                        prevp->s.ptr = p->s.ptr;
                                else
                                {
                                        p->s.size -= nunits;
                                        p += p->s.size;
                                        p->s.size = nunits;
                                }

                                freep = prevp;
                                printf("mymalloc(%u)\tSuccessful allocation of %u bytes.\n", nbytes, nbytes);
                                return (void *)(p + 1);
                        }

                        if (p == freep)
                        {
                                if ((p = morecore(nunits)) == NULL)
                                {
                                        printf("Error: System out of memory.\n");
                                        return NULL;
                                }
                        }
                }
        }

        void myfree(void *ap)
        {
                Header *bp, *p;

                if (ap == NULL)
                {
                        printf("Error: Attempt to free NULL pointer.\n");
                        return;
                }

                if ((uintptr_t)ap % sizeof(Header) != 0)
                {
                        printf("Error: Invalid pointer passed to free.\n");
                        return;
                }

                bp = (Header *)ap - 1;

                if (bp->s.size == 0 || bp->s.size > MAX_ALLOC)
                {
                        printf("Error: Corrupted block or invalid size.\n");
                        return;
                }

                for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
                {
                        if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
                                break;
                }

                if (bp + bp->s.size == p->s.ptr)
                {
                        bp->s.size += p->s.ptr->s.size;
                        bp->s.ptr = p->s.ptr->s.ptr;
                }
                else
                {
                        bp->s.ptr = p->s.ptr;
                }

                if (p + p->s.size == bp)
                {
                        p->s.size += bp->s.size;
                        p->s.ptr = bp->s.ptr;
                }
                else
                {
                        p->s.ptr = bp;
                }

                freep = p;
        }

#define NALLOC 1024

        static Header *morecore(unsigned nu)
        {
                char *cp;
                Header *up;

                if (nu < NALLOC)
                        nu = NALLOC;

                cp = sbrk(nu * sizeof(Header));
                if (cp == (char *)-1)
                        return NULL;

                up = (Header *)cp;
                up->s.size = nu;

                myfree((void *)(up + 1));
                return freep;
        }

        void my_malloc()
        {
                void *p1, *p2;

                p1 = mymalloc(500);
                p2 = mymalloc(11000);

                myfree(p1);
                myfree((void *)0x12345678);

                return;
        }
