#include <stdio.h>
#include <math.h>
//0题：写一个最简单的计算器，支持四则运算
#include <stdbool.h>



int main()

{
    float op1, op2;
    char ch;
    float result;
    bool invalid = false;

    printf("请输入式子：");
    scanf("%f %c %f", &op1, &ch, &op2); //scanf 函数要注意的是双引号里边的内容是指定接收的格式化占位符，如果在里边写上空格，那么表示该位置将读取并忽略连续的空白字符（空格、回车和制表符）
//哦牛批，scanf还能这么用，这就简单了
    switch (ch) {

        case '-': op2 = -op2; // no break

        case '+': result = op1 + op2; break;

        case '*': result = op1 * op2; break;

        case '/': 

            if (op2 != 0)

                {
                    result = op1 / op2;
                    break;
                }

            else {
                    invalid = true;
                    break;
                }

    }



    if (invalid) {

        printf("除数不能为零！\n");

    }

    else {

        printf("结果是：%.2f\n", result);
    }
    
    return 0;

}

/*
//废案
        if (input[count] != ' ') {
            c = input[count];
            printf("Load variable c: %d\n", c);
        }
        else {
            printf("Error\n");
*/