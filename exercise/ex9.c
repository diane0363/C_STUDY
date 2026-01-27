/*
    [문제] 한달치 달력 구하기
    1) 윤년 구하는 함수
    2) 총 날 수 구하는 함수
    3) 특정 연도의 특정 달의 1일이 무슨 요일인가?
*/

/**************************************
    전달받은 연도가 평년인가 윤년인가
***************************************/

#include <stdio.h>
#include <conio.h> // 맥에서는 사용X 윈도우 전용
#include <windows.h>

int isLeapYear(int year);               // 윤년 구하는 함수
long totalDays(int year, int month);    // 총 날수 구하는 함수
void titleDisplay(int year, int month); //
void dateDisplay(int year, int month);  //
void gotoxy(int x, int y);

// 평년
int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    int year = 2026, mon = 1, dayOfWeek, datecnt;
    long totalDate; // 총 날수를 저장하는 변수

    // totalDate =

    return 0;
}

// ------------ 윤년 구하기 -----------------
int isLeapYear(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return 1; // 윤년
    else
        return 0; // 평년
}

// ------------- 총 날 수 구하는 함수 --------------------
