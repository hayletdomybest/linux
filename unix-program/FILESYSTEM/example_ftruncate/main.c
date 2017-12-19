#include "lib.h"

const char* cmd="r:c:s:?";
const char 	help[]=\
{\
"-c: creat file with permission rw-r-----\n\
-?: display help message to help you how to use"\
};
int main(int argc,char** argv)
{
	readcmd(argc,argv);
	return 0;
}

//-c : creat file 
int readcmd(int argc,char** argv)
{
		int ch,ref;
		sstat* sbuf;char** buf;
		while((ch=getopt(argc,argv,cmd)))
		{
			switch(ch)
			{
				case 'r':
					sbuf=readstat(optarg);
					printf("%s size is %d\n",optarg,sbuf->st_size);
					free(sbuf);
					break;
				case 'c':
						ref=creat_file(optarg,S_IRUSR|S_IWUSR|S_IRGRP);
						break;
				case 's':
						puts(optarg);
						buf=anlys(optarg);
						
						ref=resizefile(buf[0],strtol(buf[1],NULL,10));
						free(buf[0]);
						free(buf[1]);
						free(buf);
						break;
				case '?':
					printf("%s\n",help);
					break;
				default:
					return ref;
			}
			
		}
		return ref;
	
}