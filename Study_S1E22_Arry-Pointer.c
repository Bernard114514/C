#include <stdio.h>

int main()
{
    char str[128];
    printf("请输入一个字符串:");
    scanf("%s", str);
    printf("\n你输入的字符串是: %s\n", str);

    printf("数组str的地址是: %p\n", str);
    printf("数组str中第一个值的地址是: %p\n", &str[0]);
    printf("由此可见，数组名其实是数组第一个元素的地址，因此一般数组前不需要加取址符&\n");

    return 0;
}