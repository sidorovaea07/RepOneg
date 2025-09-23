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

int MyLen(char* s1, char* s2)
{
    int len = 0;
    char* save_ptr1 = s1;
    char* save_ptr2 = s2;
    while (s1 != s2)
    {
        s1++;
        len++;
    }
    s1 = save_ptr1;
    s2 = save_ptr2;
    return len + 1;
}

int AlphasCheck (char * s)
{
    char * save_ptr = s;
    int alphas = 0;
    while (*s != '\n' && *s != '\0') {
        if (isalpha(*s))
            alphas++;
        s++;
    }
    s = save_ptr;
    if (!alphas)
        return 0;
    else
        return 1;
}

ptrs* CreatePtrArr(int linescnt, char* buff)
{
    char* save_ptr = buff;
    ptrs* ptrsarr = (ptrs* )calloc((size_t)linescnt, sizeof(ptrs));
    if (!ptrsarr)
        return NULL;
    ptrs* save_ptr2 = ptrsarr;

    int i = 0;
    char* new_buff = NULL;
    ptrsarr[i].val = buff;
    ptrsarr[i].len = mystrchr(buff, '\n') + 1 - ptrsarr[i].val;
    while (i < linescnt) {
        new_buff = mystrchr(buff, '\n');
        if (new_buff) {
            if (AlphasCheck(new_buff + 1)) {
                i++;
                buff = ptrsarr[i].val = new_buff + 1;
                ptrsarr[i].len = mystrchr(buff, '\n') + 1 - ptrsarr[i].val;
                //PRD(ptrsarr[i].len);
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

int PtrsPrint(ptrs* ptrsarr, int linescnt)
{
    ptrs* save_ptr = ptrsarr;
    for (int i = 0; i < linescnt; i++) {
        for (int j = 0; j < ptrsarr[i].len; j++) {
            putchar(ptrsarr[i].val[j]);
        }
    }
    ptrsarr = save_ptr;
    return 0;
}