#include <stdio.h>
//第2题:
//要求用户输入一个字符，如果是大写字母，将其转换为小写；
//如果是小写字母，将其转换为大写；其他字符不做处理，并输出结果。

int main()
{
    printf("请输入一个英文字符, \n\
    如果是小写则将转换成大写\n\
    如果是大写则将转换成小写\n\
    现在请输入字符:\t");
    char c;
    scanf("%c", &c);

    if (c >= 65 && c <= 90)
    {
        printf("转换成小写: %c\n", c + 32);
        printf("ASCII CODE: %d\n", c);
        getchar();
    }
    
    else if (c >= 97 && c <= 122)
    {
        printf("转换成大写: %c\n", c - 32);
        printf("ASCII CODE: %d\n", c);
        getchar();
    }
    
    else
    {
        printf("您输入的不是英文字符\n");
        printf("ASCII CODE: %d\n", c);
        getchar();
    }

    
    getchar();
    return 0;
}