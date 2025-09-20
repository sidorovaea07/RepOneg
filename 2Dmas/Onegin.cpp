#include "FileWork.h"
#include "BubbleSorts.h"
#include "PtrsWork.h"

// struct OneginData 
// 
// добавить stat, qsort, сравнение Б и м, непосимвольный вывод
// исправить сортировку пустых строк
// isalpha tolower

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
    struct Data {
        const char * input;
        char **ptrs;
        int linescnt;
        char *buff;
        int size;
    };

    struct Data Onegin;
    Onegin.input = "inputfile.txt";
    Onegin.size = 0;
    Onegin.buff = OpenAndReadFile(Onegin.input, &Onegin.size);
    Onegin.linescnt = LinesCnt(Onegin.buff);
    Onegin.ptrs = CreatePtrArr(Onegin.linescnt, Onegin.buff);
    
    puts(Onegin.buff);
    PRD(Onegin.linescnt);
    PRTF(PrintToFile(Onegin.ptrs, Onegin.linescnt));
    PRS(BubbleSort(Onegin.ptrs, Onegin.linescnt));
    PRTF(PrintToFile(Onegin.ptrs, Onegin.linescnt));
    PRS(RevBubbleSort(Onegin.ptrs, Onegin.linescnt));
    PRTF(PrintToFile(Onegin.ptrs, Onegin.linescnt));

    free(Onegin.buff);
    free(Onegin.ptrs);
    printf(RCOLOR "finish\n" WCOLOR);
    return 0;
    
}

