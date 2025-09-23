#include "BubbleSorts.h"

int Switch(ptrs *p1, ptrs *p2)
{
    char* temp = p1 -> val;
    p1 -> val = p2 -> val;
    p2 -> val = temp;

    int t = p1 -> len;
    p1 -> len = p2 -> len;
    p2 -> len = t;
    return 0;
}

ptrs* MySort(ptrs *ptrsarr, int linescnt)
{
    ptrs* save_ptr = ptrsarr;
    int iter = 0;
    do {
        iter = 0;
        for (int i = 0; i < linescnt - 1; i++) {
            if (!AlphasCheck(ptrsarr[i + 1].val)) {      
                Switch(&ptrsarr[i], &ptrsarr[i + 1]);
                iter++;
            }
            else if (mystrcmp(ptrsarr[i].val, ptrsarr[i + 1].val) > 0) {
                Switch(&ptrsarr[i], &ptrsarr[i + 1]);
                iter++;
                //PRP(&iter);
            }
        }   
    } while (iter != 0);
    ptrsarr = save_ptr;
    //PRP(&iter);
    return ptrsarr;
}

ptrs* MyRevSort(ptrs* ptrsarr, int linescnt)
{
    ptrs* save_ptr = ptrsarr;
    int iter = 0;
    do {
        iter = 0;
        for (int i = 0; i < linescnt - 1; i++) {
            if (myrevstrcmp(ptrsarr[i].val, ptrsarr[i + 1].val) > 0) {
                Switch(&ptrsarr[i], &ptrsarr[i + 1]);
                iter++;
                //PRP(&iter);
            }
        }    
    } while (iter != 0);
    ptrsarr = save_ptr;
    //PRP(&iter);
    return ptrsarr;
}
