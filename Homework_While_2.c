#include <stdio.h>
#include <stdlib.h> //用于测试atoi()功能
#include <string.h>
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

留到6月25日完成
已完成
*/

int main() {

    int num = 0, numOut = 0 ,transNum = 0;
    char word, typing[64], test[64];

    printf("请输入待转换的字符串:\x20");
    while ((word=getchar()) != '\n') {
        if (word >= 48 && word <= 57) {
            //使用ASCII码识别是否是数字，并将其按顺序存储至一个字符串内
            typing[num] = word;
            num = num + 1; 
        }
        
        else if ((typing[num-1] >= 48 && typing[num-1] <= 57) && (word <= 48 || word >= 57)) {
            printf("EDN\n");
            break; //识别出第一组数字后，主动跳出while循环
        }

        //numOut = numOut + 1;
        //test[numOut] = word;
    }
    
    numOut = strlen(typing); //读取数字的位数
    
    if (0 == num) {
        printf("未找到任何数字\n"); //若未识别出任何数字则显示这条
    }
    
    else if (numOut <= 10) {
        //第一次判断范围，先从输入位数判断（假设前几位不为0）

        while (numOut > 0) {
            printf("translating...\n");
            numOut = numOut - 1;
            switch (typing[strlen(typing) - (numOut+1)]) {
                //只考虑正整数情况
                case '0': transNum = transNum + 0 * pow(10, numOut); break;
                case '1': transNum = transNum + 1 * pow(10, numOut); break;
                case '2': transNum = transNum + 2 * pow(10, numOut); break;
                case '3': transNum = transNum + 3 * pow(10, numOut); break;
                case '4': transNum = transNum + 4 * pow(10, numOut); break;
                case '5': transNum = transNum + 5 * pow(10, numOut); break;
                case '6': transNum = transNum + 6 * pow(10, numOut); break;
                case '7': transNum = transNum + 7 * pow(10, numOut); break;
                case '8': transNum = transNum + 8 * pow(10, numOut); break;
                case '9': transNum = transNum + 9 * pow(10, numOut); break;
                default: printf("ERROR\n"); break;
                }
        } 
        
        if (transNum < 0) {
            printf("警告：转换数值超出范围（+2^31-1）\n");
        }
        else {
            printf("转换结果为: %d", transNum);
        }
    }

    else if (transNum < 0) {
        //第二次判断范围，从转换后数字正负性判断
            printf("警告：转换数值超出范围（+2^31-1）\n");
    }
    
    else {
        printf("警告：转换数值超出范围（+2^31-1）\n");
    }
    //printf("测试: %d\n", atoi("001"));
    return 0;
}

//问题：不使用ASCII码识别，可以用别的编码识别和读写吗？例如UTF-8？
//测试结果是不行，需要调用别的库