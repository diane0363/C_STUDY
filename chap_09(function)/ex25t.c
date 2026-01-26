#include <stdio.h>
#include <stdlib.h>

int isPrime(int);

int main()
{
    int num, primeCnt = 0;

    printf("정수입력: ");
    scanf("%d");

    if (num < 2)
    {
        printf("2 이상 숫자 입ㄺ");
        exit(0);
    }

    for (int i = 2; i <= num; ++i)
    {
        if (isPrime(i))
        {
            primeCnt++;
            printf("%d ", i);
        }
    }
    printf("\n2~%d까지 소수는 %d개 입니다. \n", num, primeCnt);
}

int isPrime(int value)
{
    for (int j = 2; j < value; ++j)
        if (value % j == 0)
            return 0;
    return 1; // 문장 하나면 중괄호 생략 가능
}