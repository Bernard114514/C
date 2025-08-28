#include <stdio.h>

int countString(char *word);
int countStringSpace(char *word);
void question_0();

int main() 
{
    // question_0(); // 主要用数组实现的版本
    // 使用指针再写一次
    int row = 0, column = 0, temp_column = 0, count = 0;
    char temp[256], *pt;
    printf("请输入一段英文句子: ");
    scanf("%[^\n]", temp);
    // count = countStringSpace(temp);
    // printf("debug 0: %s | %d\n", temp, count);
    pt = temp;
    while (1)
    {
        // printf("test: %c\n", *pt);
        if (*pt == ' ')
        {
            if (*(pt+1) != ' ')
            {
                row++;
                temp_column = 0;
            }

        }
        else if (*pt == '\0')
        {
            row++;
            temp_column = 0;
            break;
        }
        else
        {
            temp_column++;
            if (temp_column > column)
            {
                column = temp_column;
            }
        }
        pt++;
        count++;
    } 
    printf("debug 1: row: %d | column: %d | count: %d\n", row, column, count);
    char result[row][column], (*pr)[column];
    pr = result;
    for (int i = 0, j = 0, k = 0; k < count+1; k++)
    {
        if (temp[k] != ' ' && temp[k] != '\0')
        {
            *(*(pr + i) + j) = temp[k];
            // printf(": %c | k = %d | j = %d \n", *(*(pr + i) + j), k, j);
            j++;
        }
        else if (temp[k+1] != ' ')
        {
            j = 0;
            printf(": %s\n", *(pr+i));
            i++;
        }
        else if (temp[k] == '\0')
        {
            printf(": %s\n", *(pr+i));
        }

        
    }

}

/*
自定义函数区域------------------------------------------
*/

int countString(char *word) 
{
    // 实现计算输入的字符串(不含空格)长度的功能
    int count = 0, space = 0;
    while (1)
    {
        if (*(word + count) == '\0')
        {
            break;
        }
        else if (*(word + count) == ' ')
        {
            count++;
            space++;
        }
        else
        {
            count++;
        }
    }
    return count - space;
}

int countStringSpace(char *word) 
{
    // 实现计算输入的字符串总长度(不含\0)的功能
    int count = 0;
    while (1)
    {
        if (*(word + count) == '\0')
        {
            break;
        }
        else
        {
            count++;
        }
    }
    return count;
}

void question_0()
{
    // 用数组写的版本, 尝试用指针写一次
    int row = 0, column = 0, count = 0;
    char input[256], temp[256];

    printf("请输入一个英文句子: ");
    scanf("%[^\n]", input);
    count = countStringSpace(input);
    printf("Your input: %s\n", input);
    printf("Length: %d\n", count);

    // 将输入的句子按空格切片, 计算出最长的单词长度, 以及单词数量:
    for (int i = 0, j = 0, _length = 0; i < count+1; i++, j++)
    {
        if (input[i] != ' ' && input[i] != '\0')
        {
            temp[j] = input[i]; // 测试用
            _length++;
            if (_length > column) {
                column = _length;
            }
        }
        else if (input[i] == ' ')
        {
            // 当读取到空格时
            if (input[i+1] != ' ')
            {
                // 判断空格是否要结束
                row++;
                temp[j] = '\0'; // 测试用
                j = -1;
                // printf(":%s\n", temp); //测试用
                _length = 0;
            }
            
        }
        else
        {
            // 当读取到字符串末尾时
            row++;
            temp[j] = '\0'; // 测试用
            j = -1;
            // printf(":%s\n", temp); //测试用
            _length = 0;
        }
    }
    // printf("Row: %d\nColumn: %d\n", row, column);
    printf("分割结果已存放到result[%d][%d]数组中\n", row, column);
    printf("下面依次打印每个单词: \n");
    char words[row][column+1]; // 初始化二维数组
    // char **writter = words; // 生成指向二维数组中第一个数组0号元素的指针
    for (int i = 0, j = 0, k = 0; i < row, j < column, k < count; k++)
    {
        if (input[k] != ' ' && input[k] != '\0')
        {
            words[i][j] = input[k];
            // printf("debug: %s\n", words[i]);
            j++;
        }
        else if (input[k] == ' ')
        {
            if(input[k+1] != ' ')
            {
                words[i][j+1] = '\0';
                printf(": %s\n", words[i]);
                i++;
                j = 0;
            }
        }
        else
        {
            words[i][j+1] = '\0';
        }
    }
    printf(": %s\n", words[row-1]);
}