CFLAGS  ?= -g -O2 -Wall
CFLAGS  += -I./
CC      ?= gcc
SOURCES := func.c main.c
OBJECTS := $(SOURCES:.c=.o)
FILE	:= testfile
OUTPUT  := taccess

all: $(SOURCES) $(OUTPUT)

.c.o: 
	$(CC) -c -o $@ $< $(CFLAGS)
$(OUTPUT): $(OBJECTS)
	$(CC) -o $@ $^ 
clean:
	rm -f $(OUTPUT) $(OBJECTS) $(FILE)
