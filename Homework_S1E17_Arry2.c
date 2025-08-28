#include <stdio.h>
#include <math.h>

// 1. 写一个生命计算器，要求用户输入生日，显示他在这个世界上活了多少天？(挑战:代码越少越好，用上数组)
// 2. 改进上一题的程序，增加显示预期寿命80年时的剩余天数，以及已经使用天数的占比(小数点后两位)

int main()
{
    int diffYMD[3] = {0}, YMD[3] = {0}, months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //日期数组格式YYYY/MM/DD
    char birthday[11], today[11];
    float life80;
    printf("请输入你的生日(如 2002-04-02):");
    scanf("%s", &birthday);
    printf("请输入今年日期(如 2024-08-28):");
    scanf("%s", &today);
    diffYMD[0] = (today[0]-birthday[0])*1000 + (today[1]-birthday[1])*100 + (today[2]-birthday[2])*10 + (today[3]-birthday[3]); //计算二者差了多少年
    diffYMD[1] = (today[5]-birthday[5])*10 + (today[6]-birthday[6]); //计算二者相差多少月
    diffYMD[2] = (today[8]-birthday[8])*10 + (today[9]-birthday[9]); //计算二者相差多少天
    YMD[0] = (birthday[0]-48)*1000 + (birthday[1]-48)*100 + (birthday[2]-48)*10 + (birthday[3]-48); //用于计算是否是闰年
    YMD[1] = (birthday[5]-48)*10 + (birthday[6]-48); //计算开始月份
    for(int i = 1, j = 0; i < 80*12 + 1; i++)
    {
        j = i / 12;
        if(((YMD[0]+j) % 4 == 0) && ((YMD[0]+j) % 100 != 0) | ((YMD[0]+j) % 400 == 0))
        {
            months[1] = 29; 
        }
        life80 += months[(i+YMD[1])%12]; //计算80年对应的天数
        if(i == diffYMD[0]*12 + diffYMD[1])
        {
            YMD[2] = (int)life80; //保存生日至输入日期的天数
            printf("\n你在这个世界上总共生存了%d天\n", YMD[2] + diffYMD[2]);
        }
        months[1] = 28;
    }
    printf("如果能活到80岁，你还剩下%d天\n", (int)life80 - (YMD[2] + diffYMD[2]));
    printf("你已经使用了%.2f\%的生命，请好好珍惜剩下的时间！", ((YMD[2] + diffYMD[2]) / life80) * 100);
    return 0;
}