/*
얕은 복사와 깊은 복사
 - 얕은 복사 : 포인터 변수의 값(주소값)만 복사
 - 깊은 복사 : 실제 데이터까지 복사
    -> 동적 메모리 할당을 통해 깊은 복사를 구현
*/

#include <stdio.h>

output(int *ptr);

// 얕은 복사
int main()
{
    int src[] = {1, 2, 3, 4, 5};
    int *dest;

    dest = src; // 얕은 복사 : 주소값만 복사

    printf("원본 : ");
    output(src);

    printf("복사본 : ");
    output(dest);

    // 복사본 변경
    printf("...수정...\n");
    dest[2] = 60;

    printf("원본 : ");
    output(src);

    printf("복사본 : ");
    output(dest);

    free(dest);
    return 0; // 프로그램이 정상 종료되었음을 운영체제에 알림
}

output(int *ptr)
{
    for (int i = 0; i < 5; i++)
    {
        // printf("%d ", *(ptr + i));
        printf("%d ", ptr[i]);
    }
    printf("\n");
}