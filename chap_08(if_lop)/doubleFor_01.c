#include <stdio.h>

int main()
{
    for (char i = 'a'; i < 'z'; ++i)
    {
        for (char j = i; j <= 'z'; ++j)
        {
            printf("%c", j);
        }
        printf("\n");
    }
    return 0;
}