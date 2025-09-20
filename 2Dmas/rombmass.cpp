#include "needfor2d.h"
const size_t MYSIZE = 7;

int * input(int *);
const int * output(const int *);
int   min_el(const int *);

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
    size_t center = MYSIZE / 2;
    size_t L = center;
    size_t R = center + 1;
    
    for (size_t y = 0; y <= center; ++y) {
        for (size_t x = L; x < R; ++x) {
            *(int *)((size_t)data + (y * MYSIZE + x) * sizeof (int)) = getchar();
        }
        --L, ++R;   
    }
    L = 1, R = MYSIZE - 1;
    for (size_t y = center + 1; y < MYSIZE; ++y) {
        for (size_t x = L; x < R; ++x) {
            *(int *)((size_t)data + (y * MYSIZE + x) * sizeof (int)) = getchar();
        }
        ++L, --R;   
    }
    return (int *)data;
}

const int * output(const int * data)
{
    size_t center = MYSIZE / 2;
    size_t L = center;
    size_t R = center + 1;
    for (size_t y = 0; y <= center; ++y, putchar('\n')) {
        for (size_t i = 0; i < center - y; ++i, putchar('\t')) {}
        for (size_t x = L; x < R; ++x) {
            printf(GCOLOR "[%d|%d]" WCOLOR " %c ", y, x, *(data + y * MYSIZE + x));
        }
        --L, ++R;   
    }
    L = 1, R = MYSIZE - 1;
    for (size_t y = center + 1; y < MYSIZE; ++y, putchar('\n')) {
        for (size_t i = 0; i <= y - center - 1; ++i, putchar('\t')) {}
        for (size_t x = L; x < R; ++x) {
            printf(GCOLOR "[%d|%d]" WCOLOR " %c ", y, x, *(data + y * MYSIZE + x));
        }
        ++L, --R;   
    }
    return (const int *)data;
}

int min_el(const int * data)
{
    int imin = INT_MAX;
    size_t center = MYSIZE / 2;
    size_t L = center;
    size_t R = center + 1;
    
    for (size_t y = 0; y <= center; ++y) {
        for (size_t x = L; x < R; ++x) {
            if (*(data + y * MYSIZE + x) < imin) {
                imin = (int)*(data + y * MYSIZE + x);
            }
        }
        --L, ++R;   
    }
    L = 1, R = MYSIZE - 1;
    for (size_t y = center + 1; y < MYSIZE; ++y) {
        for (size_t x = L; x < R; ++x) {
            if (*(data + y * MYSIZE + x) < imin) {
                imin = (int)*(data + y * MYSIZE + x);
            }
        }
        ++L, --R;   
    }
    
    return imin - '0';
}


