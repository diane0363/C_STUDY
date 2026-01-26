#include <stdio.h>
#include <stdlib.h> // rand()함수 라이브러리

int main()
{
    // srand(1);   // 난수 고정 (seed 값 사용)
    // srand(time(0))  // 현재 시간을 기준으로 seed값 사용

    int num;
    for (int i = 0; i < 10; ++i)
    {
        num = rand() % 100 + 1; // 0 ~ 99 ==> 1 ~ 100
        printf("%d ", num);
    }
}