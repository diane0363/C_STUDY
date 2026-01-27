#include <stdio.h>

int main()
{
    void *arr[3]; // 배열이냐 포인터냐,, 그것은 바로,,! 배열!

    int a = 100;
    float b = 20.5;
    char *c = "Hello";

    // 배열에 주소 저장
    arr[0] = &a;
    arr[1] = &b;
    arr[2] = &c;

    // 포인터 배열 값 추출
    printf("Integer: %d\n", *((int *)arr[0]));  // 100
    printf("Float: %f\n", *((float *)arr[1]));  // 20.50000
    printf("String: %s\n", *((char **)arr[2])); // Hello
}