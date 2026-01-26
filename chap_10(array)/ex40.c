#include <stdio.h>
#include <stdlib.h> // rand(), srand()
#include <time.h>   // time()

int main()
{
    int ary[5][5];
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;

    srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            ary[i][j] = rand() % 9 + 1;
            printf("%d ", ary[i][j]);

            if (i == j)
            {
                sum1 += ary[i][j];
            }
            else if (i < j)
            {
                sum2 += ary[i][j];
            }
            else
            {
                sum3 += ary[i][j];
            }
        }
        printf("\n");
    }
    printf("sum1: %d, sum2: %d, sum3: %d", sum1, sum2, sum3);
}