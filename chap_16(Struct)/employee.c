/*
문제 55?
void input(Employee *e); // 키보드로 데이터 입력받아 구조체 초기화
void output(Employee *e); // 구조체 데이터 출력
void output(Employee* e); // 이거랑은 무슨 차이?
*/

#include <stdio.h>  // printf, scanf 사용 위해 필요
#include <string.h> // strcpy 사용 위해 필요

typedef struct
{
    char name[20];
    char phone[30];
    int salary;
} Employee;

void input(Employee *e);
void output(Employee *e);

int main()
{
    Employee e;

    input(&e);
    output(&e);

    return 0;
}

void input(Employee *e)
{
    // 포인터 는 날아가 ?
    // 구조체 멤버는 날아가지 않음,,?

    // 임시 변수 사용, 입력받기 위한 변수 (완충 역할)
    // stack 영역에 생성 -> 중괄호 내에서만 유효
    char name[20];
    char phone[30];
    int salary;

    printf("이름 입력: ");
    scanf("%s", name);

    printf("전화번호 입력: ");
    scanf("%s", phone);

    printf("급여 입력: ");
    scanf("%d", &salary);

    // 구조체 멤버에 값 복사
    strcpy(e->name, name);   // e->name = name; 안되는 이유?
    strcpy(e->phone, phone); // 첫번째 name은 구조체 멤버, 두번째 name은 임시 변수
    e->salary = salary;      // 일반 변수이므로 대입 가능 (equal 사용 가능)

    // printf("이름 입력: ");
    // scanf("%s", e->name);
    // printf("전화번호 입력: ");
    // scanf("%s", e->phone);
    // printf("급여 입력: ");
    // scanf("%d", &e->salary);
}

void output(Employee *e)
{
    printf("이름 : %s, 전화번호 : %s, 급여 : %d\n", e->name, e->phone, e->salary);
}