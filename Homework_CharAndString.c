#include <stdio.h>
#include <math.h> //使用math

int main()
{
    //问题0：写一个华氏度到摄氏度的转换程序，用户输入华氏度，程序计算并输出对应的摄氏度。
    float temp; //虽然声明是浮点数，但是输入整形也是可以的，反之则不行
    printf("请输入华氏度:\t");
    scanf("%f", &temp);
    printf("转换为摄氏度为:\t %.2f\n", temp = (temp-32)*5/9);


    //问题1：身高体重单位转换工具
    char Name[256];
    float Height, Weight;
    printf("请输入您的姓名: \t");
    scanf("%s", &Name);
    printf("请输入您的身高整数(cm): \t");
    scanf("%f", &Height);
    printf("请输入您的体重整数(kg): \t");
    scanf("%f", &Weight);
    printf("======正在为您转换======\n%s 的身高是 %.2f (in), 体重是 %.2f (lb)。\n", \
    Name, Height = Height/2.54, Weight = Weight/0.45359237);
    
    getchar();
    return 0;
}