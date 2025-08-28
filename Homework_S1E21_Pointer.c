#include <stdio.h>

//0: 补全代码: 实现比较三个数之间大小的功能

int main()
{
        int a, b, c, t;
        int *pa, *pb, *pc;

        printf("请输入三个数:");
        scanf("%d %d %d", &a, &b, &c);

        pa = &a;
        pb = &b;
        pc = &c;

        if (a > b) 
        {
                // printf("DEBUG: 执行1\n");
                t = *pa; //将a位置的值 覆盖至 t位置
                a = *pb; //将b位置的值 覆盖至 a位置
                *pa = t; //将t位置的值(原a值) 覆盖至 a位置
        }

        if (a > c) 
        {
                // printf("DEBUG: 执行2\n");
                t = *pa;
                a = *pc;
                *pc = t;
        }

        if (b > c) 
        {
                // printf("DEBUG: 执行3\n");
                t = *pb;
                b = *pc;
                *pc = t;
        }

        printf("%d <= %d <= %d", *pa, *pb, *pc);
        return 0;
}