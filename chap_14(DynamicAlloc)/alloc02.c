#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CNT 5

int main()
{
    // 난수 seed 설정
    srand(time(NULL));

    int *p;

    p = (int *)malloc(sizeof(4) * CNT); // 20바이트 할당

    // 실제로 4바이트 할당여부를 알 수 없기 때문에
    // NULL pointer로 할당여부 체크하기
    if (p == NULL)
    {
        printf("메모리 할당 실패\n");
        exit(0);
    }

    // 난수를 1~50 사이 발생시켜 초기화한 후 출력
    for (int i = 0; i < CNT; i++)
    {
        // rand() % 50 : 0 ~ 49
        // + 1         : 1 ~ 50
        p[i] = (rand() % 50) + 1;
        printf("%4d ", p[i]); 
    }
    printf("\n");

    free(p); // 제일 에러가 나기 쉽다.
    return 0;
}
