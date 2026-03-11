CC      = gcc
CFLAGS  = -Wall -Wextra -g -Iinclude -DMODULE=$(MODULE) -DTASK=$(TASK)

BIN_DIR = bin
BIN     = $(BIN_DIR)/main.out

MAIN_SRC = main.c
MAIN_OBJ = obj/main.o

SEL_FUNC_SRC = lib/src/selectfunction.c
SEL_FUNC_OBJ = lib/obj/selectfunction.o

COMM_SRC = $(wildcard lib/src/comm_function/*.c)
COMM_OBJ = $(patsubst lib/src/comm_function/%.c, \
			lib/obj/comm_function/%.o, \
			$(COMM_SRC))

MOD_DIR = 170877_Harsh_DR_Module$(MODULE)_T006

TASK_SRC = $(MOD_DIR)/src/170877_harsh_DR_Module$(MODULE)_T006_$(MODULE)-$(TASK).c
TASK_OBJ = $(MOD_DIR)/obj/170877_harsh_DR_Module$(MODULE)_T006_$(MODULE)-$(TASK).o

all:$(BIN)

$(BIN): $(MAIN_OBJ) $(TASK_OBJ) $(SEL_FUNC_OBJ) $(COMM_OBJ) 
	$(CC) $(MAIN_OBJ) $(TASK_OBJ) $(SEL_FUNC_OBJ) $(COMM_OBJ) -o $(BIN) -lm

$(MAIN_OBJ): $(MAIN_SRC) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(SEL_FUNC_OBJ): $(SEL_FUNC_SRC) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

lib/obj/comm_function/%.o: lib/src/comm_function/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(MOD_DIR)/obj/%.o: $(MOD_DIR)/src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -f $(SEL_FUNC_OBJ) $(MAIN_OBJ) $(TASK_OBJ) $(BIN)

.PHONY: all clean

