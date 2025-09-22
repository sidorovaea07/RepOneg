#include "PtrsWork.h"
#include "StrFunc.h"

int LinesCnt(char * buff)
{
    char * save_ptr = buff;
    int cnt = 0;
    //putchar(*buff);
    while (*buff != '\0') {
        char * new_buff = mystrchr(buff, '\n');
        //PRP(*new_buff);
        if (new_buff) {
            if (AlphasCheck(new_buff + 1)) {
                cnt++;
                //PRD(cnt);
            }
            buff = new_buff + 1;
        }
        else {
            break;
        }
    }
    buff = save_ptr;
    //PRD(cnt + 1);
    return cnt + 1;
}

char ** CreatePtrArr(int linescnt, char * buff)
{
    char * save_ptr = buff;
    char ** ptrs = (char **) calloc(linescnt, sizeof (char **));
    //PRP(ptrs);
    if (!ptrs)
        return NULL;
    char ** save_ptr2 = ptrs;
    ptrs[0] = buff;
    int i = 1;
    while (i < linescnt) {
        //printf("new buff is: ");
        char * new_buff = mystrchr(buff, '\n');
        //PRP(new_buff + 1);
        if (new_buff) {
            if (AlphasCheck(new_buff + 1)) {
                buff = ptrs[i] = new_buff + 1;
                //PRP(ptrs[i]);
                //PRP(buff);
                i++;
            }
            else
                buff = new_buff + 1;
        }
        else {
            break;
        }
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