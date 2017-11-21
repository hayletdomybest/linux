cc:=gcc
out:=ch1-2 get-cur-path


all: ch1-2 


ch1-2: ch1-2.c err_exit.h
	cc -o $@ $^

get-cur-path: get-cur-path.c
	cc -o $@ $^

.PHONY : clean
clean:
	-rm $(out)

