#include <stdio.h>
//for 循环语句

//一个判断输入数字是否是素数的程序：
int main() {
    long long int i, num;
    _Bool flag = 1; //标志布尔值，并初始化为1

    printf("请输入一个整数:\t");
    scanf("%lld", &num);

    for (i = 2; i < (num/2); i++) { //对其循环求余数
        if (num % i == 0) {
            flag = 0; //如果余数是0，则其能被整除，不是素数
            break; 
        }
        else {
            ;
        }
    }

    if (flag) {
        printf("%lld 是一个素数\n", num);
    }
    else {
         printf("%lld 不是一个素数\n", num);
    }
    
    printf("循环次数统计: %lld", i - 2);
    
    return 0;
}
