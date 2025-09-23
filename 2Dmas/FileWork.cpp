#include "FileWork.h"

char * OpenAndReadFile(const char* myfile, int* ReadSize)
{
    FILE *fp = fopen(myfile, "r");
    if (!fp) {
        printf(RCOLOR "ERROR WHILE OPENING THE FILE.\n" WCOLOR);
    }
    fseek(fp, 0L, SEEK_END);
    size_t FileSize = (size_t)ftell(fp);
    char *buff = (char *) calloc(FileSize + 2, sizeof (char *));
    //PRP(buff);
    fseek(fp, 0L, SEEK_SET);
    *ReadSize = (int) fread(buff, sizeof (char), FileSize, fp);
    buff[*ReadSize + 1] = '\n';
    fclose(fp);
    //PRP(buff);
    return buff;
}

int PrintToFile(ptrs* ptrsarr, int linescnt)
{
    ptrs* save_ptr = ptrsarr;
    FILE *fp = fopen("newoutputfile.txt", "a+");
    if (!fp) {
        printf(RCOLOR "ERROR WHILE OPENING THE FILE.\n" WCOLOR);
    }
    for (int i = 0; i < linescnt; i++) {
        for (int j = 0; j < (ptrsarr[i]).len; j++) {
            fputc(ptrsarr[i].val[j], fp);
        }
    }
    fputs("----------\n", fp);
    fclose(fp);
    ptrsarr = save_ptr;
    return 0;
}