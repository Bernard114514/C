#include <stdio.h>
//第0题:
/*
70 年代后期，Steve Bourne（关于这位大神的故事，大家在本节的知识点备忘的彩蛋环节看到^_^）
在贝尔实验室编写 UNIX 第7 版的 shell（命令解释器）时，决定采用 C 预处理器使 C 语言看上去更像 Algol-68
他发现如果代码中有显式的“结束语句”提示，诸如 if ... fi 或者 case ... esac 等，
调试起来会更容易。Steve 认为仅仅一个“}”是不够的，
因此他建立了许多预处理定义：
如下
*/
#define STRING char *
#define IF if(
#define THEN ){
#define ELSE }else{
#define FI ;}
#define WHILE while(
#define DO ){
#define OD ;}
#define INT int
#define BEGIN {
#define END }

/*
//例如以下:
int main()
BEGIN
    printf("Hello World\n");
    getchar();
    return 0;
END
*/

//以同样方式改写代码：
int main()
BEGIN
    int i;

    printf("请输入您的年龄：");
    scanf("%d", &i);

    IF i < 18 THEN
        printf("您未满18周岁，不得使用这个程序！\n");
    ELSE
        printf("您已满18周岁，欢迎使用本程序，嘿嘿嘿...\n");
    END
    return 0;
END