#include <stdio.h>
#include <string.h>

int main() {
    // 문자열 다루는 함수들 연습함. C언어는 문자열 처리가 빡셈...
    char str1[20] = "Hello";
    char str2[20];

    // strcpy로 문자열 복사함. 대입 연산자(=)로는 배열 복사가 안 됨.
    strcpy(str2, str1);
    printf("복사된 문자열: %s\n", str2);

    // strcat으로 문자열 이어붙임. 공간 넉넉하게 잡아야 에러 안 남.
    strcat(str1, " World");
    printf("이어붙인 문자열: %s\n", str1);

    // strlen으로 길이 잼. 널문자(\0)는 빼고 계산됨.
    printf("str1의 길이: %zu\n", strlen(str1));

    // strcmp로 문자열 비교. 같으면 0 나옴.
    if (strcmp(str1, str2) != 0) {
        printf("두 문자열은 다름!\n");
    }

    return 0;
}
