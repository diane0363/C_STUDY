#include <stdio.h>

int main()
{
    // 파일 오픈 -> 파일 포인터 부여 -> 작업 -> 파일 클로즈
    // 1. 파일 열기
    FILE *fp = fopen("./data/rnote01.txt", "rt"); // 읽기 모드로 파일 열기. 텍스트 모드
    if (fp == NULL)
    {
        printf("파일 열기 실패\n");
        return -1;
    }

    // 2. 파일에서 문자 읽기
    int ch;
    while ((ch = fgetc(fp)) != EOF) // 파일 끝까지 문자 읽기
    {
        putchar(ch); // 읽은 문자 출력
    }
    // 3. 파일 닫기
    if (fp != NULL)
    {
        printf("할당받은 디스크립터 번호: %d\n", fileno(fp));
        fclose(fp);
    }

    return 0;
}