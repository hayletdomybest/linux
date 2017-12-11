#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define size 1024
int main(int argc,char** argv)
{
	int from,to;
	char buf[1024];
	if(argc!=3)
		return -1;
	if((from=open(argv[1],O_RDONLY))<0){
		fprintf(stderr,"from oepn error\n");
		return -1;
	}
	if((to=open(argv[2],O_WRONLY|O_CREAT|O_APPEND,0644))<0){
		fprintf(stderr,"to open error\n");
		return -1;
	}
	 while(read(from,buf,size)>0){
		if(write(to,buf,size)<0){
			fprintf(stderr,"write error\n");
			return -1;	
		}
		return -1;
	}

	return 0;
}