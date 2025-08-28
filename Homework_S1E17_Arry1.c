#include <stdio.h>
#include <math.h>

// 1. 写一个生命计算器，要求用户输入生日，显示他在这个世界上活了多少天？(挑战:代码越少越好，用上数组)

int main()
{
    int diffYMD[3] = {0}, YMD[3] = {0}, months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //日期数组格式YYYY/MM/DD
    char birthday[11], today[11];
    printf("请输入你的生日(如 1988-05-20):");
    scanf("%s", &birthday);
    printf("\n请输入今年日期(如 2016-03-28):");
    scanf("%s", &today);
    diffYMD[0] = (today[0]-birthday[0])*1000 + (today[1]-birthday[1])*100 + (today[2]-birthday[2])*10 + (today[3]-birthday[3]); //计算二者差了多少年
    diffYMD[1] = (today[5]-birthday[5])*10 + (today[6]-birthday[6]); //计算二者相差多少月
    diffYMD[2] = (today[8]-birthday[8])*10 + (today[9]-birthday[9]); //计算二者相差多少天
    YMD[0] = (birthday[0]-48)*1000 + (birthday[1]-48)*100 + (birthday[2]-48)*10 + (birthday[3]-48); //用于计算是否是闰年
    YMD[1] = (birthday[5]-48)*10 + (birthday[6]-48); //计算开始月份
    for(int i = 1, j = 0; i < diffYMD[0]*12 + diffYMD[1] + 1; i++)
    {
        j = i / 12;
        if(((YMD[0]+j) % 4 == 0) && ((YMD[0]+j) % 100 != 0) | ((YMD[0]+j) % 400 == 0))
        {
            months[1] = 29; 
        }
        YMD[2] += months[(i+YMD[1])%12];
        months[1] = 28;
    }
    printf("你在这个世界上总共生存了%d天\n", YMD[2] + diffYMD[2]);
    return 0;
}







