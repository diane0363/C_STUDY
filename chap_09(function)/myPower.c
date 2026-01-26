/*
두 개의 값을 전달받아 거듭제곱 연산 결과
*/

#include <stdio.h>
// #include <math.h>  // 해당 라이브러리를 들고와 pow 함수 사용가능

int ipow(int, int);
double fpow(double, int);

int main()
{

    int rst1 = ipow(2, 3);
    double rst2 = fpow(1.2, 3);

    // printf("결과 : %d, %d", rst1, rst2);
    printf("결과 : %d, %0.2lf", rst1, rst2);
    return 0;
}

int ipow(int a, int b)
{
    // int c = a ^ b;  // ^는 XOR 비트 연산자

    int rst = 1;
    int i;

    for (i = 0; i < b; i++)
    {
        rst = rst * a;
        // rst *= a;
    }

    return rst;
}

double fpow(double a, int b)
{
    double rst = 1;
    int i;

    for (i = 0; i < b; i++)
    {
        rst = rst * a;
    }

    return rst;
}