#include <stdio.h>
//用for循环和嵌套循环写一个99乘法表

int main() {
    int i, j;
    for (i = 1; i <= 9; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d * %d = %-2d ", i, j, i * j);
        }

        putchar('\n');
    }
}