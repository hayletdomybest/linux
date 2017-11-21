#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	printf("put answer y/n\n");
	while(1)
	{
		char c;
		c=tolower(fgetc(stdin));
		tolower(c);
		while(c!='\n' && c!=EOF)
		{
			if(c=='y')
				return 1;
			else if(c=='n')
				return 0;
			else
				printf("Type your answer y or n\n");
			c=tolower(fgetc(stdin));
		
		}
	}	
	return -1;



	return 0;
}
