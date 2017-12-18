#include "lib.h"

int main(void)
{
	struct stat* sbuf=readstat("file");
	readpermission(sbuf->st_mode);
	return 0;
}