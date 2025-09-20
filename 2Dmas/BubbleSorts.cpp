#include "BubbleSorts.h"
int SwitchStr(char ** s1, char ** s2)
{
    char * temp = *s1;
    *s1 = *s2;
    *s2 = temp;
    return 0;
}

int BubbleSort(char **ptrs, int linescnt)
{
    int iter = 1;
    char ** save_ptr = ptrs;
    while (iter != 0) {
        iter = 0;
        for (int i = 0; i < linescnt - 1; i++) {
            if (!isalpha(*ptrs[i + 1])) {           //if 2 стр небукв - меняем
                SwitchStr(&ptrs[i], &ptrs[i+1]);    //ptrs[i] == *(ptrs + i) -> (ptrs + i)
                iter++;
            }
            else if (strcmp(ptrs[i], ptrs[i + 1]) > 0) {
                SwitchStr(&ptrs[i], &ptrs[i + 1]);
                iter++;
            }
        }    
    }
    ptrs = save_ptr;
    //PRP(&iter);
    return 0;
}

int RevBubbleSort(char **ptrs, int linescnt)
{
    char ** save_ptr = ptrs;
    int iter = 0;
    do {
        iter = 0;
        for (int i = 0; i < linescnt - 1; i++) {
            if (myrevstrcmp(ptrs[i], ptrs[i + 1]) > 0) {
                SwitchStr(&ptrs[i], &ptrs[i + 1]);
                iter++;
            }
        }    
    }
    while (iter != 0);
    ptrs = save_ptr;
    //PRP(&iter);
    return 0;
}
