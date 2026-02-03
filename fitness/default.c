/*
구조체 배열을 이용한 회원 관리 프로그램
*/

#define MAX_CNT 5; // 가입 가능한 최대 회원 수

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

Fitness member[MAX_CNT];
static int last = 0;  // 현재 저장된 회원 수
static int memno = 0; // 회원 번호