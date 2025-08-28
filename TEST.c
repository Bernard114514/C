#include <stdio.h>
#include <math.h>

// #define LENGTH(array) (sizeof(array) / sizeof(array[0])) //简易计算数组长度的宏定义
int main(int argc, char *argv[])
{
        int i;

        for (i = 0; i < argc; i++)
        {
                printf("%s\n", argv[i]);
        }

        return 0;
}