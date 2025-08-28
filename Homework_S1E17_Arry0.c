#include <stdio.h>
#include <math.h>

int main()
{
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year;
    printf("请输入一个年份: ");
    scanf("%d", &year);
    // printf("DEBUG: %d\n", year);
    if((year % 4 == 0) && (year % 100 != 0) | (year % 400 == 0))
    {
        months[1] = 29;
        for(year = 0; year < 12; year++)
        {
            printf("%2d月份: %2d天\n", year + 1, months[year]);
        }
    }
    else
    {
        for(year = 0; year < 12; year++)
        {
            printf("%2d月份: %2d天\n", year + 1, months[year]);
        }
    }
    return 0;
}