/*
* File Name     : 170877_harsh_DR_module8_T006_8-7.c
* Description   : Write a routine bfree(p,n) that will free any arbitrary block p of n characters into the free list maintained by
                  malloc and free. By using bfree, a user can add a static or external array to the free list at any time.
* Author        : harsh_kerai
* Date          : 06/05/2025
*/

#include <stdio.h>
#include <unistd.h>

typedef long Align;

/* Header for each block */
union header {
    struct {
        union header *ptr;
        unsigned size;
    } s;
    Align x;   // force alignment
};

typedef union header Header;

static Header base;
static Header *freep = NULL;

/* myfree: put block ap in free list */
void myfree(void *ap)
{
    Header *bp, *p;

    bp = (Header *)ap - 1;

    for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
    {
        if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
            break;
    }

    /* join to upper neighbor */
    if (bp + bp->s.size == p->s.ptr)
    {
        bp->s.size += p->s.ptr->s.size;
        bp->s.ptr = p->s.ptr->s.ptr;
    }
    else
    {
        bp->s.ptr = p->s.ptr;
    }

    /* join to lower neighbor */
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

/* morecore: ask system for more memory */
static Header *morecore(unsigned nu)
{
    if (nu < 1024)
        nu = 1024;

    char *cp = sbrk(nu * sizeof(Header));
    if (cp == (char *)-1)
        return NULL;

    Header *up = (Header *)cp;
    up->s.size = nu;

    /* initialize free list if needed */
    if (freep == NULL)
    {
        base.s.ptr = freep = &base;
        base.s.size = 0;
    }

    myfree((void *)(up + 1));
    return freep;
}

/* mymalloc: general-purpose storage allocator */
void *mymalloc(unsigned nbytes)
{
    Header *p, *prevp;
    unsigned nunits;

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
            {
                prevp->s.ptr = p->s.ptr;
            }
            else
            {
                p->s.size -= nunits;
                p += p->s.size;
                p->s.size = nunits;
            }
            freep = prevp;
            return (void *)(p + 1);
        }

        if (p == freep)
        {
            if ((p = morecore(nunits)) == NULL)
                return NULL;
        }
    }
}

/* bfree: add arbitrary block to free list */
void bfree(void *p, unsigned n)
{
    Header *bp;

    if (n < sizeof(Header))
        return;

    unsigned nunits = n / sizeof(Header);
    if (nunits < 2)
        return;

    /* IMPORTANT FIX: initialize free list */
    if (freep == NULL)
    {
        base.s.ptr = freep = &base;
        base.s.size = 0;
    }

    bp = (Header *)p;
    bp->s.size = nunits;

    myfree((void *)(bp + 1));
}

/* ---------- TEST PROGRAM ---------- */

#define BUFSIZE 10000

/* Properly aligned buffer */
static union {
    Align x;
    char buf[BUFSIZE];
} buffer;

void b_free()
{
    printf("Adding static buffer to free list using bfree...\n");
    bfree(buffer.buf, BUFSIZE);

    void *p1 = mymalloc(100);
    void *p2 = mymalloc(200);

    printf("Allocated p1 = %p (100 bytes)\n", p1);
    printf("Allocated p2 = %p (200 bytes)\n", p2);

    myfree(p1);
    printf("Freed p1\n");

    myfree(p2);
    printf("Freed p2\n");

    void *p3 = mymalloc(150);
    printf("Allocated p3 = %p (150 bytes)\n", p3);

    return;
}
