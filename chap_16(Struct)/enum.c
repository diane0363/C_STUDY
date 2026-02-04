#include <stdio.h>

typedef enum DayOfWeek
{
    SUN,
    MON,
    TUE,
    WED,
    THU,
    FRI,
    SAT
} DayOfWeek;

int main()
{
    DayOfWeek today = WED;
    char *result;
    switch (today)
    {
    case SUN:
        result = "일요일";
        break;
    case MON:
        result = "월요일";
        break;
    case TUE:
        result = "화요일";
        break;
    case WED:
        result = "수요일";
        break;
    case THU:
        result = "목요일";
        break;
    case FRI:
        result = "금요일";
        break;
    case SAT:
        result = "토요일";
        break;
    default:
        result = "알 수 없는 요일";
    }
    printf("오늘은 %s입니다.\n", result);

    DayOfWeek tomorrow = (today + 1) % 7;   // 다음 요일 계산
    printf("내일은 %d입니다.\n", tomorrow); // 숫자로 출력

    return 0;
}