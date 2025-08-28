#include <stdio.h>
//变量与常量，重点是符号常量
//符号常量：可以理解为另一种全局变量？可以使用标识符调用，但是需要在程序开头声明
//符号常量使用前需要在程序开头声明，使用预处理命令#define
//以 # 开头的指令都叫预处理命令
//格式：#define 标识符 常量
#define PERSON "Bernard" //这是符号常量，习惯使用全部大写，便于区分
#define AGE 22
#define YEAR 2002
#define MONTH 4
#define DAY 2 
#define YEARTODAY 2024

int main()
{
    int Age = YEARTODAY - YEAR; //这是变量
    //Age = YEARTODAY - YEAR;
    printf("\t%s 同学出生于 %d 年 %d 月 %d 日，今年 %d 岁\n", PERSON, YEAR, MONTH, DAY, Age);

    //数据类型与sizeof运算符
    int line = 0;
    printf("\n0%0127d\n", line);
    
    int i;
    char j;
    float k;

    i = 123;
    j = 'c';
    k = 3.14;
    //下面可以看出不同数据类型在内存中所占的大小不同
    printf("size of int is %d Byte\n", sizeof(int)); //int类型所占的字节数
    printf("size of short int is %d Byte\n", sizeof(short));
    printf("size of long int is %d Byte\n", sizeof(long));
    printf("size of long long int is %d Byte\n", sizeof(long long));
    printf("size of i is %d Byte\n", sizeof(i)); //此变量所占的字节数
    printf("size of _Bool is %d Byte\n", sizeof(_Bool)); //布尔值（Ture or False）
    printf("size of char is %d Byte\n", sizeof(char));
    printf("size of j is %d Byte\n", sizeof(j));
    printf("size of float is %d Byte\n", sizeof(float));
    printf("size of double float is %d Byte\n", sizeof(double));
    printf("size of long double is %d Byte\n", sizeof(long double));
    printf("size of k is %d Byte\n", sizeof(k));

    getchar(); //让程序窗口停留，直到用户敲击任意键后关闭
    return 0;

}