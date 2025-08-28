#include <stdio.h>
#include<stdlib.h>


int main()
{
    int diffYMD[3] = {0}, YMD[3] = {0}, months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //日期数组格式YYYY/MM/DD
    char birthday[11], today[11];
    float life80;

label0:    printf("> Please enter your birthdate (Format example: 2002-04-02):");
    scanf("%s", &birthday);

    printf("> Please enter current date (Format example: 2024-08-28):");
    scanf("%s", &today);

    diffYMD[0] = (today[0]-birthday[0])*1000 + (today[1]-birthday[1])*100 + (today[2]-birthday[2])*10 + (today[3]-birthday[3]); //计算二者差了多少年
    if(diffYMD[0] < 0)
    {
        goto label0;
        printf("ERROR: Time-going-backwards\n");
    }
    diffYMD[1] = (today[5]-birthday[5])*10 + (today[6]-birthday[6]); //计算二者相差多少月
    diffYMD[2] = (today[8]-birthday[8])*10 + (today[9]-birthday[9]); //计算二者相差多少天

    YMD[0] = (birthday[0]-48)*1000 + (birthday[1]-48)*100 + (birthday[2]-48)*10 + (birthday[3]-48); //用于计算是否是闰年
    YMD[1] = (birthday[5]-48)*10 + (birthday[6]-48); //计算开始月份
    
    for(int i = 1, j = 0; i < 80*12 + 1; i++)
    {
        if(diffYMD[0]*12 + diffYMD[1] > 80*12)
        {
            printf("ERROR: Index Out Of Range\n");
            goto label0;
        }
        j = i / 12;
        
        if(((YMD[0]+j) % 4 == 0) && ((YMD[0]+j) % 100 != 0) | ((YMD[0]+j) % 400 == 0))
        {
            months[1] = 29; 
        }
        life80 += months[(i+YMD[1])%12]; //计算80年对应的天数
        
        if(i == diffYMD[0]*12 + diffYMD[1])
        {
            YMD[2] = (int)life80; //保存生日至输入日期的天数
        }
        months[1] = 28;
    }
    printf("----------------------------------------\n> You have survived <%d> days on Earth.\n", YMD[2] + diffYMD[2]);
    printf("> If you can live to be 80 years old,\n> you have <%d> days remain.\n", (int)life80 - (YMD[2] + diffYMD[2]));
    printf("> You have already used <%.2f%%> of your life, use the time wisely!\n----------------------------------------\n", ((YMD[2] + diffYMD[2]) / life80) * 100);
    printf("> Press any key to exit(this program, not your life)...>\n");
    system( "pause" );

    return 0;
}