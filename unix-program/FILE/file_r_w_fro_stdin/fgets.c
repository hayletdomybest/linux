#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	FILE *p=fopen("test.txt","r+");
	char *buf=malloc(100);
	memset(buf,0,100);
	fgets(buf,100,p);
 	printf("%s",buf);
	while(*buf !='\0')
	{
		printf("%s",buf);
		memset(buf,0,100);
		fgets(buf,100,p);
	}
	return 0;

}
