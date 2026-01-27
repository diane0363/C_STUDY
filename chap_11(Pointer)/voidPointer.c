/*
void pointer의 형 변환
*/
#include <stdio.h>

int main()
{

    int a = 10;
    char b = 'x';

    void *ptr = &a; // 어떤 타입의 데이터든 주소 추출 가능

    // Void Pointer로부터 값을 가져오려면 적절하게 형변환을 해야 한다.
    // (int *)ptr ; void 주소 500번지가 참조하는 int주소 출력
    // *((int*)(ptr)) ; int 주소의 값 출력
    printf("Void Pointer가 가리키는 값: %d\n", *((int *)(ptr)));

    ptr = &b;
    printf("Void Pointer가 가리키는 값: %c\n", *((char *)(ptr)));
    return 0;
}
