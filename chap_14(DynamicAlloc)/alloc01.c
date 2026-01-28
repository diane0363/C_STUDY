#include <stdio.h>
#include <stdlib.h>

int main()
{
    // void *p;
    int *p;

    // p = malloc(4); // 4바이트
    // p = malloc(sizeof(4)); // 가독성을 위해 sizeof 쓰는 것 추천
    p = (int *)malloc(4); // int로 데이터를 받을 경우 형변환

    // 실제로 4바이트 할당여부를 알 수 없기 때문에
    // NULL pointer로 할당여부 체크하기
    if (p == NULL)
    {
        printf("메모리 할당 실패\n");
        exit(0);
    }

    *p = 25;
    printf("값은 : %d\n", *p);

    free(p); // 제일 에러가 나기 쉽다.
    return 0;
}
