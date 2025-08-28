#include <stdio.h>
//if语句

int main()
{
    int i;
    printf("您多大了\t");
    scanf("%d", &i);

    if (i>=18)
    {
        printf("进来搞耍!\n");
        getchar();
    }
    else
    {
        printf("慢走不送!\n");
        getchar();
    }
    getchar();
    return 0;
}