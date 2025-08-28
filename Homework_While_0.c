#include <stdio.h>
//统计从键盘输入的一行英文句子中大写字母的个数
int main() {
    int words = 0;
    char test;
    
    printf("请输入一段英文:\x20"); //为什么使用转义字符打ASCII码需要用16进制？10进制的话实际打印字符与ASCII表上对应的字符相差12？

    while ((test = getchar()) != '\n') {
        //test = getchar(); //错误点：有多少个getchar(),其就被调用执行了多少次，这里只能每次循环调用一次
    
        if (test >= 65 && test <= 90) {
            words = words + 1;
        }
        else {
            ;
        }
    } 

    printf("你一共输入了%d个大写字符\n", words);

    return 0;
}