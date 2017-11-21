#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/utsname.h>
#include "err_exit.h"
#include <limits.h>
#include <sys/param.h>
int main(void)
{
	struct utsname *uts;
	uts=malloc(sizeof(struct utsname));
	char *hostname=malloc(MAXHOSTNAMELEN * sizeof(char));
	size_t size=MAXHOSTNAMELEN;
	if(gethostname(hostname,size))
	{
		err_exit("faile");
	}
	printf("hostname %s \n",hostname);
	
	if(uname(uts)<0)
		err_exit("could not get system infonation");
	printf("system name %s \n",uts->sysname);

	free(hostname);
	free(uts);
	
}

