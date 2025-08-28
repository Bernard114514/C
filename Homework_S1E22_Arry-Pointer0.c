#include <stdio.h>
#include <stdlib.h>

#define MAX 1024 // 设定数组的长度

/*
如果要在 VS Code 环境外使用, 编译时请选择: Saving With Code -> GBK
保存源代码前请选择: Saving With Code -> UTF-8

题目0: 
    使用 fgets 函数（使用文档 -> 传送门）读取用户输入的字符串（英文），并用指针法来计算字符串的字符个数。
    请自行观察你当前系统对中文字符的处理方式，并设计一个可以统计中文字符以及中英文混合字符的程序。
问题解决

题目1:
    自定义拷贝字符串 —— 仿造 strcpy 和 strncpy 函数
    实现 strncpy 函数，让用户输入需要拷贝的字符个数（注意：该程序需要能够正确拷贝中英混合的字符串）
问题已解决20240920, 方案是增加bool值复位机制, 避免重复统计gbk字符

题目2. 连接字符串 —— strcat 和 strncat 函数：
    基础要求：使用 fgets 函数接收用户输入的两个字符串到 str1 和 str2 中，将 str2 连接到 str1 后边，并打印出来
    进阶要求：实现 strncat 函数，让用户输入需要连接到 str1 后边的字符个数（注意：该程序需要能够正确拷贝中英混合的字符串）
问题已解决, 兼容中英文时可以套用copystr()中的代码-20241024

题目3. 比较字符串 —— strcmp 和 strncmp 函数:
    基础要求：使用 fgets 函数接收用户输入的两个字符串（仅支持英文）到 str1 和 str2 中，对比 str1 和 str2，
    如果两个字符串完全一致，打印“完全一致”；如果存在不同，打印第一处不同的位置（索引下标）
    进阶要求：实现 strncmp 函数，允许用户指定前 n 个字符进行对比，这一次要求支持中英文混合的字符串比较噢！

由于编码问题,该方法仅在gbk编码下有效
*/


/* 
-------------------------------函数声明区-------------------------------
*/
int arryCounter_GBK(char str[MAX]);
int arryCounter_8bit(char str[MAX]);
char *copystr(char str1[MAX], char str2[MAX], int length);
char *filter_fgets_str(char *str); //用于去除多获取的回车
char copyTo(char str1[MAX], char str2[MAX], int copyLen); // 将str2拷贝到str1
char compare(char str1[MAX], char str2[MAX], int len); // 比较字符串str1和str2的内容是否一致


/* 
-------------------------------主函数区-------------------------------
*/
int main() 
{
    char str[MAX], str1[MAX], str2[MAX], *pstr, *pstr2, question = 0;
    int countNum = 0, length = 0;
    int copyLen = 0; // 用于设置输入长度
    int len; // 用于设置被比较字符串的长度

    printf("请选择题目:");
    scanf("%d", &question);

    if (question == 0)
    {
        // 题目0
        getchar();
        printf("请输入一个字符串:");
        fgets (str, MAX, stdin);
        filter_fgets_str(str);
        printf("你输入的字符串是:\n%s\n", str);
        countNum = arryCounter_GBK(str);
        printf("您总共输入了 %d 个字符\n", countNum);
    }
    else if (question == 1)
    {
        //题目1
        getchar();
        printf("请输入一个字符串到 str1 中:");
        fgets (str1, MAX, stdin);
        filter_fgets_str(str1);
        printf("你输入的字符串是:\n%s\n", str1);
        printf("请输入需要拷贝的字符个数:");
        scanf("%d", &length);
        copystr(str1, str2, length);
        printf("拷贝完毕! 现在str2中的内容是:%s\n", str2);
    }
    else if (question == 2)
    {
        // 题目2：
        getchar();
        printf("请输入一个字符串到 str1 中:");
        fgets (str1, MAX, stdin);
        filter_fgets_str(str1);
        printf("请输入一个字符串到 str2 中:");
        fgets (str2, MAX, stdin);
        filter_fgets_str(str2);
        // 下一步：将str2拼接到str1后部
        // 进阶: 可以手动设置拷贝长度，兼容中文
        printf("请输入希望拷贝的字符串长度:");
        scanf("%d", &copyLen);
        copyTo (str1, str2, copyLen);
        printf("拷贝后的str1=%s\n", str1);
        printf("str1=%s\nstr2=%s\n", str1, str2);
    }
    else if (question == 3)
    {
        // 题目3:
        getchar();
        printf("请输入一个字符串到 str1 中:");
        fgets (str1, MAX, stdin);
        filter_fgets_str(str1);
        printf("请输入一个字符串到 str2 中:");
        fgets (str2, MAX, stdin);
        filter_fgets_str(str2);
        printf("请输入希望比较的字符串长度:");
        scanf("%d", &len);
        compare(str1, str2, len);
    }

    // getchar();
    system( "pause" );
    return 0;
}


/* 
-------------------------------自定义函数区-------------------------------
*/


//计算数组中包括gbk字符和回车的总元素个数
int arryCounter_GBK(char str[MAX])
{
    char *pstr;
    int countNum1 = 0;
    pstr = str; //将 指针 指向 数组

    for (int i = 0, gbk = 0, flag = 0; flag == 0;)
    {
        if (*(pstr + i) != '\0')
        {
            // printf("DEBUG: item = %d\n", *(pstr + i));
            //由于gbk二进制码开头为1,因此用int类来比较的话其值小于0(详情参见C语言保存负数的基本知识),用此特性判断值是否是gbk编码的汉字
            if ( (int)*(pstr + i) < 0) 
            {
                gbk++; //由于gbk编码汉字由2个8位1开头的二进制编码构成，因此根据逻辑判断该值一定为偶数，因此gbk/2即为其中的汉字个数
            }
            i++;
        }
        else
        {
            countNum1 = i - gbk/2; 
            printf("DEBUG: GBK = %d | i = %d\n", gbk, i);
            flag = 1;
        }
    }

    return countNum1; //返回统计出的数字，但是这里不包括多输入的换行符和'\0'
}


//用于拷贝字符串, 从str1拷贝到str2, 并且能手动设置拷贝长度
char *copystr(char *str1, char *str2, int length)
{
    // char *pstr2;
    int num1 = arryCounter_8bit(str1) + 2;
    _Bool flag = 1;
    if (length <= num1)
    {
        num1 = length;
    }
    for (int i = 0; i < num1; i++)
    {
        if ((int)*(str1 + i) < 0 && flag) //如果第一个字节是负数, 则说明此为gbk字符, 占用2字节, 因此+1
        {
            num1++;
            flag = 0;
        }
        else if ((int)*(str1 + i) > 0) //如果该字节是ASCII字符，则将flag复位成1
        {
            flag = 1;
        }
        else if((int)*(str1 + i) < 0 && flag == 0) //如果该字节是gbk字符 并且 flag == 0, 则将flag复位成1 (这表明这是一个gbk字符占用的两个字节中的第二个)
        {
            flag = 1;
        }
        
        *(str2 + i) = *(str1 + i);
        // printf("DEBUG: str2[%d] = %c\n", i, *(str2 + i));
    }
    str2[num1] = '\0';
    printf("str2 = %s\n", str2);
    // char *pa = str2;

    return str2; //返回str2指针，指向str2数组的第0个元素
}


//计算数组中所有ASCII字符的总元素个数
int arryCounter_8bit(char str[MAX])
{
    char *pstr;
    int countNum = 0;
    pstr = str; //将 指针 指向 数组

    for (int i = 0, flag = 0; flag == 0;)
    {
        if (*(pstr + i) != '\0')
        {
            i++;
        }
        else
        {
            countNum = i; 
            printf("DEBUG: i = %d\n", i);
            flag = 1;
        }
    }

    return countNum;
}


//自动去除fgets()指令从输入流中多获取的一个回车
char *filter_fgets_str(char *str)
{
    // char *pstr;
    int countNum = 0;
    // str; //将 指针 指向 数组

    for (int i = 0, gbk = 0, flag = 0; flag == 0;)
    {
        if (*(str + i) != '\0')
        {
            i++;
        }
        else
        {
            countNum = i; 
            // printf("DEBUG: i = %d\n", i);
            flag = 1;
        }
    }

    str[countNum - 1] = '\0';

    return str;
}

// 将str2内容拷贝合并到str1末尾\0上的函数
char copyTo(char str1[MAX], char str2[MAX], int copyLen)
{
    int str1Len = 0, str2Len = 0;
    _Bool flag = 1;
    // 先按照1字节的模式获取两个字符串的真实长度
    str1Len = arryCounter_8bit(str1);
    str2Len = arryCounter_8bit(str2);
    int index = 0;
    if (copyLen == 0 || copyLen >= str2Len)
    {
        copyLen = str2Len;
    }
    
    for (int i = 0; i < copyLen; i++) 
    {
        if ((int)*(str2 + i) < 0 && flag) //如果第一个字节是负数, 则说明此为gbk字符, 占用2字节, 因此+1
        {
            copyLen++;
            flag = 0;
        }
        else if ((int)*(str2 + i) > 0) //如果该字节是ASCII字符，则将flag复位成1
        {
            flag = 1;
        }
        else if((int)*(str2 + i) < 0 && flag == 0) //如果该字节是gbk字符 并且 flag == 0, 则将flag复位成1 (这表明这是一个gbk字符占用的两个字节中的第二个)
        {
            flag = 1;
        }
        index = i + str1Len;
        *(str1 + index) = *(str2 + i);
        printf("Copy str2-%d to str1-%d\n", i, index);
    }
    *(str1 + index + 1) = '\0'; //补上字符串末尾的结束符号'\0'

    return 0;
}

// 比较字符串str1和str2的内容是否一致
char compare(char str1[MAX], char str2[MAX], int len)
{
    int length1 = arryCounter_8bit(str1), length2 = arryCounter_8bit(str2);
    int num = 0;
    _Bool flag = 1, gbk = 1;
    if (length2 < length1)
    {
        num = length1;
        flag = 0;
    }
    else if (length1 < length2)
    {
        num = length2;
        flag = 0;
    }
    else
    {
        num = length1;
    }

    if (len < num && len != 0)
    {
        num = len;
    }


    for (int i = 0; i < num; i++)
    {
        // 先判断是不是gbk字符
        if ((int)*(str2 + i) < 0 && gbk) //如果第一个字节是负数, 则说明此为gbk字符, 占用2字节, 因此+1
        {
            num++;
            gbk = 0;
        }
        else if ((int)*(str2 + i) > 0) //如果该字节是ASCII字符，则将gbk复位成1
        {
            gbk = 1;
        }
        else if((int)*(str2 + i) < 0 && gbk == 0) //如果该字节是gbk字符 并且 gbk == 0, 则将gbk复位成1 (这表明这是一个gbk字符占用的两个字节中的第二个)
        {
            gbk = 1;
        }
        // 判断内容是否一致
        if (*(str1 + i) != *(str2 + i))
        {
            printf("存在不一致: 起始位置: (str1)index = %d\n", i);
            flag = 0;
            break;
        }
        else
        {
            printf("i = %d 相等\n", i);
            flag = 1;
        }
    }

    if (flag)
    {
        printf("str1和str2在指定范围内完全一致\n");
    }
    return 0;
}

/*
一些问题汇总：
0:关于fgets()函数被跳过的问题：
    C语言里的gets()函数功能是从输入缓存中读取多个字符，遇到回车符时，结束输入。
    当使用gets()函数之前有过数据输入，并且，操作者输入了回车确认，这个回车符没有被清理，被保存在输入缓存中时，gets()会读到这个字符，结束读字符操作。
    因此，从用户表面上看，gets()没有起作用，跳过了。
    简单解决方案：如果程序之前有过输入操作，在操作后补一个getchar();命令带走回车输入，再使用fgets();就不会有问题

*/