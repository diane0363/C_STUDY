/*
    배열을 함수로 전달할 경우
*/
#include <stdio.h>

// 어떻게 매개변수를 처리할 것인가?
// 1차원 정수형 배열
// 차원과 타입이 같으면 된다. ******
void func1(int *ptr);
// (*ptr) 괄호가 굉장히 중요하다! 괄호가 없으면 의미가 달라짐
// int 방 4개 짜리를 가리켜라,,
void func2(int (*ptr)[4]);
void func3(int (*ptr)[3][2]);
void func4(int (*ptr)[3][2]);

int main()
{

    int ary1[] = {1, 2, 3, 4, 5}; // size of ary1 ==> 4byte * 5개

    func1(ary1);     // ary1의 첫번째 요소 크기가 얼마정도인가
    func1(&ary1[0]); // 이것과 동일한 표현

    int ary2[3][4] = {1, 2, 3, 4};                      // 남은 부분은 0으로 채워짐 -> 3행 4열 중 1행만 채운 것
    int ary3[][3][2] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // ary3의 한 덩어리는? - 처음에 2개씩 묶고 3덩어리를 묶으면 알 수 있다.
    // {{{1,2},{3,4},{5,6}},{{7,8},{9,10},{0,0}}}
    /*
    ary3은 몇개로 구성이 되었는가?
    한 덩어리가 int[3][2] ==> 이런 덩어리가 두개 있움
    */

    /*
    ary2의 한 덩어리 : integer 방 4개짜리가 한 덩어리
    */
    func2(ary2); // int[4] * 3

    func4(ary3); // ary3은 3차원 배열

    // void func4(int ***ptr) {} // 차원은 맞음. 하지만 타입 오류  -> 이렇게 쓰면 안 된다~!~

    // 어떤 형태로 만들어져있는지 정확히 표기

    return 0;
}

// 어떻게 매개변수를 처리할 것인가?
// 1차원 정수형 배열
// 차원과 타입이 같으면 된다. ******
void func1(int *ptr)
{
    for (int i = 0; i < 5; ++i)
        printf("%d ", ptr[i]);

    printf("\n");
}

// (*ptr) 괄호가 굉장히 중요하다! 괄호가 없으면 의미가 달라짐
// int 방 4개 짜리를 가리켜라,,
void func2(int (*ptr)[4])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 4; ++j)
            printf("%d ", ptr[i][j]);
        printf("\n");
    }

    printf("\n");
}

void func3(int (*ptr)[3][2])
{
}
void func4(int (*ptr)[3][2]) {}
