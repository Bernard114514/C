#include <stdio.h>

int question5();

int main()
{
    int *pa = NULL;
    // void a;
    int *b = (void *)0;
    printf("%d\n", b == NULL);
    if (pa == NULL)
    {
        printf("pa == NULL\n"); // 指向NULL的指针, 不操作
        // printf("%d\n", *pa); // 如果对NULL指针解引用, 会直接出现Segmentation fault
    }
    else
    {
        printf("%d\n", *pa); // 执行解引用操作
    }

    question5();
    return 0;
}

int question5()
{
        int array[5] = {1, 2, 3, 4, 5};
        int *pi = &array[2];
        void *pv;
        // pv = (int *)pv;
        pv = pi;
        pv++;
        pi = pv;

        printf("%d\n", *pi);

        return 0;
}