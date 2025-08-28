#include <stdio.h>
#include <math.h>

// #define LENGTH(array) (sizeof(array) / sizeof(array[0])) //简易计算数组长度的宏定义
int main()
{
        int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        int *p = (int *)(&array + 1); // 这可以理解为在地址层面上，向前进一个数组长度的地址(步长为该数组的长度,40字节)，也就是10乘以4(int类占4字节)
        int *pa = &array[0];
        printf("adress = %d\n", &array); //adress = 6421984
        printf("adress = %d\n", p); //adress = 6422024; 看出比前一个地址值多了40
        printf("adress = %d\n", p - 6); //adress = 6422000; 看出比p的地址少了24=6*4
        printf("adress = %d\n", (array + 1)); //一般操作时这样会让地址在数组内向前进一个单位，单位长度由数组类型决定
        printf("%d\n", *(p - 6));

        return 0;
}