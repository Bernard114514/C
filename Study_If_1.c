#include <stdio.h>
//分数评级程序
int main()
{
    float score;
    printf("请输入需要判别的分数:\t");
    scanf("%f", &score);

    if (score < 60)
    {
        printf("%f 的等第为 E\n", score);
        getchar();
    }
    
    else if (score >= 60 && score < 70)
    {
        printf("%.2f 的等第为 D\n", score);
        getchar();
    }

    else if (score >= 70 && score < 80)
    {
        printf("%.2f的等第为 C\n", score);
        getchar();
    }

    else if (score >= 80 && score < 90)
    {
        printf("%.2f 的等第为 B\n", score);
        getchar();
    }
    
    else
    {
        printf("%.2f 的等第为 A\n", score);
        getchar();
    }

    getchar();
    return 0;
}
