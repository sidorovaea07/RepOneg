#ifndef strfunc
#define strfunc
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

//#define MAXSIZE 100
#define FCOLOR "\033[35m"
#define WCOLOR "\033[0m"
#define GCOLOR "\033[90m"
#define RCOLOR "\033[30m"
#define BCOLOR "\033[36m"
#define YCOLOR "\033[33m"

#define PRP(x) printf(BCOLOR "%p\n" WCOLOR, (x))
#define PRD(x) printf(BCOLOR "%d\n" WCOLOR, (x))
#define PRTF(x) printf(FCOLOR "print to file returned %d\n" WCOLOR, (x))
#define PRS(x) printf(FCOLOR "my sort returned %d\n" WCOLOR, (x))

int myputs (char *s);
int myrevstrcmp(const char * s1, const char * s2);
char* mystrchr (char * s, int c);
size_t mystrlen (const char * s);
char *mystrcat (char * s1, const char * s2);
char *mystrncat (char * s1, const char * s2, size_t n);
int myatoi(const char * nptr);
char * myfgets(char *str, int num, FILE *stream);
char *mystrdup(char *str);
int mygetline(char **lineptr, size_t *n, FILE *stream);  

#endif