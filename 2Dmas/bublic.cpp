#include "needfor2d.h"

const size_t MYSIZE = 11;
double center = MYSIZE / 2.0;
double xO = center;
double yO = center;

int CompareDoubles (double a, double b);
int * input(int *);
const int * output(const int *);
int   min_el(const int *);
//123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789
int main()
{
    int data[MYSIZE][MYSIZE] = {{0}};
    printf("%p\n", input((int *) data));
    printf("%p\n", output((const int *) data));
    printf("minimum = %d\n", min_el((const int *) data));
}

int CompareDoubles (double a, double b) {
    if (isnan(a) && isnan(b))
        return 0;
    else 
    {
        if (fabs(a - b) < DBL_MIN)
            return 0;
        else
            return (a-b > DBL_MIN) ? 1 : -1;
    }
}

int * input(int *data)
{
    printf("Enter\n");
    
    for (size_t y = 0; y < MYSIZE; ++y) {
        for (size_t x = 0; x < MYSIZE; ++x) {
            if (CompareDoubles(pow(x - xO, 2) + pow(y - yO, 2), pow(center, 2)) != 1 && CompareDoubles(pow(x - xO, 2) + pow(y - yO, 2), pow(center/2, 2)) != -1) {
                *(int *)((size_t)data + (y * MYSIZE + x) * sizeof (int)) = getchar();
            }
        }
    }
    return (int *)data;
}

const int * output(const int * data)
{
    for (size_t y = 0; y < MYSIZE; ++y, putchar('\n')) {
        for (size_t x = 0; x < MYSIZE; ++x) {
            if (CompareDoubles(pow(x - xO, 2) + pow(y - yO, 2), pow(center, 2)) != 1 && CompareDoubles(pow(x - xO, 2) + pow(y - yO, 2), pow(center/2, 2)) != -1) {
                if (x < 10)
                    putchar(' ');
                if (y < 10)
                    putchar(' ');
                printf(GCOLOR "[%d|%d]" WCOLOR FCOLOR" %c " WCOLOR, y, x, *(data + y * MYSIZE + x));
            }
            else {
                putchar('\t');
                if (x > 9)
                    putchar(' ');
                if (y > 9)
                    putchar(' ');
            }
        }
    }
    return (const int *)data;
}

int min_el(const int * data)
{
    int imin = INT_MAX;

    for (size_t y = 0; y < MYSIZE; ++y) {
        for (size_t x = 0; x < MYSIZE; ++x) {
            if (CompareDoubles(pow(x - xO, 2) + pow(y - yO, 2), pow(center, 2)) != 1 && CompareDoubles(pow(x - xO, 2) + pow(y - yO, 2), pow(center/2, 2)) != -1) {
                if (*(data + y * MYSIZE + x) < imin) {
                    imin = (int)*(data + y * MYSIZE + x);
                }
            }
        }
    }
    return imin - '0';
}


