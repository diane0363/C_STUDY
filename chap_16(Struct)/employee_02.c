/*
구조체 배열을 이용한 회원 관리 프로그램
- 입력 함수와 출력 함수로 분리
- 구조체 배열을 매개변수로 전달
- 5명 직원을 한번에 입력 받고 출력
*/

#include <stdio.h>
#include <string.h>
#define MAX_CNT 5 // 가입 가능한 최대 회원 수

typedef struct Employee
{
    char name[20];
    char phone[30];
    int salary;
} Employee;

// 함수 프로토타입
// 매개변수가 없기 때문에 구조체 포인터를 사용하지 않음
void input(Employee *e);
void output(Employee *e);

int main()
{
    Employee e[MAX_CNT];

    input(e);
    output(e);

    return 0;
}

void input(Employee *e)
{
    // 임시 변수 사용, 입력받기 위한 변수 (완충 역할)
    // stack 영역에 생성 -> 중괄호 내에서만 유효
    // [[name][phone][salary]] 5개씩
    char name[20];
    char phone[30];
    int salary;

    printf("\n=== 직원 정보 입력 ===\n");
    for (int i = 0; i < MAX_CNT; i++)
    {
        printf("이름 입력: ");
        scanf("%s", name);

        printf("전화번호 입력: ");
        scanf("%s", phone);

        printf("급여 입력: ");
        scanf("%d", &salary);

        // 구조체 멤버에 값 복사
        strcpy(e[i].name, name);
        strcpy(e[i].phone, phone);
        e[i].salary = salary;
    }
}

void output(Employee *e)
{
    printf("\n=== 직원 정보 출력 ===\n");
    for (int i = 0; i < MAX_CNT; i++)
    {
        printf("이름 : %s, 전화번호 : %s, 급여 : %d\n", e[i].name, e[i].phone, e[i].salary);
    }
}