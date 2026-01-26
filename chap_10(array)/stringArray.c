#include <stdio.h>

/*
String Array
- String은 문자열이 나열된 배열
- 컴퓨터는 배열이 어디서 끝나는지 알 수 X
-> 배열의 끝을 알리는 신호 필요! => \0 (Null 문자)
- printf는 \0을 만날 때까지 문자 출력
- NULL 포인터와는 다름. null포인터: 주소가 없음 (포인터가 아무것도 가리키지 않음)
*/

// 문자열 길이 구하기
unsigned int ustrlen(char *str);

// 전달받은 문자열 비교
int ustrcmp(char *s1, char *s2);

// src를 dest에 복사
char *ustrcpy(char *dest, char *src);

int main()
{
    char test[] = "apple pear banana orange";

    char *s1 = "Korea";
    char *s2 = "Korea!";

    int cmp = ustrcmp(s1, s2);
    char *result = (cmp > 0) ? "크다" : (cmp < 0 ? "작다" : "같다");

    printf("%s과(와) %s는 %s\n", s1, s2, result);

    char src[] = "I have a dream!";
    // src 데이터를 dest에 복사
    char dest[50];

    ustrcpy(dest, src);
    printf("원본 : %s\n", src);
    printf("복사본 : %s\n", dest);

    return 0;
}

unsigned int ustrlen(char *str)
{
    int len = 0;
    while (1)
    {
        if (str[len] == '\0')
            return len;
        ++len;
    }
}

// 전달받은 문자열 비교
int ustrcmp(char *s1, char *s2)
{
    int i = 0;
    while (1)
    {
        if (s1[i] != s2[i])
            return s1[i] - s2[i]; // 다르면 차이값 반환

        if (s1[i] == '\0')
            return 0; // 두 문자가 같은데, 그게 NULL 문자라면 끝까지 같다.

        ++i;
    }
}

// src를 dest에 문자열 복사
char *ustrcpy(char *dest, char *src)
{
    // 1. 반환할 데이터의 시작주소를 저장
    char *target = dest;

    int i = 0;
    while (1)
    {
        if (src[i] == '\0')
            break;
        dest[i] = src[i]; // destination은 배열이어야 사용가능하다
        i++;
    }

    // dest 마지막 위치에 Null이 없는 상태로 반환
    // 마지막 위치에는 NULL이 꼭 들어가야한다.
    dest[i] = '\0';
}