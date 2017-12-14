#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <memory.h>
#include <string.h>
#define size 100000

char buf[size];
const char error_message[]="In %d time error %d\n";
//char fmt[] = "%d Hi :( -> :) ---aha!---";
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
	char wbuf[]="%d Hi :( -> :) ---aha!---\n";
	
	char rebuf[40];
	int nbytes=0,wbytes=0,j=0,ntime=0,success=0,error=0;
	int fd=open("file",O_WRONLY|O_CREAT|O_APPEND,0666);
	memset(rebuf,0,40);
	if((set_nonblock(STDOUT_FILENO,1))<0)
	{
		fprintf(stderr,"set non block error\n");
		return -1;
	}
	while((nbytes+sizeof(wbuf))<size)
	{
		sprintf(&buf[nbytes],wbuf,j++);
		nbytes+=sizeof(wbuf);
		buf[nbytes]='\n';
		nbytes++;
	}
	for(wbytes=0;nbytes>0;)
	{
		int rw,len;
		rw=write(STDOUT_FILENO,&buf[wbytes],nbytes);
		ntime++;
		if(rw<0)
		{
			error++;
			sprintf(rebuf,error_message,ntime,error);
			len=strlen(rebuf);
			write(fd,rebuf,len*sizeof(char));
		}
		else
		{
			success++;
			nbytes-=rw;
			wbytes+=rw;
		}
	}
	fprintf(stderr,"error %d\n",error);
	return 0;
}

