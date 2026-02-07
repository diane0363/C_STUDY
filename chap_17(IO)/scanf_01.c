#include <stdio.h>

int main()
{
    int a, b, c;

    printf("정수 3개를 입력하세요: ");
    int result = scanf("%d %d %d", &a, &b, &c);

    printf("입력된 정수는 %d, %d, %d입니다.\n", a, b, c);
    printf("scanf 함수의 반환값은 %d입니다.\n", result);

    printf("테스트1====================\n");
    test();

    return 0;
}

int test()
{
    int a = 10, b = 20, c = 30;

    int result = printf("데이터 출력");
    int result2 = printf("abc\n");

    printf("출력 결과 = %d\n", result);
    printf("출력 결과 = %d\n", result2);

    result = printf("a=%d, b=%d, c=%d\n", a, b, c);
    printf("출력 결과 = %d\n", result);

    return 0;
}