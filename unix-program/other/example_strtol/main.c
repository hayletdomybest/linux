#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char* argv[])
{
	if(argc!=2){
		fprintf(stderr,"parameter is not match\n");
		return -1;
	}
	char* ptr;
	int length=strtol(argv[1],&ptr,10);
	if(ptr !=(argv[1]+strlen(argv[1])))
	{
		int dd=(argv[1]+strlen(argv[1]))-ptr+1;
		printf("error in %d character is string %s\n",dd,ptr);
		return -1;
	}
	printf("%d\n",length);
	
}