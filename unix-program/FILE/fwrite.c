#include <stdio.h>
#include <memory.h>
struct _test_{
	int i;
	char ii;
}item;


int main(void)
{
	
	FILE *stream=fopen("./test.txt","r+");
	if(stream==NULL){
		printf("fail\n");
		return -1;
	}
        item.i=123;
	item.ii='x';	
	fwrite(&item,sizeof(item),1,stream);
	printf("%d %c",item.i,item.ii);
	
	return 0;
}

