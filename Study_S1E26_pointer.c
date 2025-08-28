#include <stdio.h>

int sample0();

int main()
{
    // 指向指针的指针
    int num = 100;
    int *p = &num;
    int **pp = &p; // 声明指向指针p的指针, 因此要对指针p用取址符

    // 例子: 
    printf("num = %d\n", num);
    printf("*p = %d\n", *p); // *p 一层解引用, 值为num的值
    printf("*PP = %d\n", **pp); // **pp两层解引用, 指针值为num的值
    printf("&p = %p, pp = %p\n", &p, pp); // pp的值, 为指针p自身的地址
    printf("&num = %p, p = %p, *pp = %p\n", &num, p, *pp); //*pp一层解引用, 值为指针p指向的地址, 即num的地址
    
    sample0();
    return 0;
}

int sample0()
{
    /* 
    简单的应用案例:
        利用指向指针的指针数组, 给指针数组内的字符串分类
    优势:
        避免重复分配内存
        只需要进行一处修改
        ->提升代码的灵活性和安全性
    */

    // 利用指针数组存储字符串
    char *cBooks[] = {
    "C程序设计语言",
    "C专家编程",
    "C和指针",
    "C陷阱与缺陷",
    "C Primer Plus",
    "带你学C带你飞"
    };
    char **byFishC;
    char **iLoves[5];
    char *test[6]; // 用作对比

    byFishC = &cBooks[5];
    for (int i = 0; i < 5; i++)
    {
        iLoves[i] = &cBooks[i];
    }

    printf("FishC出版的图书有:\n\t%s\n", *byFishC);

    printf("我喜欢的书籍有:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("\t%s\n", *iLoves[i]);
    }

    printf("===============\n如果不使用指向指针的指针数组:\n");
    for (int i = 0; i < 6; i++)
    {
        test[i] = cBooks[i];
    }
    test[0] = "test: from test";
    printf("修改test[0]: cBooks[0] = %s\n", cBooks[0]);
    *iLoves[0] = "test: from iLoves";
    printf("修改iLoves[0]: cBooks[0] = %s\n", cBooks[0]);
    printf("test[] = %p | cBooks[] = %p | iLoves[] = %p\n", test[0], cBooks[0], *iLoves[0]);

    return 0;
}