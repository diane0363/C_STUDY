/*
copy_03.c
프로그램을 실행하는 시점에 값을 전달 -> main 함수로 전달
int main(int argc, char *argv[])
 - argc : 전달된 값의 개수 (argument count)
 - argv : 전달된 값들이 저장된 배열 (argument vector)
    -- argv[0] : 프로그램 이름
    -- argv[1] : 첫 번째 전달된 값 (원본 파일 이름)
    -- argv[2] : 두 번째 전달된 값 (복사본 파일 이름)
*/

#include <stdio.h>

// int main(int argc, char *argv[]) // char 포인터의 배열
int main(int argc, char **argv) // char 포인터의 포인터
{
    // 전달된 값이 3개인지 확인 (프로그램 이름 + 원본 파일 이름 + 복사본 파일 이름)
    // 스페이스 기준으로 구분. 파일명도 argc에 포함
    printf("아규먼트 개수");
    printf("argc = %d\n", argc);
    printf("argv[0] = %s\n", argv[0]); // 실행할 프로그램 이름
    printf("argv[1] = %s\n", argv[1]); // 원본 파일 이름
    printf("argv[2] = %s\n", argv[2]); // 복사본 파일 이름

    if (argc != 3)
    {
        printf("사용법: %s <원본 파일 이름> <복사본 파일 이름>\n", argv[0]);
        return -1;
    }

    FILE *rp = fopen(argv[1], "rt"); // 원본 파일 열기
    FILE *wp = fopen(argv[2], "wt"); // 복사본 파일 열기

    if (rp == NULL || wp == NULL)
    {
        printf("파일 열기 실패\n");
        return -1;
    }

    int ch;

    while (1)
    {
        ch = fgetc(rp);
        if (ch == EOF)
        {
            break;
        }
        fputc(ch, wp);
    }

    printf("파일 복사 완료\n");

    fclose(rp);
    fclose(wp);

    return 0;
}