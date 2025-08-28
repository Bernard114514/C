#include <stdio.h>

int main()
{
    char a = 'F';
    int f = 12345;

    //定义并初始化指针指针：在此*为定义指针的符号，&为取址运算符
    char *pa = &a;
    int *pb = &f;
    // char *pb = &f; //这里展现了一个错误，使用char类的指针访问int类数据

    printf("a = %c\n", *pa);
    printf("f = %d\n", *pb);
    printf("DEBUG: %d\n", 12345 % 256); //这解释了之前的错误：用char类指针去间接访问int类值，其只能返回char类大小的一部分错误数据，char类大小为256，使用取模运算可以计算出错误数据的值

    //也可以通过指针修改变量值
    *pa = 'C';
    *pb += 1;
    printf("a = %c\n", *pa);
    printf("f = %d\n", *pb);

    //可以用操作符sizeof()查看指针大小，不同系统的指针大小可能不一样
    //注意：不要使用*号，否则取得的是指针指向的地址中存放变量的大小
    printf("The size of pointer pa: %d\n", sizeof(pa));
    printf("The size of pointer pb: %d\n", sizeof(pb));


    return 0;
}