CC = gcc
MPICC = mpicc
BIN_DIR = bin
CFLAGS = -Wall -O3 -std=c99
LFLAGS = -lm

COMMON =

SOURCES = $(shell find src/ -name '*.c')
BINFILES = $(addprefix $(BIN_DIR)/, $(SOURCES:src/%.c=%))

all: $(BINFILES)

bin/%: src/%.c $(DEPS)
		@mkdir -p "$(@D)"
		$(MPICC) $(CFLAGS) -o $@ $< $(COMMON) $(LFLAGS)

bin/%_seq: src/%_seq.c $(DEPS)
		@mkdir -p "$(@D)"
		$(CC) $(CFLAGS) -o $@ $< $(COMMON) $(LFLAGS)

clean:
		@rm -rf $(BIN_DIR)
