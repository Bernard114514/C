#include <stdio.h>
#include <math.h> //使用math
//字符与字符串

int main()
{
    char test = 'C';//字符类本身是一种特殊的int类
    printf("%c == %d\n", test, test); //基于ASCII码存放字符，因此可以通过这种方式打印出字符对应的编码数字
    //也可以反着来：
    /*
    char a = 70, b = 105, c = 115, d = 104, e = 67;
    printf("%c %c %c %c %c\n", a, b, c, d, e);   
    */

    //声明字符串：
    char Name[8] = {'B', 'e', 'r', 'n', 'a', 'r', 'd', '\0'};//末尾加入空字符\0表示该字符串到此为止 
    printf("My name is %s\n", Name);

    //简单起见，完全可以这样：
    char Name1[] = {"Bernard"}; //直接使用字符串常量，也可以省去大括号{}
    printf("My name is %s\n", Name1);
    printf("The third character in my name is: %c", Name1[2]); //这样提取字符串中特定位置的字符
    return 0;

}