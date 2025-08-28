#include <stdio.h>

int main() {
    char typing[64];
    int words = 0, test = ' ';
    
    printf("请输入一段英文:\x20"); //为什么使用转义字符打ASCII码需要用16进制？10进制的话实际打印字符与ASCII表上对应的字符相差12？

    while (getchar() != '\n') {
        words = words + 1;
    }
    printf("你一共输入了%d个字符\n", words);
    printf("测试ASCII码: %d", test);
    return 0;
}

/*
 && getchar() != '\0'
*/