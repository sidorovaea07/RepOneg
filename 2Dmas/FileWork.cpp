#include "FileWork.h"

char * OpenAndReadFile(const char* myfile, int* ReadSize)
{
    FILE *fp = fopen(myfile, "r");
    if (!fp) {
        printf(RCOLOR "ERROR WHILE OPENING THE FILE.\n" WCOLOR);
    }
    fseek(fp, 0L, SEEK_END);
    size_t FileSize = ftell(fp);
    char *buff = (char *) calloc(FileSize + 2, sizeof (char *));
    //PRP(buff);
    fseek(fp, 0L, SEEK_SET);
    *ReadSize = (int) fread(buff, sizeof (char), FileSize, fp);
    buff[*ReadSize + 1] = '\n';
    fclose(fp);
    //PRP(buff);
    return buff;
}

int PrintToFile(char** ptrs, int linescnt)
{
    char ** save_ptr = ptrs;
    FILE * fp = fopen("newoutputfile.txt", "a+");
    if (!fp) {
        printf(RCOLOR "ERROR WHILE OPENING THE FILE.\n" WCOLOR);
    }
    for (int i = 0; i < linescnt; i++) {
        int j = 0;
        while (ptrs[i][j] != '\n' && ptrs[i][j] != '\0') {
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