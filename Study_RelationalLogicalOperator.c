#include <stdio.h>
//关系运算符和逻辑运算符
int main()
{
    int a = 5, b = 3; 
    printf("%d\n", 1 < 2); //关系运算，返回0假或1真
    printf("%d\n", a > b);
    printf("%d\n", a <= b + 1);
    printf("%d\n", 'a' + 'b' <= 'c');
    printf("%d\n", (a=3) > (b=5));
    printf("====================================\n");

    //逻辑运算符与逻辑表达式
    printf("%d\n", 3 > 1 && 1 < 2);
    printf("%d\n", 3 + 1 || 2 == 0);
    printf("%d\n", !(a+b));
    printf("%d\n", !0 + 1 < 1 || !(3+4));
    printf("%d\n", 'a' - 'b' && 'c');

    //短路求值示例：
    int c = 1, d = 3, e;
    printf("original value: c is %d, d is %d\n", c, d);
    e = (c=0) > d && (d = 4);
    printf("c is %d, d is %d, logicla = %d\n", c, d, e);
    e = (c=100) > d || (d = 4);
    printf("c is %d, d is %d, logicla = %d\n", c, d, e);
    printf("====================================\n");

    printf("%d\n", 100%3); 
    printf("====================================\n");
    
    
    char i = 'a', j = 'b', k;
    k = i + j;
    printf("it is: %d\n", k);
    getchar();
    return 0;

    //典中典：以下表达式的作用
    float count, sum;
    count != 0 && sum/count; //该表达式使用逻辑与（&&）来确保 sum/count 的除数不为 0
    //因为当 count 为 0 时，并不会导致 sum/0，因为根据短路求值的原则，&& 运算符在左侧为假的情况下，并不会计算右侧的表达式
}