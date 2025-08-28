#include <stdio.h>
#include <math.h> //为了使用sqrt求平方根函数

//想法：寻找非素数，然后用总数减去非素数的个数以计算出素数的数量
//114514
int main() {

    long long int numIn, i, i1;
    int count = 0, flag = 0;
    printf("请输入一个正整数: ");
    scanf("%d", &numIn);

    for (i = 2; i <= numIn; i++) {
        for (i1 = 2; i1 <= (int)sqrt(i); i1++) {
            if (i % i1 == 0) {
                printf("<%d/%d>\n", i, i1); //调试用
                count++; //计入：已得到一个非素数
                flag = 0;
                break; //如果余数为0则说明能被整除，不是素数，则跳出这个循环
            }
            else {
                flag = 1; 
            }
        }

        if (flag) {
            printf("<! %d !>\n", i); //调试用
        }
    }

    
    printf("1 - %d以内共有%d个素数!", numIn, numIn - count - 1); //除去数字1不算素数
    return 0;
}