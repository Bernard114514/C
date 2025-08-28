#include <stdio.h>

//验证尼科彻斯定理

int main()
{
    int X, oddNum, check;
    char plus = '+', space = ' ';

    printf("请输入一个整数:");
    scanf("%d", &X);

    int count[X];

    oddNum = X * (X - 1) + 1;
    printf("%d^3 = %d = ", X, X*X*X);

    for (int i = 0; i < X; i++)
    {
        count[i] = oddNum;
        printf("%d", oddNum);
        if (X - i != 1)
        {
            putchar(space);
            putchar(plus);
            putchar(space);
        }
        oddNum += 2;
    }

    for (int i = 0; i < X; i++)
    {
        check += count[i];
    }

    if (check == X*X*X)
    {
        printf("\n验证成功，符合尼科彻斯定理\n");
    }
    else
    {
        printf("验证失败\n");
    }

    return 0;
}