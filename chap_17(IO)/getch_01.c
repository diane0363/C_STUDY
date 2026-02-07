/*
_getch() 함수
 - 콘솔에서 문자 1개를 입력받는 함수
 - 입력된 문자를 화면에 출력하지 않음(에코 없음)
 - <conio.h> 헤더 파일에 선언되어 있음
 - Windows 전용 함수
*/
#include <stdio.h>
#include <string.h>
#include <conio.h> // _getch() 함수가 선언된 헤더 파일

int main()
{
    char data;

    printf("문자 하나를 입력하세요: ");
    data = _getch(); // Windows 전용 함수로, 입력된 문자를 반환
    printf("\n입력된 문자: %c(%d)\n", data, data);

    return 0;
}