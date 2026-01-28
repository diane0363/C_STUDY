/*
얕은 복사와 깊은 복사
 - 얕은 복사 : 포인터 변수의 값(주소값)만 복사
 - 깊은 복사 : 실제 데이터까지 복사
    -> 동적 메모리 할당을 통해 깊은 복사를 구현
*/

#include <stdio.h>
#include <stdlib.h> // malloc, free
#include <string.h> // memcpy
#define SIZE 5

output(int *ptr);

// 깊은 복사
int main()
{
    int src[] = {1, 2, 3, 4, 5};
    int *dest;

    // 1) 동적 메모리 할당
    // dest = (int *)malloc(sizeof(int) * 5); // 5개의 int 크기만큼 메모리 할당. 원본 배열의 요소 개수
    dest = (int *)malloc(sizeof(int) * SIZE); // #define 사용 가능. 한번에 관리하기 좋다.
    if (dest == NULL)
    {
        printf("메모리 할당 실패\n");
        exit(0);
    }

    // 2) 실제 데이터 복사 (혹은 memcpy 사용 가능)
    // 2-1) for문 사용
    // for (int i = 0; i < 5; i++)
    // {
    //     dest[i] = src[i];
    // }

    // 2-2) memcpy 사용 (메모리 복사 함수. string.h에 선언)
    // memcpy(dest, src, sizeof(int) * 5);
    memcpy(dest, src, sizeof(int) * SIZE);

    printf("원본 : ");
    output(src);

    printf("복사본 : ");
    output(dest);

    // 복사본 변경
    printf("\n...수정...\n");
    dest[2] = 60;

    printf("원본 : ");
    output(src);

    printf("복사본 : ");
    output(dest);

    free(dest);
    return 0;
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