/*
auto : 지역 변수 (auto.c)
*/

#include <stdio.h>
int main()
{
    auto int a = 1;         // 지역 변수 선언, 스택에 처음 저장
    printf("a =% d Wn", a); // 1
    {
        int a = 2;              // 블록 내부에 같은 이름의 지역 변수 선언, 스택 두 번째 저장
        printf("a =% d Wn", a); // 2
        {
            a += 1;
            printf("a =% d Wn", a); // 3
        }
        printf("a =% d Wn", a); // 3
    } // 블록 종료, 내부 지역 변수 소멸
    printf("a =% d Wn", a); // 1

    return 0;
}