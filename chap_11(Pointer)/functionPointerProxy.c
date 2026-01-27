/*
해당 방식으로 만드는게 귀찮고 복잡해서 만들어진 것이 함수 오버로딩
전달 인자가 다를 경우 등등
*/

#include <stdio.h>

// 함수 선언부
int plus(int, int);
int minus(int, int);
int multiply(int, int);
int modulus(int, int);
int proxy(int, int, int (*ptr)(int, int));

// int (*fptr)(int, int);

int main()
{
    int x = 15, y = 20;

    printf("더하기 %d\n", proxy(x, y, plus));
    printf("빼  기 %d\n", proxy(x, y, minus));
    printf("곱하기 %d\n", proxy(x, y, multiply));
    printf("나머지 %d\n", proxy(x, y, modulus));

    return 0;
}

int proxy(int x, int y, int (*fptr)(int, int))
{
    fptr(x, y);
}

// int proxy(int x, int y, int func(int,int))
// {
//     int (*fptr)(int, int);
//     fptr = func;
//     fptr(x, y);
// }

// int proxy(int x, int y, int func)
// {
//     fptr = func;
//     return fptr(x, y);
// }

int plus(int x, int y)
{
    return x + y;
}
int minus(int x, int y)
{
    return x - y;
}
int multiply(int x, int y)
{
    return x * y;
}
int modulus(int x, int y)
{
    return x % y;
}