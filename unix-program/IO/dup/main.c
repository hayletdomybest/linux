#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int error(char* s)
{
	fprintf(stderr,s);
	return -1;
}

int main(int argc,char** argv)
{
	int fd=open("test",O_WRONLY|O_CREAT|O_APPEND,0666);
	if(fd<0)
		return error("fd open error\n");
	int newfd=dup2(fd,STDOUT_FILENO);
	if(newfd<0)
		return error("newfd dup error\n");
	printf("test\n");
	return 0;
}
