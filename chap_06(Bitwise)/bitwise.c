#include <stdio.h>

int main() {
    // 비트 연산자 공부함. 실무에서 많이 쓴다고 해서 꼼꼼히 봄.
    int a = 5;  // 0101
    int b = 3;  // 0011

    // AND, OR, XOR, NOT 연산자 테스트해봄.
    printf("a & b = %d\n", a & b); // 0001 (1)
    printf("a | b = %d\n", a | b); // 0111 (7)
    printf("a ^ b = %d\n", a ^ b); // 0110 (6)
    printf("~a = %d\n", ~a);       // 2의 보수 계산이라 -6 나옴. 좀 신기함.

    // 쉬프트 연산자. 곱하기 나누기 대신 쓰면 빠르다고 함.
    printf("a << 1 = %d\n", a << 1); // 10 (5 * 2)
    printf("a >> 1 = %d\n", a >> 1); // 2  (5 / 2)

    return 0;
}
