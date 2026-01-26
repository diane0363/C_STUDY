#include <stdio.h>

int main()
{
    int i;
    int sum = 0;

    for (i = 1; i <= 10; ++i)
        sum += i;

    printf("1~%d까지의 합 = %d\n", (i - 1), sum);
    return 0;
}