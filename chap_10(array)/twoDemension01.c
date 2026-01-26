#include <stdio.h>

// 1) 배열의 이름은 그 배열의 시작주소이다
// 2) 문자열은 문자열의 시작주소이다
// 3) 함수의 이름은 그 함수의 시작주소이다

// 2차원 배열인 경우 전달 인자를 어떻게 사용하는가?
// 배열을 함수로 받으려면 포인터를 사용해야한다.
// int **ptr 아님!! 정확한 표현 XX
// int **ptr은 두 번 참조하면 integer값을 만날 수 있다! 라는 뜻
// *ptr은 1차원(한번 참조) **ptr은 2차원(두번 참조)

// 2차원 배열을 가리키는 포인터 변수
// ptr은 배열이 아니라 포인터여서,,
// 2차원 포인터 변수를 함수의 매개변수로 받아서 어쩌고,,,,
// [4]가 중요하다는데,,,?
// void output(int ptr[3][4]) warning 이 뜬다. . .

// 함수 포인터 선언 방식
// ptr은 자신이 가리키는 요소의 첫번째 한개를 정확히 가르치면 된다.
// 1) (*ptr) => ptr은 포인터 변수! 포인터 변수 지정을 제일 먼저 해야해서 ()필수
// 2) int[4] ptr이 가르키는 대상 : 1차원 배열, 행은 필요X
// 3) 행 정보X, 4열의 2차원 배열을 가리키는 것
// 실제로는 int 배열 4행 짜리가 3개가 있다.
// 하지만 행 정보를 알려주는 것은 개발자가 알아서 해야한다.
void output(int (*ptr)[4])
{
    printf("output 함수 내 작업\n");
    printf("3행 4열 int 배열의 size: %d\n", sizeof(ptr));
    // 0행의 사이즈
    printf("3행 4열 int 배열의 ary[0] size: %d\n", sizeof(ptr[0]));
    // 실제 integer 하나의 사이즈
    printf("3행 4열 int 배열의 ary[0][0] size: %d\n", sizeof(ptr[0][0]));
}

int main()
{
    int ary[3][4];
    // printf("3행 4열 배열의 size: %d\n", ary);    // 배열의 이름은 배열의 시작주소
    printf("3행 4열 int 배열의 size: %d\n", sizeof(ary));                 // 48
    printf("3행 4열 int 배열의 ary[0] size: %d\n", sizeof(ary[0]));       // 한 행의 size, 16
    printf("3행 4열 int 배열의 ary[0][0] size: %d\n", sizeof(ary[0][0])); // 4

    output(ary);

    return 0;
}