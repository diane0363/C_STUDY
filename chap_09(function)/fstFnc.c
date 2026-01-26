#include <stdio.h>

// 함수의 선언 (호출보다 위에)
// 반환 타입과 매개 변수의 타입이 중요해서 변수 이름은 쓰지 않아도 ㄱㅊ
int add(int, int);
int multiply(int, int);

int main()
{
    int result1 = add(5, 6);

    int result2 = 0, a = 5, b = 6;
    result2 = multiply(a, b);

    // printf("결과 : %d , %d \n", &result1, &result2); // &변수는 값이 아닌 주소 출력
    // scanf를 쓸 때는 주소를 알려줘야해서 &연산자 사용하지만 printf는 값 출력이라 빼야함
    printf("결과 : %d , %d \n", result1, result2);
    return 0; // 운영체제 커널로 0을 반환해 프로그램 종료
}

// 함수의 정의
int add(int a, int b)
{
    int c;
    c = a + b;

    return c; // main으로 return (제어가 되돌아간다.)
}

int multiply(int a, int b)
{
    return a * b;
}