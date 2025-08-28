#include <stdio.h>

// 实现矩阵相乘功能, 允许用户自定义输入两个矩阵的尺寸和数据
int main()
{
    int M = 0, P = 0, P0 = 0, N = 0, temp = 0;

    printf("请输入矩阵A行列数(M * P): ");
    scanf("%d * %d", &M, &P);
    getchar();
    printf("请输入矩阵B行列数(P * M): ");
    scanf("%d * %d", &P0, &N);
    getchar();

    if (P0 == P)
    {
        // 可变长数组, 保存一个矩阵的行列数
        int matrixA[M][P]; // 矩阵A
        int matrixB[P][N]; // 被乘矩阵B
        int result[M][N];  // 结果矩阵C

        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                result[i][j] = 0;
            }
        }

        printf("请输入矩阵A的值:\n");
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < P; j++)
            {
                scanf("%d", &matrixA[i][j]);
            }
        }

        printf("请输入矩阵B的值:\n");
        for (int i = 0; i < P; i++)
        {
            for (int j = 0; j < M; j++)
            {
                scanf("%d", &matrixB[i][j]);
            }
        }
        
        /* 计算矩阵乘法部分*/
        for(int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < P; k++)
                {
                    result[i][j] += (matrixA[i][k] * matrixB[k][j]);
                    printf("result[%d][%d] += ( matrixA[%d][%d] * matrixB[%d][%d] = %d (%d * %d) )\n", i, j, i, k, k, j, (matrixA[i][k] * matrixB[k][j]), matrixA[i][k], matrixB[k][j]);
                }
                
            }
        }

        // 打印结果(测试用)
        printf("============Result============\n");
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
        printf("============Result============\n");
        
        // 更漂亮的打印效果:
        int count = P / 2;
        int row = (M > P ? M : P);
        for (int i = 0; i < P; i++)
        {
            // 打印matrixA
            for (int j = 0; j < P; j++)
            {
                if (i < M)
                {
                    printf("%d ", matrixA[i][j]);
                }
                else
                {
                    printf(" ");
                }
            }
            
            // 判断并打印乘号
            if(i == count)
            {
                printf(" * ");
            }
            else
            {
                printf("   ");
            }

            // 打印matrixB
            for (int k = 0; k < N; k++)
            {
                if (i < P)
                {
                    printf("%d ", matrixB[i][k]);
                }
                else
                {
                    printf(" ");
                }
            }

            // 判断并打印等于号
            if(i == count)
            {
                printf(" = ");
            }
            else
            {
                printf("   ");
            }

            // 打印结果矩阵
            for (int l = 0; l < M; l++)
            {
                if (i < M)
                {
                    printf("%d ", result[i][l]);
                }
                else
                {
                    printf(" ");
                }
            }

            printf("\n");

        }
        
    }
    else
    {
        printf("矩阵A的列数和矩阵B的行数不相等\n");
    }
    
    return 0;
}