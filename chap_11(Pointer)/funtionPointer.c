/*
함수 포인터
*/

#include <stdio.h>

// 아래 두개의 함수는 전달 인자의 타입, 갯수, 반환 타입이 같기 때문에
// 컴파일러 입장에서는 두 개는 같은 타입의 함수
int plus(int, int);
int minus(int, int);

int main(void)
{
    int a = 10, b = 20;
    int result;

    int (*fptr)(int, int); // plus()함수를 가리키는 포인터변수 선언

    fptr = plus; // 함수포인터로 함수 가리키기 (주소를 변수에 저장,,,?)
    // fptr이 함수를 대리

    result = fptr(a, b); // 함수호출부 : result = (* fptr)(a, b) ;
    printf("% d + % d = % d\n", a, b, result);

    fptr = minus;
    result = fptr(a, b);

    printf("%d - %d = %d\n", a, b, result);
}