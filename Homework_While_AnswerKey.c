#include <stdio.h>
#include <math.h>
/*
C 语言中有个 atoi 函数（定义于 <stdlib.h> 头文件中），用于将字符串中的值解析为对应的整型数字。现在要求我们自己写一个程序，实现类似的功能。
基本要求：
A. 将用户输入的字符串中代表数字的字符转换为整型数值
B. 打印转换结果
C. 只打印第一组数字
进阶要求：
A. 如果字符串中不存在任何表示数值的字符，则打印“并未找到任何数值
B. 检测数值是否超出整型变量（int）可存放的范围，如果超出范围，则打印“数值超出范围，结果未定义！”的提醒
C. 为了达到锻炼的效果，整型变量的范围需要自己计算，不使用 <limits.h> 头文件

此为标准答案
*/


int main()

{

        int ch;

        long long num = 0;

        long long temp; // 临时变量，用于测试是否超出范围

        int is_overflow = 0;



        const int max_int = pow(2, sizeof(int) * 8) / 2 - 1;

        const int min_int = pow(2, sizeof(int) * 8) / 2 * (-1);



        printf("请输入待转换的字符串：");



        do

        {

                ch = getchar();



                if (ch >= '0' && ch <= '9')

                {

                        temp = 10 * num + (ch - '0');

                        if (temp > max_int || temp < min_int)

                        {

                                is_overflow = 1;

                                break;

                        }

                        else

                        {

                                num = temp;

                        }

                }

                else

                {

                        if (num)

                        {

                                break; // 如果已有数字，则退出循环

                        }

                }



        }

        while (ch != '\n');



        if (is_overflow)

        {

                printf("数值超出范围，结果未定义！\n");

        }

        else

        {

                if (!num)

                {

                        printf("并未找到任何数值！\n");

                }

                else

                {

                        printf("结果是：%d\n", num);

                }

        }



        return 0;

}