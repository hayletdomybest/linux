#include "common.h"

extern struct stat* readstat(const char*);
extern void readpermission(mode_t);
extern void createfile(const char*,mode_t);