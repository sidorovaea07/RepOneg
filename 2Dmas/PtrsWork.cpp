#include "PtrsWork.h"

int LinesCnt(char * buff)
{
    char * save_ptr = buff;
    int cnt = 0;
    while (*buff != '\0') {
        char * new_buff = mystrchr(buff, '\n');
        if (new_buff) {
            buff = new_buff + 1;
            cnt++;
        }
        else
            break;
    }
    buff = save_ptr;
    return cnt;
}

char ** CreatePtrArr(int linescnt, char * buff)
{
    char * save_ptr = buff;
    char ** ptrs = (char **) calloc(linescnt, sizeof (char));
    char ** save_ptr2 = ptrs;
    ptrs[0] = buff;
    for (int i = 1; i < linescnt; i++) {
        buff = (ptrs[i] = mystrchr(buff, '\n') + 1);
        PRP(ptrs[i]);
    }
    buff = save_ptr;
    return save_ptr2;
}

int PtrsPrint(char ** ptrs, int linescnt)
{
    char ** save_ptr = ptrs;
    for (int i = 0; i < linescnt; i++) {
        int j = 0;
        while (ptrs[i][j] != '\n') {
            putchar(ptrs[i][j]);
            j++;
        }
        putchar('\n');
    }
    ptrs = save_ptr;
    return 0;
}