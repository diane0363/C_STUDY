/*
구조체 배열을 이용한 회원 관리 프로그램
*/

#include <stdio.h>
#include <string.h>
#define MAX_CNT 5 // 가입 가능한 최대 회원 수

typedef struct Fitness
{
    int id;
    char name[50];
    double height;
    double weight;
    double bmi;
} Fitness;

// 함수 프로토타입
// 매개변수가 없기 때문에 구조체 포인터를 사용하지 않음
void menu();
void input();
void search();
void update();
void deleteMember();
void output();

Fitness member[MAX_CNT]; // 전역 변수로 선언된 회원정보를 저장하기위한 구조체 배열
static int last = 0;     // 현재 저장된 회원 수
static int memno = 0;    // 회원 번호

int main()
{
    char choice;
    while (1)
    {
        menu();
        printf("메뉴 선택: ");
        scanf(" %c", &choice); // %c 앞에 공백을 넣어 이전 입력의 개행문자 제거 (버퍼 비우기)

        switch (choice)
        {
        case '1':
            input();
            break;
        case '2':
            search();
            break;
        case '3':
            update();
            break;
        case '4':
            output();
            break;
        case '5':
            deleteMember();
            break;
        case '0':
            printf("프로그램 종료\n");
            return 0;
        default:
            printf("잘못된 선택입니다. 다시 시도하세요.\n");
        }
    }
}

void menu()
{
    printf("\n=== 회원 관리 프로그램 ===\n");
    printf("1. 회원 등록 (Create)\n");
    printf("2. 회원 검색 (Read)\n");
    printf("3. 회원 정보 수정 (Update)\n");
    printf("4. 회원 목록 출력 (Read All)\n");
    printf("5. 회원 삭제 (Delete)\n");
    printf("0. 종료 (Exit)\n");
}
void input()
{
    if (last >= MAX_CNT)
    {
        printf("더 이상 회원을 등록할 수 없습니다.\n");
        return;
    }
    // last(현재 회원수), memno(회원번호)
    memno++; // 회원 아이디 증가
    member[last].id = memno;

    printf("이름 입력: ");
    scanf("%s", member[last].name);

    printf("키 입력 (cm): ");
    scanf("%lf", &member[last].height);

    printf("몸무게 입력 (kg): ");
    scanf("%lf", &member[last].weight);

    // BMI 계산
    double h_tmp = member[last].height / 100.0; // cm를 m로 변환
    member[last].bmi = member[last].weight / (h_tmp * h_tmp);
    // member[last].bmi = member[last].weight / ((member[last].height / 100) * (member[last].height / 100));

    last++; // 회원 수 증가

    printf("회원 등록이 완료(ID : %d)\n", member[last - 1].id);
}
void search()
{
    printf("\n=== 회원 검색 ===\n");

    if (last == 0)
    {
        printf("등록된 회원이 없습니다.\n");
        return;
    }

    char s_name[50];
    printf("검색할 이름 입력: ");
    scanf("%s", s_name);

    // int found = 0; // 검색된 회원 수

    for (int i = 0; i < last; i++)
    {
        if (strcmp(member[i].name, s_name) == 0) // 이름이 일치하는 경우 // strcmp는 같으면 0 반환
        {
            printf("ID: %d | 이름: %s | 키: %.2f cm | 몸무게: %.2f kg | BMI: %.2f\n",
                   member[i].id, member[i].name, member[i].height, member[i].weight, member[i].bmi);
            // found++;
            return; // 첫번째 검색된 회원만 출력하고 종료
        }
    }
    printf("검색 결과가 없습니다.\n");
}
void update() {}
void deleteMember()
{
    // 삭제할 회원 ID 입력

    // 삭제한 자리를 이후 회원들로 채우기 (한 칸씩 앞으로 당기기)
    printf("\n=== 회원 삭제 ===\n");
}
void output()
{

    printf("\n=== 회원 목록 출력 ===\n");

    if (last == 0)
    {
        printf("등록된 회원이 없습니다.\n");
        return;
    }

    printf("\n ID  이름                   키(cm)    몸무게(kg)   BMI\n");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < last; i++)
    {
        printf("%3d  %-20s  %8.2f  %10.2f  %6.2f\n",
               member[i].id, member[i].name, member[i].height, member[i].weight, member[i].bmi);
    }
}
