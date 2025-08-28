#include <stdio.h>
#include <math.h>
//凯撒加密程序，基于ASCII编码的英文字符

/*
细节要求：
基本：用户输入一行明文（字符串），针对字母进行加密（偏移量设置为 3），非字母部分保留原型。例：A->D, Z->C, a->d, z->c
进阶：用户可以手动设置偏移量(0-9)
*/

int main() {

    _Bool flag = 1, flag1 = 0, flag2;
    unsigned char word = 0, offset, i;

    do {
        offset = '3';

        flag2 = 1;
        flag1 = 1; //循环前重置标志变量
        flag = 0;
        printf("\n请输入偏移量(单个数字)+明文(ASCII): ");
        
        do {
            word = getchar();

            //识别开头第一个数字，作为偏移量
            if (flag2) {
                for (i = '0'; i <= '9'; i++) {
                    if ((word-i) == 0) {
                        offset = i;
                        flag2 = 0; //标志变量=0，下次循环中不进行此操作
                        break;
                    }
                }
                if (flag2 == 0) {
                    printf("设置偏移量: %d\n", offset - '0');
                    continue; //跳过后续程序，避免首数字被错误识别
                }
                if (flag2 == 1) {
                    //未输入数字时，默认为使用偏移量3，不跳过后续程序
                    printf("默认偏移量: 3\n");
                    flag2 = 0;
                }
            }
            

           if (word == '\n') {
                //判断是否输入回车，如果输入则判定结束识别循环
                flag1 = 0; //向while传递结束循环值
                flag = 1; //向外层while传递开始循环值
                }
            else if (word < 'A' || (word > 'Z' & word < 'a') || word > 'z') {
                //判断是否是除了26字母外的字符
                putchar(word);
            }

            for (i = 'A'; i <= 'Z'; i++) {
                if ((word-i) == 0) {
                    //是大写字母的情况
                    word = word + (offset - '0');
                    if (word >= 'A' & word <= 'Z') {
                        //如果修改后字符仍然在大写字母中则不做修改输出
                        putchar(word);
                        break;
                    }
                    else if (word > 'Z') {
                        //如果修改后字符超出大写个字母范围，则修正
                        putchar('A' + (word - 'Z' - 1));
                        break;
                    }
                    break;
                }
                else if ((word-i) == 32) {
                    //是小写字母情况
                    word = word + (offset - '0');
                    if (word >= 'a' & word <= 'z') {
                        //如果修改后字符仍然在小写字母中则不做修改输出
                        putchar(word);
                        break;
                    }
                    else if (word > 'z') {
                        //如果修改后字符超出小写个字母范围，则修正
                        putchar('a' + (word - 'z' - 1));
                        break;
                    }
                    break;
                }
            }
            
            
              
        } while (flag1); //内层循环:识别字符
    } while (flag); //外层循环:反复执行程序

    getchar();
    return 0;
}

