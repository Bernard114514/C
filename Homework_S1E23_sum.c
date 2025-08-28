#include <stdio.h>
#include <stdlib.h>

/*
需要从cmd输入指令启动
特别之处在于该main函数可以传入参数，从控制台输入指令时在后方继续输入参数
例如：
cmd:
        D:\C>Homework_S1E23_sum.exe 1 2 3 4 5
        Homework_S1E23_sum.exe
        1
        2
        3
        4
        5
        sum = 15
没搞懂原理
*/

int main(int argc, char *argv[])
{
        int i, sum = 0;
        for (i = 0; i < argc; i++)
        {
                sum += atoi(argv[i]);
                printf("%s\n", argv[i]);
        }
        printf("sum = %d\n", sum);

        return 0;
}