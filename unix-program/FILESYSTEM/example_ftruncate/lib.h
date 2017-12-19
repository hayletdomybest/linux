#include "common.h"
#define readfsize(size) printf("size=%d\n",size);

extern sstat* readstat(const char*);
extern int creat_file(const char*,mode_t);
extern int resizefile(const char*,off_t);
extern char** anlys(char*);