#include <stdio.h>

int main()
{
    int a, b, c, temp;
    printf("1번째 입력:");
    scanf("%d", &a);
    printf("2번째 입력:");
    scanf("%d", &b);
    printf("3번째 입력:");
    scanf("%d", &c);

    // 버블 정렬 로직
    if (a < b)
    {
        temp = a;
        a = b;
        b = temp;
    }

    if (a < c)
    {
        temp = a;
        a = c;
        c = temp;
    }
    if (b < c)
    {
        temp = b;
        b = c;
        c = temp;
    }
    printf("%d %d %d\n", a, b, c);
}