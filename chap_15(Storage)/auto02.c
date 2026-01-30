/*
- auto 저장 클래스는 지역변수의 기본 저장 클래스
- 지역변수는 초기화 되지 않음
- 쓰레기값도 사용하기 때문에 예측불가한 결과 발생
*/
#include <stdio.h>

void workover(int);
int reset(int);
int main()
{
    auto int a = 5;

    reset(a / 2);
    printf("%d₩n", a);

    reset(a /= 2);
    printf("%dWn", a);

    a = reset(a / 2);
    printf("%d₩n", a);

    workover(a);
    printf("%d₩n", a);

    return 0;
}

void workover(int a)
{
    a = ((a * a) / (2 * a) + 4) * (a % a);
    printf("%d₩n", a);
}

int reset(int a)
{
    a = (a < 2) ? 5 : 0;
    return (a);
}