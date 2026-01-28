/*
가변인자 함수
va_list
va_start
va_arg
va_end
*/

#include <stdio.h>
#include <stdarg.h> // 가변인자 함수를만들기 위한 header

void printNumbers(int args, ...)
{
    va_list ap;         // 가변 인자 목록을 가리키는 포인터 선언
    va_start(ap, args); // 포인터 변수와 포인터를 통해 가져올 수 있는 데이터 개수를 함수로 전달
    for (int i = 0; i < args; i++)
    {
        // 리스트로 받은 값들의 타입 va_arg (변수, 타입)
        int num = va_arg(ap, int); // 포인터에서 int크기의 값을 가져오고 포인터를 다음으로 이동
        printf("%d ", num);
    }
    va_end(ap); // 가변 인자 목록 포인터 해제
}

int main()
{
    printNumbers(3, 10, 20, 30);     // 인수 개수 3개
    printNumbers(4, 10, 20, 30, 40); // 인수 개수 4개

    return 0;
}