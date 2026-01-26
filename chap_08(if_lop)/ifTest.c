/*
[문제] 놀이동산에 놀러간 가족들의 입장료를 계산

(조건)
기본 입장료 (성인) 15,000
어린이, 노인 10% 할인

(요금)
인원은 몇명 ? ..
어린이? ..
노인? ..

총 요금은 xxx 입니다.
*/
#include <stdio.h>

int main()
{
    int ppl, jnr, snr;

    printf("인원은 몇 명?");
    scanf("%d", &ppl);
    printf("어린이?");
    scanf("%d", &jnr);
    printf("노인?");
    scanf("%d", &snr);

    int adt = ppl - jnr - snr;

    if (adt < 0)
    {
    }
    else
    {
        float total = (jnr + snr) * 15000 * 0.9 + (ppl - jnr - snr) * 15000;
        printf("%d", total);
    }
 
}