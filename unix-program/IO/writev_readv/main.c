#include <error.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define size 100
void writev_test(int fd)
{
	printf("Will start writev test\n");

	char p1[]="hello how are you\n";
	char p2[]="I am fine thank you\n";
	struct iovec iov[2];
	iov[0].iov_base=p1;
	iov[0].iov_len=strlen(p1);
	iov[1].iov_base=p2;
	iov[1].iov_len=strlen(p2);
	int total=strlen(p1)+strlen(p2);
	int lenwritev=writev(fd,iov,2);
	printf("lenwritev %d total %d bytes\n",lenwritev,total);
	printf("writev test end\n\n");
}
void readv_test(fd)
{
	printf("Will  start readv test\n");
	char p1[size];
	char p2[size];
	struct iovec iov[2];
	memset(p1,0,100);
	memset(p2,0,100);
	iov[0].iov_base=p1;
	iov[0].iov_len=size;
	iov[1].iov_base=p2;
	iov[1].iov_len=size;
	int total=strlen(p1)+strlen(p2);
	int nbytes=readv(fd,iov,2);
	printf("Read %d bytes\n",nbytes);
	printf("%s",p1);
	printf("%s",p2);
	printf("Readv test end\n");
}


int main(void)
{
	int fd=open("file",O_RDWR|O_CREAT|O_APPEND,0666);
	if(fd<0)
	{
		perror("fd open error\n");
		return -1;
	}
	writev_test(fd);
	lseek(fd,0,SEEK_SET);
	readv_test(fd);

	return 0;
}




