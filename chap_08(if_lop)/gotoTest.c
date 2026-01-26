#include <stdio.h>

int main()
{
    char place = 0;

    printf("s 입력 시 '서울'로 이동\n");
    printf("j 입력 시 '제주'로 이동\n");
    printf("가고싶은 곳의 문자 입력\n");
    scanf("%c", &place);

    if (place == 's')
    {
        goto LABEL_SEOUL;
    }
    else if (place == 'j')
    {
        goto LABEL_JEJU;
    }
    else
    {
        printf("잘못된 입력입니다.\n");
        goto END;
    }

LABEL_SEOUL:
    printf(">>> 서울 도착!\n");
    goto END;

LABEL_JEJU:
    printf(">>> 제주 도착!\n");

END:
    printf("여행 끝!\n");

    return 0;
}