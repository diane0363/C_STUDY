/*
함수 포인터의 사용
*/

#include <stdio.h>

int plus(int, int);
int minus(int, int);

int main()
{
    int x = 10, y = 20, result;
    int (*fptr)(int, int); // 함수 포인터 변수

    fptr = plus;
    printf("plus 함수 주소 : %p\n", plus);

    printf("plus 함수 실행 결과: %d\n", plus(x, y));
    printf("fptr로 대리로 함수 실행 결과: %d\n", fptr(x, y));

    fptr = minus;
    printf("minus 함수 주소 : %p\n", minus);

    printf("minus 함수 실행 결과: %d\n", minus(x, y));
    printf("fptr로 대리로 함수 실행 결과: %d\n", fptr(x, y));

    return 0;
}

int plus(int x, int y)
{
    return x + y;
}
int minus(int x, int y)
{
    return x - y;
}
/*
    문자열은 주소다
    배열명은 주소다
    함수명은 주소다!
*/
