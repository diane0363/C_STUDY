/*
call by value : 데이터 전달 시 값 전달
    - argument의 상수값 복사해 전달
    - 피호출 함수 조작으로 값 변경 X
    - arg 데이터와 pmt 변수 데이터 타입은 동일이 일반적
call by reference : 데이터 전달 시 주소 전달
    - arg의 시작 주소 전달 방식
    - 피호출 함수 조작으로 arg값 변경 가능
*/
#include <stdio.h>

void func(int);
int add(int *ptr);
void change(int *ptr);

int main()
{
    // 1. Call By Value 예시 (func 함수)
    int a = 1;
    printf("main 함수 => a 값:%d, a 주소:%p\n", a, &a);
    func(a);

    printf("----------------------------");

    int b = 10;    // INT는 4바이트
    int *ptr = &b; // 포인터ptr. ptr이 가지고 있는 주소가 가지고 있는 대상체의 타입 작성!!
    // ptr은 주소값을 가지고 있음 -> 해당 주소값이 가진 값(int)을 참조
    // 호출하는 쪽이 equal의 오른쪽
    // 참조하는 쪽이 equal의 왼쪽

    // 2. Call by Reference (주소 전달) - 읽기 전용
    // int result1 = add(b);  // call by value (값 10 전달
    int result2 = add(&b); // call by reference

    add(&b);
    printf("main함수 add()의 결과 : %d\n", b); // 읽기

    // 3. Call by Reference (주소 전달) - 쓰기(변경) 발생
    change(&b);
    printf("main함수 change()의 결과 : %d\n", b); // 읽기 + 쓰기
}

void func(int a)
{
    printf("func함수 => a변수 값 : %d, a변수 주소: %p\n", a, &a);
}

// Call By Reference (주소 전달) 방식이지만 값만 참조
int add(int *ptr)
{
    // ptr이 a를 바라보고 있다면 a주소의 값을 추출 (값의 타입은 알아야함..)
    // ptr = @100 -> a100 = 5
    int rst = *ptr + 10; // 읽어옴
    printf("*ptr + 10 = %d\n", rst);
    return 0;
}

// Call By Reference
void change(int *ptr)
{
    *ptr = *ptr + 10; // a 값이 변경
    printf("*ptr + 10 = %d\n", *ptr);
}