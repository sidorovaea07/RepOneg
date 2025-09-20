#include "needfor2d.h"
const size_t SIZE_X = 3;
const size_t SIZE_Y = 3;

int * input(int *);
const int * output(const int *);
int min_el(const int *);

int main()
{
    int data[SIZE_Y][SIZE_X] = {{}};
    printf("%p\n", input((int *)data));
    printf("%p\n", output((const int *)data));
    printf("minimum = %d\n", min_el((const int *) data));
}

int * input(int *data)
{
    printf("Enter\n");
    for (size_t y = 0; y < SIZE_Y; y++) {
        for (size_t x = 0; x < SIZE_X; x++) {
            *(int *)((size_t)data + (y * SIZE_X + x) * sizeof (int)) = getchar();
        }    
    }
    return (int *)data;
}

const int * output(const int * data)
{
    for (size_t y = 0; y < SIZE_Y; y++, putchar('\n')) {
        for (size_t x = 0; x < SIZE_X; x++) {
            printf(GCOLOR "[%d|%d]" WCOLOR " %c ", y, x, *(data + y * SIZE_X + x));
        }    
    }
    return (const int *)data;
}

int min_el(const int * data)
{
    int imin = INT_MAX;
    for (size_t y = 0; y < SIZE_Y; y++) {
        for (size_t x = 0; x < SIZE_X; x++) {
            if (*(data + y * SIZE_X + x) < imin) {
                imin = (int)*(data + y * SIZE_X + x);
            }
        }    
    }
    return imin - '0';
}


