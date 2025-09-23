#include "FileWork.h"
#include "BubbleSorts.h"
#include "PtrsWork.h"
#include <assert.h>
#define H 1000
// rm -rf outputfile.txt
// добавить stat, qsort

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

int main()
{
    struct Data OnE;                                    //Onegin Evgene
    OnE.input = "onegfromkr.txt";
    OnE.size = 0;
    OnE.buff = OpenAndReadFile(OnE.input, &OnE.size);
    PRD(OnE.linescnt = LinesCnt(OnE.buff));
    //puts(OnE.buff);
    OnE.prim = CreatePtrArr(OnE.linescnt, OnE.buff);
    OnE.sorted = CreatePtrArr(OnE.linescnt, OnE.buff);
    OnE.revsorted = CreatePtrArr(OnE.linescnt, OnE.buff);
    
    MySort(OnE.sorted, OnE.linescnt);
    MyRevSort(OnE.revsorted, OnE.linescnt);

    PRTF(PrintToFile(OnE.prim, OnE.linescnt));
    PRTF(PrintToFile(OnE.sorted, OnE.linescnt));
    PRTF(PrintToFile(OnE.revsorted, OnE.linescnt));
    
    free(OnE.buff);
    free(OnE.prim);
    free(OnE.sorted);
    free(OnE.revsorted);

    printf(RCOLOR "finish\n" WCOLOR);
    return 0;
}

