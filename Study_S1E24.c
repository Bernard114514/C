#include <stdio.h>

void sample_1();

int main()
{
    int array2D[4][5] = {0};
    int i, j, k = 0;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            array2D[i][j] = k++;
        }
    }

    printf("*(array2D + 1) = %p\n", *(array2D + 1));
    /*
    不同于一维数组, 二维数组中进行 array2D + 1 操作实际上是前进一个行的长度, 
    跳到下一行, 而非前进到数组的第1位元素;
    同样, *(array2D + 1) 取出的实际上是数组中下一行元素的第0个元素的地址! 
    **()这样才能取出数组中元素的具体值
    */
    printf("array2D[1] = %p\n", array2D[1]);
    printf("&array2D[1][0] = %p\n", &array2D[1][0]);
    printf("**(array2D + 1) = %d\n", **(array2D + 1));

    sample_1();
    return 0;
}

void sample_1()
{
    /*
    二维数组 和 数组指针 之间的关系
    */
    printf("============\n");

    int array[2][3] = {
        {0, 1, 2},
        {3, 4, 5}
    };

    int (*p)[3] = array;

    printf("**(p + 1) = %d\n", **(p + 1));
    printf("**(array + 1) = %d\n", **(array + 1));
    printf("array[1][0] = %d\n", array[1][0]);
}