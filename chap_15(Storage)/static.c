/*
정적 저장 클래스(static storage class)
- 함수가 호출될 때마다 초기화되지 않고, 프로그램이 종료될 때까지 값이 유지됨
- 데이터 영역(data segment)에 저장됨
*/

#include <stdio.h>

void sub();

int main()
{
    int i; // 자동 저장 클래스, 스택 메모리, 블록 종료 시 소멸
    for (i = 0; i < 3; i++)
        sub();
    printf("main i = % d Wn", i);
    return 0;
}

void sub()
{
    static int i = 1;                              // 정적 저장 클래스, 데이터 영역에 저장, 프로그램 종료 시 소멸
    auto int k = 3;                                // 스택 메모리, 괄호가 사라지면 소멸
    printf("sub i = % d Wt k = % d Wt", i++, k++); // i는 호출될 때마다 값이 유지, k는 매번 3으로 초기화
}