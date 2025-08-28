#include <stdio.h>
#include <math.h>

// #define LENGTH(array) (sizeof(array) / sizeof(array[0])) //简易计算数组长度的宏定义
int main()
{
        int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        int (*p)[10] = &array;
        printf("adress = %d\n", &array);
        printf("adress = %d\n", p);
        printf("'4' adress = %d\n", &array[4]);

        printf("%d\n", *(*(p+1)-6));
        printf("等价于: %d\n", *(*(&array+1)-6));

        return 0;
}