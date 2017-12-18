#include "lib.h"
//S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH
int main(void)
{
	
	createfile("a.txt",S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
	fprintf(stderr,"creat file a.txt umask is disalbe --- -w- -w-\n");
	umask(0);
	createfile("b.txt",S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
	fprintf(stderr,"creat file b.txt umask is disalbe --- --- ---\n");
	umask(S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
	createfile("c.txt",S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
	fprintf(stderr,"creat file a.txt umask is disalbe --- rw- rw-\n");
	struct stat* sbuf;
	
	sbuf=readstat("a.txt");
	fprintf(stderr,"a.txt permission is ");
	readpermission(sbuf->st_mode);
	free(sbuf);
	
	sbuf=readstat("b.txt");
	fprintf(stderr,"b.txt permission is ");
	readpermission(sbuf->st_mode);
	free(sbuf);
	
	sbuf=readstat("c.txt");
	fprintf(stderr,"c.txt permission is ");
	readpermission(sbuf->st_mode);
	free(sbuf);
	return 0;
}