#include <stdio.h>
#include <math.h> //使用math库？
//二进制转换与取值范围
int main()

{
    unsigned int result = pow(2, 32) - 1; //调用了pow()函数，计算2的32次方
    printf("result = %u\n", result); //unsigned 要用%u打印
    //如果用默认signed int，gcc编译器提示overflow警告，表示数值溢出。给warning程序还能运行，error报错就会停止
    //默认signed时，第一位(bit)会用来存放正负号（0 or 1），可能会导致数值溢出，这里手动修改为unsigned

    getchar(); //让程序窗口停留，直到用户敲击任意键后关闭
    return 0;
}