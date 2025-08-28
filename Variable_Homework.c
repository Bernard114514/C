#include <stdio.h>
int main()
{
    //第一题
    printf("\n\
    Question 0:\n");
    int a;
    int b; 
    b = 3;
    a = b; //将b变量值赋值给a
    b = b * 2;
    printf("b = %d\n", b); //打印变量b的参数
    printf("a = %d\n", a); //打印变量a的参数

    //第二题
    printf("\n\
    Question 1\n");
    int r; //半径
    float c; //周长
    float s; //面积
    r = 5;
    c = 2 * 3.14 * r; //周长
    s = 3.14 * r * r; //面积
    printf("半径为 %d 的圆，周长是 %5.2f，面积是 %5.2f", r, c, s);
    //return 0;

    //第三题
    //%[flags][width][.precision][length]specifier
    printf("\n\
    Question 2\n");
    printf("打印五个字符：%c %c %c %c %c\n", 70, 105, 115, 104, 67);
    printf("前面用 填充：%10d\n", 2015); //试出来的填充空格数
    printf("前面用 填充：%010d\n", 2015); //试出来的填充空格数
    printf("右对齐，保留两位：%9.2f\n", 3.1416);
    printf("左对齐，保留三位：%-9.3f\n", 3.1416);
    printf("右对齐，指数形式：%.4e\n", 520000.0);
    printf("左对齐，指数形式：%-.4E\n", 520000.0);
}

/*
//第三题答案
#include <stdio.h>

int main()
{
        printf("打印五个字符：%c %c %c %c %c\n", 70, 105, 115, 104, 67);
        printf("前边用 填充：%10d\n", 2015);
        printf("前边用0填充：%010d\n", 2015);
        printf("右对齐，保留2位：%10.2f\n", 3.1416);
        printf("左对齐，保留3位：%-10.3f\n", 3.1416);
        printf("右对齐，指数形式：%10e\n", 520000.0);
        printf("左对齐，指数形式：%-10E\n", 520000.0);

        return 0;
}

*/
