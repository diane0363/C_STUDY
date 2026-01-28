/*
[문제]
n개의 double형 데이터가 전달되었을 때 그 합계를 구하여
반환하는 함수를 작성하고 테스트하는 코드를 작성하시오

함수명 : addDouble
*/

#include <stdio.h>
#include <stdarg.h>

double sumDbl(double args, ...);

int main()
{
    double rst = sumDbl(1.0, 2.0, 3.0);
    printf("sum: %f ", rst);

    return 0;
}

double sumDbl(double args, ...)
{
    // %로 시작하는 아이들을 하나씩 파싱하는 작업을 선행적으로 거친다.
    // fprintf 또한 첫번 파일포인터변수, 문자열, 가변인자 -> 문자열 파싱작업 선행
    va_list al;
    double sum = 0;
    va_start(al, args);
    for (int i = 0; i < args; i++)
    {
        // double num = va_arg(al, double);
        // sum += num;

        sum += va_arg(al, double);
    }
    // printf("sum: %d", sum);
    va_end(al);
    return sum;
}