#include <stdio.h>
//请写一个程序，帮小甲鱼计算 20 公斤内的运费。（顺丰起步价 23 元，每超一公斤加 14 元）

int main() {
    int i;
    printf("公斤 -- 花费(元)\n");
    for (i = 1; i <= 20; i++) {
        printf("%3d  --%5d\n", i, 23 + (i-1)*14);
    }
    return 0;
}