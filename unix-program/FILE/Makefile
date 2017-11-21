cc := gcc
obj:= file_w y_n_answer get_line
all: $(obj)

file_w: file_w.c
	cc -o $@ $^
y_n_answer:y_n_answer.c
	cc -o $@ $^
get_line: get_line.c
	cc -o $@ $^

.PHONY : clean
clean:
	-rm $(obj) myfile


