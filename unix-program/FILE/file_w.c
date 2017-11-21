#include <stdio.h>
#include <string.h>
#define size 80
int main(void)
{
	char buf[size];
	FILE *stream=fopen("./myfile","w+");	
	printf("Will open file\n");
	if(!stream)
		return -1;
	printf("Tpye any test string\n");
	memset(buf,size,sizeof(buf));
	fgets(buf,sizeof(buf),stdin);
	fputs(buf,stream);
	fclose(stream);
	return -1;
}
