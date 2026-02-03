#include <stdio.h>

int *count(char *);

int main()
{

    // ""로 연결된 문자열이 하나의 문자열로 인식된다.
    char strp[] = "Hello, it's me!"
                  "I was wondering";

    int *result = count(strp);
    printf("대문자의 개수: %d\n", result[0]);
    printf("소문자의 개수: %d\n", result[1]);
    printf("숫자의 개수: %d\n", result[2]);
    printf("특수문자의 개수: %d\n", result[3]);
    return 0;
}

/* 처리한 결과를 담은 배열 반환 */
int *count(char *str)
{
    int result[4] = {0}; // 대문자, 소문자, 숫자, 특수문자 개수 저장
    // static int ret[4];   // 반환할 배열 (정적 메모리 할당)
    int i = 0;
    while (str[i] != '\0') // NUll이 나올 때까지 반복 (문자열의 끝)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            result[0]++; // 대문자
        // ++result[0]; // 동일한 의미
        else if (str[i] >= 'a' && str[i] <= 'z')
            // if (str[i] >= 'a' && str[i] <= 'z') 는 부적절
            result[1]++; // 소문자
        else if (str[i] >= '0' && str[i] <= '9')
            result[2]++; // 숫자
        else
            result[3]++; // 특수문자
        i++;
    }
}