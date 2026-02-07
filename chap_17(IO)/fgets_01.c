/*
fgets()
char *fgets(char *str, int n, FILE *stream);
 - str : 문자열을 저장할 배열의 주소. 버퍼의 포인터 ?
 - n : 최대 문자 개수 (NULL 문자 포함)
 - stream : 입력 스트림 (표준 입력 : stdin). 문자열을 읽어올 파일 포인터
    -- 기능 : stream으로부터 최대 n-1개의 문자를 읽어 str에 저장.
    -- 읽기를 종료하는 조건
        1) 개행 문자('\n')를 만나면 개행 문자까지 읽고 종료
        2) n-1개의 문자를 읽으면 종료
        3) 파일의 끝(EOF)에 도달하면 종료
 - 반환값 : 성공 시 str의 주소, 실패 시 NULL 포인터 반환
*/
#include <stdio.h>
#include <string.h> // strlen 함수

int main()
{

    char data[10]; // 문자 9개가 Maximum + NULL 문자 ==> 10개 !!!!

    printf("문자열을 입력하세요: ");
    fgets(data, sizeof(data), stdin); // 표준 입력으로부터 문자열을 읽음

    int len = strlen(data); // 문자열의 길이 계산. \0 바로 전까지의 길이 반환
    printf("입력된 문자열의 길이: %d\n", len);

    // 문자가 10개 미만이면 개행문자가 포함되어 있음
    // v2 개행 문자 제거
    // data[strlen(data) - 1] = '\0'; // 개행 문자 제거.

    printf("입력된 문자열: %s\n", data);

    // v1 입출력 결과 예시
    // Hello World! -> Hello Wor (문자열 길이 9)
    // abc -> abc(\n) (문자열 길이 4)

    // v2 입출력 결과 예시
    // Hello World! -> Hello Wo (문자열 길이 9)
    // abc -> abc (문자열 길이 4)

    fputs(data, stdout); // 표준 출력으로 문자열을 출력

    printf("*** 종료! \n");
    return 0;
}