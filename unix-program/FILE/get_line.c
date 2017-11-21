#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char** lip;
	size_t *n;
	FILE *stream=fopen("./myfile","r");
	n=malloc(sizeof(size_t) * 30);
	memset(n,10,10);
	if(!stream)
		return -1;
	lip=malloc(sizeof(char *) * 30);
	size_t j=getline(lip,n,stream);
	//j=getline(lip+1,n,stream);
	printf("%d\n",j);
	int i;
	for(i=0;i<j;i++)
	{
		puts(lip[i]);
	}	


	for(i=0;i<10;i++)
		free(lip[i]);
	free(lip);
	free(n);
	fclose(stream);
}
