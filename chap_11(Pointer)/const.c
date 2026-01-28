#include <stdio.h>

int main()
{
    const int a = 10;
    int b;
    print("%d\n", a);
    print("%d\n", a + 1); // 가능
    // print("%d\n", a++); // 불가능
    b = a; // 가능
    // a = 20;             // 불가능
    // return 0;

    // ------------
    // 포인터 대상이 const 화 되는 경우. 참조하는 값 수정 불가
    const int *p;  
    int abc = 7;        // abc는 스스로 상수 변수인지 모름
    p = &abc;
    // *p -= 10;        // 불가능
    abc -= 10;          // 가능 

    // 포인터 변수가 const화 되는 경우. 주소 값 수정 불가
    int abc[3] = {10, 20, 30};
    int *const p1 = abc;
    printf("%d\n", *p1);
    printf("%d\n", ++*p1);      // p1이 가리키는 값을 증가 -> 가능

    // printf("%d\n", *++p1);  // p1을 증가시켜서 (주소 변경) 해당 값을 가져옴 -> 불가능

    return 0;
}