#include <stdio.h>
#include <memory.h>
int main(void)
{
	FILE* stream=fopen("./test.txt","r+");
	char buf[100],buff[100];
	memset(buf,0,sizeof(char)*100);
	fread(&buf[0],sizeof(char),5,stream);
	fseek(stream,1,SEEK_CUR);
	fread(&buff[0],sizeof(char),6,stream);
	printf("%s %s\n",buf,buff);
        fseek(stream,10,SEEK_END);
	fwrite("bug",sizeof(char),3,stream);
	
	return 0;
}
