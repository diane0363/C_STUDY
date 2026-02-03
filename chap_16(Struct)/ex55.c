/*
아래 제공된 함수 Prototype을 참고
다양한 타입의 데이터를 정렬하는 프로그램 작성
int, double, 문자열 등 모든 데이터를 정렬해 출력하는 정렬함수 구현
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // malloc, free 사용 위해 필요

// mySort(정렬할 실제 데이터, 데이터 개수, 데이터 크기, 비교 함수 포인터)
// 마지막 매개변수는 함수 포인터 -> Compare함수 호출
void mySort(void *p, int count, size_t size, int (*dataCompare)(void *, void *));
void output(void *, int, size_t, void (*)(void *));

// 정렬을 위한 비교 함수들
// 퀵정렬이든 버블 정렬이든 비교함수 필요
// void 포인터를 쓴 이유? -> 다양한 타입을 받기 위해
// 프록시 함수 (대리) 필요
// int (*dataCompare)(void *, void *) 때문 -> 함수 포인터
int integerCompare(void *, void *);
int doubleCompare(void *, void *);
// strcmp 필요하다!!?!
int stringCompare(void *, void *);

void integerPrint(void *);
void doublePrint(void *);
void stringPrint(void *);

// 메인 함수 -------------------------------------------------
int main()
{
    // 정수 배열
    printf("=== 정수 배열 정렬 ===\n");
    int iArray[10] = {5, 2, 9, 1, 5, 6, 3, 7, 8, 4};
    // 정수 정렬 (int *, 요소개수, 요소 하나의 크기, 정렬 수행 함수명)
    mySort(iArray, sizeof(iArray) / sizeof(iArray[0]), sizeof(iArray[0]), integerCompare);
    output(iArray, sizeof(iArray) / sizeof(iArray[0]), sizeof(iArray[0]), integerPrint);
    printf("\n");

    // 실수 배열
    printf("=== 실수 배열 정렬 ===\n");
    double dArray[5] = {3.1, 2.4, 5.6, 1.2, 4.8};
    mySort(dArray, sizeof(dArray) / sizeof(dArray[0]), sizeof(dArray[0]), doubleCompare);
    output(dArray, sizeof(dArray) / sizeof(dArray[0]), sizeof(dArray[0]), doublePrint);
    printf("\n");

    // 문자열 배열
    printf("=== 문자열 배열 정렬 ===\n");
    char sArray[5][20] = {"바나나", "사과", "오렌지", "파인애플", "귤"};
    // 문자는 메모리의 요소 개수가 다르다. 바나나의 경우 7byte
    mySort(sArray, sizeof(sArray) / sizeof(sArray[0]), sizeof(sArray[0]), stringCompare);
    output(sArray, sizeof(sArray) / sizeof(sArray[0]), sizeof(sArray[0]), stringPrint);
    printf("\n");

    return 0;
}

// 함수 정의 -------------------------------------------------
// 정수형 (iArray     10     4    integerCompare)
// 실수형 (dArray     5      8    doubleCompare)
// 문자열 (sArray     5     20    stringCompare)
void mySort(void *p, int count, size_t size, int (*dataCompare)(void *, void *))
{
    // 교환 정렬 (버블 정렬)
    // 이중 for문이 필요

    int i, j;

    // string 교환을 위한 임시 변수
    void *tmp = malloc(size);

    // 교환 정렬을 이용해서 정렬 (하나를 고정시켜서 나머지와 비교)
    for (i = 0; i < count - 1; i++)
    {
        for (j = i + 1; j < count; j++)
        {
            // 비교 함수 호출
            // if( iArray[i] > iArray[j] ) 불가능. iArray가 void 포인터이기 때문에??
            // 실제비교작업은 dataCompare 함수가 수행
            // 0보다 크면 자리 교환. -> 오름차순 정렬
            // 데이터를 가리키고 있는 p포인터!
            // 받을 데이터 타입이 달라서 char*로 형변환
            // char*는 1byte 단위로 모든 데이터 접근 가능 -> size만큼 곱해서 접근
            // int* 의 경우 (char*)p + i * size -> (int*)p + i
            if (dataCompare((char *)p + i * size, (char *)p + j * size) > 0)
            {
                // 메모리를 덤프해서 복사 -> memcpy
                // memcpy(목적지, 출처, 크기);
                // 복사 대상의 실제 바이트는 신경 쓰지 않음
                // 교환 작업
                // 1. tmp = p[i]
                // 2. p[i] = p[j]
                // 3. p[j] = tmp
                memcpy(tmp, (char *)p + i * size, size);
                memcpy((char *)p + i * size, (char *)p + j * size, size);
                memcpy((char *)p + j * size, tmp, size);
            }
        }
    }
    free(tmp);

    // int *p1 = (int *)p; // 정수형 포인터로 형변환

    // if (*(int *)p == *(int *)p)
    // {
    //     printf("정수 정렬\n");
    // }
    // else if (*(double *)p == *(double *)p)
    // {
    //     printf("실수 정렬\n");
    // }
    // else
    // {
    //     printf("문자열 정렬\n");
    // }
}
// size_t 는 부호 없는 정수형??? 구조체 페이지 참고하기
void output(void *p, int count, size_t size, void (*dataPrint)(void *))
{
    for (int i = 0; i < count; i++)
    {
        dataPrint((char *)p + i * size);
        printf("\n");
    }
}

//  정수 비교 함수, 출력 함수 -------------------------------------------------
int integerCompare(void *p1, void *p2)
{
    return *(int *)p1 - *(int *)p2;
}

void integerPrint(void *p)
{
    printf("%5d ", *(int *)p);
}

// 실수 비교 함수, 출력 함수 -------------------------------------------------
int doubleCompare(void *p1, void *p2)
{
    // doubleCompare이 정수형 반환
    // 만약 수의 차이가 소수로 나온다면 Truncation 발생
    // 3.1 - 2.4 = 0.7 -> 0 반환 => 같음으로 처리 (자리 교환 안됨)
    // 그래서 아래와 같은 코드 사용 불가
    // return *(double *)p1 - *(double *)p2;

    // 그렇다고 double형 반환도 안됨 -> 함수 프로토타입이 int형 반환으로 되어 있기 때문
    // 그리고 표준 라이브러리의 비교 함수들도 int형 반환!! 정수를 기대한다.
    // CPU 입장에서도 정수 비교가 더 빠름. 정수연산 최적화
    // 또한 부동 소수점 연산은 오차 발생 가능성 존재

    double num1 = *(double *)p1;
    double num2 = *(double *)p2;

    if (num1 > num2)
        return 1; // 교환 대상
    else if (num1 < num2)
        return -1;
    else
        return 0;
}

void doublePrint(void *p)
{
    printf("%7.2lf ", *(double *)p);
}

// 문자열 비교 함수, 출력 함수 -------------------------------------------------
int stringCompare(void *p1, void *p2)
{
    return strcmp((char *)p1, (char *)p2);
}

void stringPrint(void *p)
{
    printf("%s ", (char *)p);
}