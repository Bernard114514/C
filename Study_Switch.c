#include <stdio.h>
#include <math.h>
//switch语句, 以及一些题目

#include <stdio.h>

int main() {
        printf("Choose what to run:\t");
        int num;
        scanf("%d", &num);
        switch (num) {
                case 0: {
                        char ch[6] = "FishC";
                        int i;
                        int h = sizeof(ch);
                        printf("%d\n", h);
                        printf("请输入你想访问的字符序号(0~5)：");
                        scanf("%d", &i);
                        if (i < 0 || i > (h-1)) {
                                printf("Out Of Range!\n");
                        }
                        else {
                                printf("%c\n", ch[i]);
                        }

                }; break;

                case 1: {
                        printf("Quit.\n");
                }; break;

                default: {
                        printf("You Choose Nothing.\n");
                }; break;
        }
        
        return 0;
}