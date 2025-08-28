#include <stdio.h>
//课后作业
#define NL '\n' //转义字符算一个字符，所以是单引号
#define S(r) 3.14 * r * r //定义一个宏？
#define C(r) 2 * 3.14 * r


int main()
{
    printf("------------\n");
    //0. 修改下边代码，使用符号常量 NL，代替转义字符 '\n'：    
    printf("Line1%c", NL);
    printf("Line2%c", NL);

    //1. 定义两个宏，分别叫 S(r) 和 C(r)，通过它可以计算得到半径为 r 的圆的面积和周长。
    printf("------------\n");
    int r = 5;
    printf("半径为%d的圆，面积是%0.2f，周长是%0.2f。", r, S(r), C(r));
    return 0;
}