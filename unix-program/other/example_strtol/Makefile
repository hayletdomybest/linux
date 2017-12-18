CC 	   := gcc
CFLAGS := -O2 -g -Wall

source  := $(shell ls *.c)
objects :=$(source:.c=.o)

OUTPUT := test

all: $(OUTPUT)

$(OUTPUT): $(source)
	$(CC) -o $@ $^ $(CFLAGS)