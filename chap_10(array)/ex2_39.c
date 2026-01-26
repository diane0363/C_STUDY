/*
버블 정렬, 교환 정렬(오름차순)을 하는 코드를 작성하시오
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CNT 10 // 배열의 크기

void menu();
void init(int *data);
void output(int *data);
void bubbleSort(int *data);
void exchangeSort(int *data);

int main()
{
    int data[CNT];
    char choice;
    while (1)
    {
        menu();
        // \n 전까지 문자를 하나씩 들고와 입력버퍼를 비우는 작업을 한다.
        choice = getchar(); // 입력 버퍼에서 글자 1개를 읽어오는 함수 (입력버퍼(standardin)에 엔터가 남아 다음 입력에 적용된다.)

        // 입력버퍼에 남은 데이터 제거 작업 필요
        // fflush(stdin); // 비권장 방법 ; 시스템에 따라 오작동 가능성 있음
        while (getchar() != '\n')
            ;
        switch (choice)
        {
        case '1':
            init(data); // 초기화 (배열의 이름은 그 배열의 시작주소) // Call by Reference
            break;
        case '2':         // 출력
            output(data); //
            break;
        case '3': // 버블 정렬
            bubbleSort(data);
            break;
        case '4': // 교환 정렬
            exchangeSort(data);
            break;
        case '0': // 종료
            printf("\n ** 프로그램을 종료합니다. ");
            return 0;
        default:
            printf("\n [오류] 잘못된 입력입니다. 다시 선택해 주세요.");
        }
    }
}

// ---- 메뉴 출력
void menu()
{
    printf("--------------\n");
    printf(" 1. 배열 초기화 ");
    printf(" 2. 출       력 ");
    printf(" 3. 버 블 정 렬 ");
    printf(" 4. 교 환 정 렬 ");
    printf(" 0. 종       료 ");
    printf(" >  선   택   : ");
}

// ---- 배열의 값을 난수로 발생시켜 저장하는 함수
// 배열명은 포인터, 즉 주소,,,?
// init 함수로 호출할 때 배열의 이름을 전달하라는 말 ,,!
// 배열의 이름은 그 배열의 시작 주소
void init(int *data)
{
    // srand(time(NULL)); // time(0)과 같은 의미
    srand(time(0));

    // int num;
    for (int i = 0; i < CNT; ++i)
        data[i] = rand() % 100 + 1;
    // num =  // 0 ~ 99 ==> 1 ~ 100

    printf("\n ** 배열 초기화 완료 \n");
}

// 배열의 값 출력하는 함수
void output(int *data)
{
    printf("\n ** 초기화된 배열 ");

    for (int i = 0; i < CNT; ++i)
        printf("%4d\n", data[i]);
}

// ------ 버블 정렬
void bubbleSort(int *data)
{
    printf("## 버블 정렬 중 ... \n");

    int temp = 0;

    for (int i = 0; i < CNT; ++i) /// 비교 차수
    {
        for (int j = 0; j < CNT - 1; ++j)
        {
            if (data[j] > data[j + 1])
            {
                // 실제 비교 후 교체 작업
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

// ------- 교환 정렬
void exchangeSort(int *data)
{
    printf("## 교환 정렬 중 ... \n");

    int temp = 0;

    for (int i = 0; i < CNT - 1; ++i) // 기준 위치 지정 (처음부터 마지막 전까지)
    {
        for (int j = i + 1; j < CNT; ++j) // 비교 대상 ; i를 제외한 나머지
        {
            if (data[j] < data[j])
            {
                // 실제 비교 후 교체 작업
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
};
