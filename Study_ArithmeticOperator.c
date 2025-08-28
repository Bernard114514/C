#include <stdio.h>
#include <math.h>

int main()
{
    //运算符有优先级，如下所示
    int i, j, k;
    i = 1 + 2; //3
    j = 1 + 2 * 3; //7
    k = i + j + -1 +pow(2, 3); //3+7-1+8=17
    printf("i=%d, j=%d, k=%d\n", i, j, k);

    //自动转换数据类型：int->float
    int a = 1;
    float b = 2.9;
    float result;
    printf("result:%f\n", 1 + 2.0); //输出浮点数
    printf("result: %f\n", result = a + b);
    //强制转换数据类型：
    printf("result: %d\n", (int)result); //使用(int)将变量强制转换成整型数, 3.5->3
    printf("change: 2.9 -> %d\n", (int)2.9);
    printf("change: 2.8 -> %d\n", (int)2.8);
    printf("change: 2.7 -> %d\n", (int)2.7);
    printf("change: 2.6 -> %d\n", (int)2.6);
    printf("change: 2.5 -> %d\n", (int)2.5);
    printf("change: 2.4 -> %d\n", (int)2.4);
    printf("change: 2.3 -> %d\n", (int)2.3);
    printf("change: 2.2 -> %d\n", (int)2.2);
    printf("change: 2.1 -> %d\n", (int)2.1); //转换是直接舍去小数位，没有四舍五入 

    getchar();
    return 0;
}
