#include <stdio.h>

int main(void)
{
    void *p;

    int intArray[5] = {1, 2, 3, 4, 5};
    double doubleArray[2][3] = {{1.5, 2.5, 3.5}, {4.5, 5.5, 6.5}};    // 값 하나가 모두 8바이트
    char *charPrtArray[4] = {"apple", "pear", "banana", "pineapple"}; // 2차원!! 헷갈리지 말기~
    // 가리키는 순간 4바이트 int형이라는 것을 인지

    p = intArray; // void형 포인터 p는 int형 1차원 배열을 가리킬 수 있고
    printf("%d\n", *((int *)p + 2));
    // p의 데이터 타입은 int* (일차원 배열을 가리키고 있기 때문에)
    // +2 이는 단순 정수 2가 아니라 첨자 (두 칸 옆 방)
    // P가 100번지라면 108번지

    p = doubleArray; // double형 2차원 배열을 가리킬 수도 있으며
    printf("%lf\n", *(*((double (*)[3])p + 1) + 2));
    // p는 포인터 변수이며 가리키는 대상체 하나가 double형 3열짜리다
    // 포인터 배열을 가리키는 포인터이기 때문에 (*) 괄호 필수!! 인거 맞게찌??
    // + 1 은 다음 행으로 넘어감 *로 차원이 낮아짐 +2로 두 칸 옆 방(열 이동)의 * 데이터 추출
    // + 1 => FLOAT(8BYTE) * 3 * 1만큼 이동
    // + 2 => FLOAT(8BYTE) * 2 만큼 이동
    // 1행 2열의 데이터 ! 즉 6.5가 출력된다.

    p = charPrtArray; // char * 배열을 가리킬 수도 있다
    printf("%s\n", *((char **)p + 2));
    // p는 두번 참조 했을 때 캐릭터형을 가져오는 변수
    // 두칸 옆방의 데이터 출력
    // banana 출력
    // %는 null이 나올 때까지 출력
}
