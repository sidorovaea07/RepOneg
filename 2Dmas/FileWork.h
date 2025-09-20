#ifndef filework
#define filework

#include "strfunc.h"

char * OpenAndReadFile(const char* myfile, int * ReadSize);
int PrintToFile(char **ptrs, int linescnt);

#endif