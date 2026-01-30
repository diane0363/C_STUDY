#include <stdio.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL)); // 난수 시드 설정
    int *ip;
    int col_1, col_2;

    printf("몇 개를 할당할까요? ");
    scanf("%d", &col_1);

    // 초기 메모리 할당
    ip = (int *)malloc(col_1 * sizeof(int));

    for (int i = 0; i < col_1; i++)
    {
        ip[i] = rand() % 100;              // 0~99 사이의 난수 생성
        printf("ip[%d] = %d\n", i, ip[i]); // 할당된 메모리 출력
    }

    printf("몇 개로 늘릴까요? ");
    scanf("%d", &col_2);

    // 메모리 추가 할당
    ip = (int *)realloc(ip, (col_1 + col_2) * sizeof(int));
    for (int i = col_1; i < col_1 + col_2; i++)
    {
        ip[i] = rand() % 100;                                   // 0~99 사이의 난수 생성
        printf("추가로 할당된 메모리 ip[%d] = %d\n", i, ip[i]); // 추가된 메모리 출력
    }

    // 전체 메모리 출력
    printf("전체 메모리 출력:\n");
    for (int i = 0; i < col_1 + col_2; i++)
    {
        printf("ip[%d] = %d\n", i, ip[i]);
    }

    free(ip); // 할당된 메모리 해제
    return 0;
}