#include <stdio.h>
struct _item_{
	int i;
	char ii;
}item;

int main(void)
{
	FILE* stream=fopen("./test.txt","r+");
	if(stream==NULL)
		return -1;
	fread(&item,sizeof(item),1,stream);
	printf("%d %c\n",item.i,item.ii);
	return 0;
}
