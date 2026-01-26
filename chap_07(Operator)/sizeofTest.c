#include <stdio.h>

int main()
{

    int a, b[10];
    double c[3]; // 8바이트 데이터타입 3개

    // 해당 정수를 처리하는데 필요한 메모리 (바이트)
    // 메모리 요구 사이크 체크 sizeof(..)
    printf("5 size : %dByte\n", sizeof(5));
    printf("5.0 size : %dByte\n", sizeof(5.0));
    printf("5.0F size : %dByte\n", sizeof(5.0f));

    char ch = 'A';
    printf("\nchar size : %dByte\n", sizeof(char));

    // 문자열을 다이렉트로 사용하는 경우 !!!!!!
    // 'A'를 메모리에 저장한 후 꺼내서 출력
    // 메모리 저장 과정에서 패딩값이 생긴다. (사용하지 않는 .. )
    // 그래서 4바이트로 출력된다. . .
    printf("'A' size : %dByte\n", sizeof('A'));

    printf("ch size : %dByte\n", sizeof(ch));
    printf("int size : %dByte\n", sizeof(int));
    printf("float size : %dByte\n", sizeof(float));
    printf("double size : %dByte\n", sizeof(double));

    // 단일 바이트
    printf("a size : %dByte\n", sizeof(a));
    // 배열
    printf("b size : %dByte\n", sizeof(b));
    printf("c size : %dByte\n", sizeof(c));

    // 문자열 + 문자열 마감 0 이 붙는다.
    printf("'A' size : %dByte\n", sizeof('A'));
    printf("\"A\" size : %dByte\n", sizeof("A"));   // A0 -> 2Byte
    printf("\"AB\" size : %dByte\n", sizeof("AB")); // AB0 -> 3Byte

    printf("=====배열 요소 계산======\n");
    // 배열 요소의 개수를 계산하는 공식
    int cnt = sizeof(b) / sizeof(b[0]);

    printf("b size : %dByte\n", sizeof(b)); // 40 / 4(int) ==> 배열의 개수를 10개
    printf("b type : %dByte\n", sizeof(b));

    return 0;
}