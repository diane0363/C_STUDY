#include <stdio.h>
// 평균 점수에 따라 학점 부여
// a = (k + e + m) / 3.0
// 90점대 : A, 80점대 : B,

int main()
{
    int k = 90, m = 88, e = 78;
    // double a = (k + m + e) / 3.0;
    // printf("%lf\n", a);
    printf("%d\n", ((k + m + e) / 3) / 10);

    switch (((k + m + e) / 3) / 10)
    {
    case 9:
        printf("A\n");
        break;
    case 8:
        printf("B\n");
        break;
    case 7:
        printf("C\n");
        break;
    case 6:
        printf("C\n");
        break;
    }

    return 0;
}