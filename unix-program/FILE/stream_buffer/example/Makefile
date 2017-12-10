cc := gcc
file:=$(wildcard *.c)
obj:= $(patsubst %.c,%,${file})
all:$(obj)

$(obj):$(file)
	gcc -o $@ $^

.PHONY : clean
clean:
	-rm $(obj) myfile


