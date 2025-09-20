#include "FileWork.h"

char * OpenAndReadFile(const char* myfile, int * ReadSize)
{
    FILE *fp = fopen(myfile, "r");
    if (!fp) {
        printf(RCOLOR "ERROR WHILE OPENING THE FILE.\n" WCOLOR);
    }
    fseek(fp, 0L, SEEK_END);
    size_t FileSize = ftell(fp);
    char *buff = (char *) calloc(FileSize + 10, sizeof (char));
    //PRP(buff);
    fseek(fp, 0L, SEEK_SET);
    *ReadSize = (int) fread(buff, sizeof (char), FileSize, fp);
    buff[*ReadSize] = '\n';
    buff[*ReadSize + 1] = '\0';
    fclose(fp);
    //PRP(buff);
    return buff;
}

int PrintToFile(char **ptrs, int linescnt)
{
    char ** save_ptr = ptrs;
    FILE * fp = fopen("outputfile.txt", "a");
    if (!fp) {
        printf(RCOLOR "ERROR WHILE OPENING THE FILE.\n" WCOLOR);
    }
    for (int i = 0; i < linescnt; i++) {
        int j = 0;
        while (ptrs[i][j] != '\n') {
            fputc(ptrs[i][j], fp);
            j++;
        }
        fputc('\n', fp);
    }
    fputs("----------\n", fp);
    fclose(fp);
    ptrs = save_ptr;
    return 0;
}