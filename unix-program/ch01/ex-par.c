#include <error.h>
#include <linux/err.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
int main(void)
{
	int i;
	char *str;

	for(i=1;i<=131;i++);
	{
		fatal(strerror(i));
	}

	return 0; 
}


