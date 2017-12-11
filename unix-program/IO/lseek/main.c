#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
int main(int argc,char** argv)
{
	const char bf1[]="ABCDEFGHIJ";
	const char bf2[]="abcdefghij";
	int fd=open("file.hole",O_WRONLY|O_CREAT|O_APPEND,0666);
	if(fd<0)
	{
		fprintf(stderr,"fd open erro");
		return -1;
	}
	int len1=strlen(bf1);
	int len2=strlen(bf2);
	if((write(fd,bf1,len1))!=len1)
	{
		fprintf(stderr,"bf1 write erro");
		return -1;
	}
	if((lseek(fd,40,SEEK_SET))<0)
	{
		fprintf(stderr,"seek erro");
		return -1;
	}
	if((write(fd,bf2,len2))!=len2)
	{
		fprintf(stderr,"bf2 write erro");
		return -1;
	}	
	close(fd);
	return 0;
}