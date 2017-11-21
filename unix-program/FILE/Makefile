cc := gcc
obj:= file_w
all: $(obj)

file_w: file_w.c
	cc -o $@ $^

.PHONY : clean
clean:
	-rm $(obj) myfile


