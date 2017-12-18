#include "lib.h"
//S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH
int main(void)
{
	
	umask(S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
	createfile("testfile",S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
	
	struct stat* sbuf=readstat("testfile");
	fprintf(stderr,"testfile permission is ");
	readpermission(sbuf->st_mode);
	
	if((access("testfile",F_OK))<0)
	{
		printf("file is not exit\n");
		return -1;
	}
	printf("file is  exit\n");
	if((access("testfile",R_OK))!=-1)
	{
		printf("can read file\n");
	}
	if((access("testfile",W_OK))!=-1)
	{
		printf("can write file\n");
	}
	if((access("testfile",X_OK))!=-1)
	{
		printf("can execute file\n");
	}	
	return 0;
}