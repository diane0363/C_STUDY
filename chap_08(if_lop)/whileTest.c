#include <stdio.h>

int main()
{
    int i = 1;
    int sum = 0;

    while (i <= 10)
    {
        sum += i;
        i++;
    }
    printf("1~%d까지의 합 = %d\n", (i - 1), sum);
    return 0;
}