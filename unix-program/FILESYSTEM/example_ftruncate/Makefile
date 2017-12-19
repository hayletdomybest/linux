CFLAGS?= -O2 -g
CFLAGS+= -I./

CC?= gcc
#$(shell ls *.c)
source = $(shell ls *.c)

objects= $(source:.c=.o)

output=exec

all: $(source) $(output)

$(output): $(objects)
	$(CC) -o $@ $^ $(CFLAGS)

.c.o:
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
		rm -f $(objects) $(output)
 