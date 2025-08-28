#include <stdio.h>
#include <string.h>

#define MAX 1024
#define ROW 3

int question0();
int question1();
int question2();
int question2_1();

int main()
{
    question2_1();
    question2();
    question1();
    question0();
    return 0;
}


int question2_1()
{
    // 计算最大和最小值, 并打印条形图
    float airData[3][12] = {
        {0, 0, 0, 0, 0, 0, 0, 31.3, 35.5, 58.7, 49.6, 55.5},
        {59.8, 54.9, 33.1, 38.2, 26.6, 20.5, 27.8, 38.5, 41.5, 44.7, 38.1, 41.5},
        {34.9, 36.4, 47.5, 37.9, 30.6, 23.4, 26.6, 34.3, 0, 0, 0, 0}
    };
    float tempMAX = 0, tempMIN = 0, temp = 0;
    int volume = 0;
    // 找出最大值和最小值的部分
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            temp = airData[i][j];
            if (temp > tempMAX) // 找出最大值
            {
                tempMAX = temp;
            }
            else
            {
                // 找出最小值d
                if (temp > 0 && temp < tempMIN && tempMIN != 0)
                {
                    tempMIN = temp;
                }
                else
                {
                    if (tempMIN == 0)
                    {
                        tempMIN = temp;
                    }
                }
            }
        }
        
    }
    printf("MAX: %.2f | MIN: %.2f\n", tempMAX, tempMIN);

    // 打印条形图
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            volume = airData[i][j];
            if (volume != 0)
            {
                printf("%d年%2d月: ", i+2014, j+1);   
                for (int k = 0; k < volume; k++)
                {
                    printf("*");
                }
                printf("\n");
            }
            
            
        }
    }
    

    return 0;
}


int question2()
{
    float airData[3][12] = {
        {0, 0, 0, 0, 0, 0, 0, 31.3, 35.5, 58.7, 49.6, 55.5},
        {59.8, 54.9, 33.1, 38.2, 26.6, 20.5, 27.8, 38.5, 41.5, 44.7, 38.1, 41.5},
        {34.9, 36.4, 47.5, 37.9, 30.6, 23.4, 26.6, 34.3, 0, 0, 0, 0}
    };
    int year, month, row;
    float result;
    printf("请输入查询年月(年-月): ");
    scanf("%d-%d", &year, &month);
    row = year - 2014;
    if (row <= 2 && month <= 12 && row >= 0)
    {
        result = *(*(airData + row) + month-1);
        if (result == 0)
        {
            printf("该月份未收录数据!\n");
        }
        else
        {
            printf("%d年%d月广州的PM2.5值是: %.2f\n", year, month, result);
        }
    }
    else
    {
        printf("该月份未收录数据!\n");
    }
    return 0;
}


int question1()
{
    // 不使用二维数组的写法
    char string[MAX];
    int len = 0, i = 0, j = 0;
    printf("Please enter:\n");
    scanf("%s", string);
    len = strlen(string);
    do
    {
        i++;
        j = i*i;
    } while (j <= len);
    i = i - 1;
    // printf("i=%d\n", i);
    for(int k = 0, l = 0, m = i; k < i; k++, m += i)
    {
        for(; l < m; l++)
        {
            printf("%c ", string[l]);
        }
        printf("\n");
    }
    return 0;
}


int question0()
{
    char string[MAX][ROW];
    int len = 0;
    printf("Please enter:\n");
    scanf("%s", string);
    // printf("%s\n", string);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c ", *(*(string + i) + j));
        }
        printf("\n");
    }

    return 0;
}