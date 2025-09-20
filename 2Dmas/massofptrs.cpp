#include "needfor2d.h"

#define MAXSTR 1000
char ** ReadText (char ** ptrs, const int ExpN, FILE * fp);

int main()
{ 
    const int ExpN = 14;
    char* ptrs[ExpN] = {0};

    FILE *fp = fopen("myfile.txt", "r");
    

    if (!fp) {
        printf(RCOLOR "ERROR WHILE OPENING THE FILE.\n" WCOLOR);
    }

    ReadText(ptrs, ExpN, fp);

    for (int i = 0; i < ExpN; i++)
    {
        myputs(ptrs[i]);
    }
    
}

char ** ReadText (char ** ptrs, const int ExpN, FILE * fp)
{
    int i = 0;
    while (i < ExpN)
    {
        ptrs[i] = (char*)calloc(MAXSTR, sizeof(char *));
        myfgets(ptrs[i], MAXSTR, fp);
        i++;
    }
    return ptrs;
}