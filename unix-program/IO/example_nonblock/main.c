#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>



int set_nonblock(int fildes,int status)
{
	int val=fcntl(fildes,F_GETFL);
	val=(status)? (val|O_NONBLOCK) : (val & ~O_NONBLOCK);
	return fcntl(fildes,F_SETFL,val);
}
int display_fl(int fildes)
{
		int val=fcntl(fildes,F_GETFL);
		int accmode=val & O_ACCMODE;
		switch(accmode)
		{
			case O_WRONLY:
				fprintf(stderr,"write only\n");
				break;
			case O_RDONLY:
				fprintf(stderr,"read only\n");
				break;	
			case O_RDWR:
				fprintf(stderr,"write read\n");
				break;
		}
		if(val & O_NONBLOCK)
		{
			fprintf(stderr,"NONBLOCK\n");
		}
}

int main(int argc,char** argv)
{
	fprintf(stderr," stdout before set non block fl:\n");
	display_fl(STDOUT_FILENO);
	if(!(set_nonblock(STDOUT_FILENO,1)))
	{
		fprintf(stderr,"set non block error\n");
	}
	fprintf(stderr," stdout after set non block fl:\n"
	display_fl(STDOUT_FILENO);
	
	
}

