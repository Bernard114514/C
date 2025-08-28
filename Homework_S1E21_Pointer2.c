#include <stdio.h>

//验证尼科彻斯定理
//改进上一题的代码，用户输入一个表示范围的最大值 count，程序将测试 3 ~ count 所有的整数是否都符合尼科彻斯定理。
//附加要求：有些用户可能不希望看到打印一丢丢式子，所以是否打印应该让用户确定（提示 -> 用二维数组先保存结果）

int main()
{
    int X, oddNum;
    char plus = '+', space = ' ', enter = '\n';
    printf("请输入一个整数:");
    scanf("%d", &X);

    for (int i = 3; i < X; i++)
    {
        oddNum = i * (i - 1) + 1;
        printf("%d = ", i);
        for (int j = 0; j < i; j++)
        {
            printf("%d", oddNum);
            if (i - j != 1)
            {
                putchar(space);
                putchar(plus);
                putchar(space);
            }
            else
            {
                putchar(enter);
            }
            oddNum += 2;
        }
    }

    return 0;
}