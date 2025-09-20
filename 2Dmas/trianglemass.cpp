#include "needfor2d.h"
const size_t MYSIZE = 4;

int * input(int *);
const int * output(const int *);
int min_el(const int *);

int main()
{
    int data[MYSIZE][MYSIZE] = {{0}};
    printf("%p\n", input((int *) data));
    printf("%p\n", output((const int *) data));
    printf("minimum = %d\n", min_el((const int *) data));

}

int * input(int *data)
{
    printf("Enter\n");
    for (size_t y = 0; y < MYSIZE; y++) {
        for (size_t x = 0; x < y + 1; x++) {
            *(int *)((size_t)data + (y * MYSIZE + x) * sizeof (int)) = getchar();
        }    
    }
    return (int *)data;
}

const int * output(const int * data)
{
    for (size_t y = 0; y < MYSIZE; y++, putchar('\n')) {
        for (size_t x = 0; x < y + 1; x++) {
            printf(GCOLOR "[%d|%d]" WCOLOR " %c ", y, x, *(data + y * MYSIZE + x));
        }    
    }
    return data;
}

int min_el(const int * data)
{
    int imin = 1e9;
    for (size_t y = 0; y < MYSIZE; y++) {
        for (size_t x = 0; x < y + 1; x++) {
            if (*(data + y * MYSIZE + x) < imin) {
                imin = (int)*(data + y * MYSIZE + x);
            }
        }
    }
    return imin - '0';
}


