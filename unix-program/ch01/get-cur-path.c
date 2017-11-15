#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <errno.h>
char* get_path(void)
{
	errno=0;
    int size=pathconf("/",_PC_PATH_MAX);
    if(size<0)
    {   printf("faile pathconf\n");
        exit(1);
    }
    char* buff=malloc(size+1);
    char* val=getcwd(buff,size);
    printf("%p %p \n",buff,val);
    if(!val && errno==ERANGE)
    {
        printf("the ram is not enough");
        return NULL;
    }
	return buff;
}
int main(void)
{
    char* ph=get_path();
    printf("my path %s\n",ph);
    free(ph);

    return 0;
}
