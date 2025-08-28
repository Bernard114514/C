#include <stdio.h>
#include <math.h> //使用math库？

int main()
{
    signed char i; 
    printf("size of i is %d Byte\n", sizeof(i));
    unsigned char j;

    i = 255;
    j = 255;

    char a = 10;
    char b = 10;
    char c = a + b;
    printf("test, the value c is %d, however c is a char\n", c); //为啥这也能行？？

    printf("signed char %hhd\n", i); 
    printf("unsigned char %hhu\n", j);
    
    printf("中文测试\n"); //在编译器内显示正常，但是在外部环境中依然有乱码
    getchar(); //让程序窗口停留，直到用户敲击任意键后关闭
    return 0;
}
/*
解释：
char 类型占一个字节的空间，因此 unsigned char 的取值范围是 0~255，
signed char 的取值范围则是 -128~127。
十进制的 255 即二进制的 11111111，
signed char 第一位为符号位，因此其值转换为十进制后是 -1

我的问题：声明变量在C中到底有什么含义？为什么字符串类型的变量还能以int方式存储整数？

*/
