#include <stdio.h>

int main() {

    int countA = 0, countE = 0, countI = 0, countO = 0, countU = 0;
    char words;
    printf("请输入一个英文句子: ");
    while (1) {
        words = getchar();
        if (words == 'a' || words == 'A') {
            countA ++; //自加1
            continue;
        }

        else if (words == 'e' || words == 'E') {
            countE ++;
            continue;
        }

        else if (words == 'i' || words == 'I') {
            countI ++;
            continue;
        }

        else if (words == 'o' || words == 'O') {
            countO ++;
            continue;
        }

        else if (words == 'u' || words == 'U') {
            countU ++;
            continue;
        }

        else if (words == '\n') {
            break;
        }
    }
    
    printf("您输入的句子中，包含原音字母 %d 个\n\
其中: a(%d), e(%d), i(%d), o(%d), u(%d)\n", (countA + countE + countI + countO + countU),\
    countA, countE, countI, countO, countU);

    return 0;
}