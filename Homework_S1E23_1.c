#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1.依据给出的代码填充完整：

//2.矩阵转置

int main()
//2.矩阵转置
{
    char *array[5] = {"FishC", "Five", "Star", "Good", "WoW"};
    char *(*pa)[5] = &array;
    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; (j < 5) && (i < strlen((*pa)[j])); j++)   
        {
            printf("%c ", array[j][i]); // array[i][j] 等价于 (*pa)[i][j] 等价于 *(array[i] + j) 等价于 *(*(array + i) + j) 等价于 *(*(*pa + i) + j)
        }
        printf("\n");
    }
    
    return 0;
}

// int main()
//// 1.依据给出的代码填充完整：
// {
//     char *array[5] = {"FishC", "Five", "Star", "Good", "WoW"};
//     char *(*pa)[5] = &array;
//     int i, j;
//     for (i = 0; i < 5; i++)
//     {
//         for (j = 0; *(*(*pa + i) + j) != '\0'; j++)   
//         {
//             printf("%c ",*(array[i] + j)); // array[i][j] 等价于 *pa[i][j] 等价于 *(array[i] + j) 等价于 *(*(array + i) + j) 等价于 *(*(*pa + i) + j)
//         }
//         printf("\n");
//     }
    
//     return 0;
// }