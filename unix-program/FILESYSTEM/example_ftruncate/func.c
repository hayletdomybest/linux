#include "common.h"


sstat* readstat(const char* path)
{
	sstat* sbuf=malloc(sizeof(sstat));
	if(stat(path,sbuf)<0)
	{
		printf("read stat error the file %s can't open\n",path);
		free(sbuf);
		return NULL;
	}
	return sbuf;
}
int creat_file(const char* path,mode_t mode)
{
	if(creat(path,mode)<0)
	{
		perror("creat file error\n");
		return -1;
	}
	return 0;
}
int resizefile(const char* path,off_t size)
{
	int fd=open(path,O_RDWR);
	if(fd<0)
	{
		printf("this file %s is not exist\n",path);
		return -1;
	}
	if(ftruncate(fd,size)<0)
	{
		printf("resize file error\n");
		return -1;
	}
	return 0;
}
char** anlys(char* org)
{
	char** ref=malloc(sizeof(char*) * 2);
	char* p=org,*pp;
	int i=0;
	while(*p!=' ' && *p)
	{
		i++;
		p++;
	}
	*p=0;
	ref[0]=malloc((i+1)*sizeof(char));
	strcpy(ref[0],org);
	while(*++p == ' ');
	i=0;
	pp=p;
	while(*p && *p!=' ')
	{
		i++;
		p++;
	}
	ref[1]=malloc((i+1) * sizeof(char));
	strcpy(ref[1],pp);
	return ref;
}

