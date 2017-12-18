CFLAGS  ?= -g -O2 -Wall
CFLAGS  += -I./
CC      ?=gcc
SOURCES :=main.c func.c
OBJECTS :=$(SOURCES:.c=.o)
OUTPUT  :=tumask

all: $(SOURCES) $(OUTPUT)

.c.o: 
	$(CC) -c -o $@ $< $(CFLAGS)
$(OUTPUT): $(OBJECTS)
	$(CC) -o $@ $^ 
clean:
	rm -f $(OUTPUT) $(OBJECTS)