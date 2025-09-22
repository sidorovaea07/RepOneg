#include "BubbleSorts.h"

int SwitchStr(char ** s1, char ** s2)
{
    char * temp = *s1;
    *s1 = *s2;
    *s2 = temp;
    return 0;
}

char ** MySort(char **ptrs, int linescnt)
{
    char ** save_ptr = ptrs;
    int iter = 0;
    do {
        iter = 0;
        for (int i = 0; i < linescnt - 1; i++) {
            if (!AlphasCheck(ptrs[i + 1])) {      
                SwitchStr(&ptrs[i], &ptrs[i + 1]);
                iter++;
            }
            else if (mystrcmp(ptrs[i], ptrs[i + 1]) > 0) {
                SwitchStr(&ptrs[i], &ptrs[i + 1]);
                iter++;
                //PRP(&iter);
            }
        }   
    } while (iter != 0);
    ptrs = save_ptr;
    //PRP(&iter);
    return ptrs;
}

char ** MyRevSort(char **ptrs, int linescnt)
{
    char ** save_ptr = ptrs;
    int iter = 0;
    do {
        iter = 0;
        for (int i = 0; i < linescnt - 1; i++) {
            if (myrevstrcmp(ptrs[i], ptrs[i + 1]) > 0) {
                SwitchStr(&ptrs[i], &ptrs[i + 1]);
                iter++;
                //PRP(&iter);
            }
        }    
    } while (iter != 0);
    ptrs = save_ptr;
    //PRP(&iter);
    return ptrs;
}
