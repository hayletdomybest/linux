#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <memory.h>
const char file_name[]="file";
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

int main(void)
{
	char *buf;
	int desc=open(file_name,O_RDONLY);
	if(desc<0)
	{
		perror("open file fail\n");
		return -1;
	}
	struct stat* statbuf=readstat(file_name);
	buf=malloc((sizeof(char)* statbuf->st_size)+1);
	read(desc,buf,statbuf->st_size);
	buf[statbuf->st_size]='\0';
	puts(buf);
	free(statbuf);
	return -1;
}
