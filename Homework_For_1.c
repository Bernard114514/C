#include <stdio.h>
#include <stdlib.h>
//写一个程序，对用户输入的整数进行求和。当用户输入任意字符时，结束程序并打印结果

int main() {
    int flag, flag_0 = 0, num = 0;
    float i, j = 0;
    //char test0[64];
    printf("请输入合法的数字: ");
    flag = scanf("%f", &i); //scanf返回值等于成功识别变量的个数
    putchar('\n');
    //如果成功，该函数返回成功匹配和赋值的个数。如果到达文件末尾或发生读错误，则返回 EOF
    //可以基于此判断输入内容是否为数字
    printf("FLAG: %d\n", flag);
    while (num == 0) {

        while (flag != 0 && getchar() != '\n') {
            j = j + i;
            num = 0;
            putchar('\n');
            flag = scanf("%f", &i);
            printf("FLAG: %d\n", flag);
            flag_0++;
        }

        if (flag <= 0) {
            //putchar('\n');
            num = 1;
        }     

        printf("请输入合法的数字: ");  
    }
    printf("结果是: %.2f\n", j);
    printf("%d",flag_0);
    return 0;
}