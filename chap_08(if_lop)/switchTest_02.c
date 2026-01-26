#include <stdio.h>
// 문자 1개를 입력받아 가족을 출력
int main()
{
    // 변수 선언, 입력
    char ch;
    printf("문자 입력:");
    scanf("%d", &ch);

    switch (ch)
    {
    // case가 여러개인 경우 연달아 작성 가능
    case 'F':
    case 'f':
        printf("아버지\n");
        break;
    case 'M':
    case 'm':
        printf("어머니\n");
        break;
    case 'S':
    case 's':
        printf("여자형제\n");
        break;
    case 'B':
    case 'b':
        printf("남자형제\n");
        break;
    default:
        printf("모르는 사람\n");
        break;
    }
}
