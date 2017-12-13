#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int display_fl(int fildes)
{
	int fl=fcntl(fildes,F_GETFL);
	if(fl<0)
		return fl;
	int accmode= fl & O_ACCMODE;
	switch(accmode)
	{
		case O_WRONLY:
				printf("access mode is write only\n");
				break
		case O_RDONLY:
				printf("access mode is read only\n");
				break;
		case O_RDWR:
				printf("access mode is read write \n");
				break;
	}
	printf("attribute have ");
	if(fl & O_APPEND)
			printf("APPEND ");
	if(fl & O_NONBLOCK)
			printf("NONBLOCK ");
	putchar('\n');
		return fl;
}


int main(int argc,char** argv)
{
	return display_fl(STDOUT_FILENO);
}