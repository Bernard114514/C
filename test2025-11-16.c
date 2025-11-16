#include <stdio.h>

void swap(int * x, int * y);

void swap(int * x, int * y) 
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main() 
{
    int x = 10, y = 20;
    printf("Before exchange: x=%d, y=%d\n", x, y);
    swap(&x, &y);
    printf("After exchange, x=%d, y=%d\n", x, y);
    return 0;
}