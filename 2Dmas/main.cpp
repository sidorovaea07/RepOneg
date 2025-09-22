#include "FileWork.h"
#include "BubbleSorts.h"
#include "PtrsWork.h"
#include <assert.h>
// rm -rf outputfile.txt
 
// структура для массива указателей: указатель + длина
// добавить stat, qsort, непосимвольный вывод

//MySort
/*
algorithm.
....
...
if (MyComparator())
    swap two elems
*/
/*
simple versions -> comprator on void* & qsort -> rewrite sorts functions

*/
struct ptrs {
    char **val;
    int len;
};

struct Data {
    const char * input;
    struct ptrs prim;
    struct ptrs sorted;
    struct ptrs revsorted;
    int linescnt;
    char *buff;
    int size;
};

int main()
{
    struct Data OnE;                                    //Onegin Evgene
    OnE.input = "inputfile.txt";
    OnE.size = 0;
    OnE.buff = OpenAndReadFile(OnE.input, &OnE.size);
    PRD(OnE.linescnt = LinesCnt(OnE.buff));
    puts(OnE.buff);
    OnE.prim.val = CreatePtrArr(OnE.linescnt, OnE.buff);
    
    OnE.sorted.val = (char **)calloc(OnE.linescnt, sizeof(char **));
    for (int i = 0; i < OnE.linescnt; i++) {
        OnE.sorted.val[i] = OnE.prim.val[i];
    }
    MySort(OnE.sorted.val, OnE.linescnt);
    
    OnE.revsorted.val = (char **)calloc(OnE.linescnt, sizeof(char **));
    for (int i = 0; i < OnE.linescnt; i++) {
        OnE.revsorted.val[i] = OnE.prim.val[i];
    }
    MyRevSort(OnE.revsorted.val, OnE.linescnt);
    
    PRTF(PrintToFile(OnE.prim.val, OnE.linescnt));
    PRTF(PrintToFile(OnE.sorted.val, OnE.linescnt));
    PRTF(PrintToFile(OnE.revsorted.val, OnE.linescnt));
    
    free(OnE.buff);
    free(OnE.prim.val);
    free(OnE.sorted.val);
    free(OnE.revsorted.val);

    printf(RCOLOR "finish\n" WCOLOR);
    return 0;
}

