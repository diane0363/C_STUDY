// 좌표의 분면 확인하기
#include <stdio.h>

int main()
{
    int a, b, res;
    printf("x좌표입력: ");
    // &는 변수앞에서 주소 추출을 해준다.
    scanf("%d", &a);
    printf("y좌표입력: ");
    scanf("%d", &b);

    if (a > 0)
    {
        if (b > 0)
            res = 1;
        else if (b < 0)
            res = 2;
    }
    else
    {
        if (b < 0)
            res = 3;
        else if (b > 0)
            res = 4;
    }

    printf("좌표 (%d,%d)는 %d분면에 있다.", a, b, res);
}