#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <memory.h>

const char* params_parterns[]={"---","--x","-w-","-wx-","r--","r-x","rw-","rwx"};
struct stat* readstat(const char* filepath)
{
	struct stat* buf=(struct stat*)malloc(sizeof(struct stat));		
	if(stat(filepath,buf)<0)
	{
		perror("stat error\n");
		return NULL;
	}
	return buf;
}

char* get_params(mode_t mode)
{
	char* ref=(char*)calloc(9,sizeof(char));
	int i;
	for(i=2;i>=0;i--)
	{
		int mode_num=((mode>>(i*3)) & 0x07);
		printf("%d\n",mode_num);
		strcat(ref,params_parterns[mode_num]);
	}
	return ref;
}
int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		fprintf(stderr,"Format is a.out FILE\n");
		return -1;
	}
	struct stat* sbuf=readstat(argv[1]);
	if(sbuf==NULL)
	{
		fprintf(stderr,"get stat fail please check file if exit\n");
		return -1;
	}
	char* ans=get_params(sbuf->st_mode);
	puts(ans);
	
	free(sbuf);
	free(ans);
}