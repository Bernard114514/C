#include <stdio.h>
#include <math.h>

int main()
{
    char test0[128] = "Hello World";
	char *test1;
		
        test1 = test0;
        
        printf("%c", *test0);
        printf("%c", *(test0 + 1));
        printf("%c", test0[3]);
        printf("%c", *(&test0[3]));
        printf("%c ", *(test0 + 4));
        printf("%c", *test1);
        printf("%c", *(test1 + 1));
        printf("%c", test1[3]);
        printf("%c\n", *(&test1[3]));
    
        return 0;
}