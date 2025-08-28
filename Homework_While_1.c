#include <stdio.h>
//写一个程序，将用户输入的英文句子中的字母大小写进行调换（即大写字母转换为小写字母，小写字母转换为大写字母）。
int main() {
    printf("请输入一段英文:\x20");
    char words;

    while ((words=getchar()) != '\n') {

        if (words >= 65 && words <= 90) {
            words = words + 32;
            //putchar(words);
        }
        else if (words >= 97 && words <= 122) {
            words = words - 32;
            //putchar(words);
        }
        else {
            //putchar(words);
        }
        putchar(words);
    }
    printf("\n--执行结束--\n");
    return 0;
}