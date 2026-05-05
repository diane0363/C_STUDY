#include <stdio.h>

int main() {
    // 정수형, 실수형 변수 선언해봄
    int a = 10;
    float b = 3.14f;
    double c = 3.141592;
    char d = 'A';

    // 출력 형식 지정자 %d, %f, %c 연습함. 은근 헷갈림.
    printf("정수: %d\n", a);
    printf("실수(float): %.2f\n", b); // 소수점 둘째자리까지만 출력하게 해봄
    printf("실수(double): %lf\n", c);
    printf("문자: %c\n", d);

    // sizeof 연산자로 크기 확인해봄. int는 4바이트임.
    printf("int 크기: %zu\n", sizeof(a));

    return 0;
}
