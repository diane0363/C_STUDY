/*
copy_01.c
파일을 열어 fgetc로 읽은 문자를 fputc로 다른 파일에 복사하는 예제

*/

#include <stdio.h>

int main()
{
    FILE *rp = fopen("./data/rnote02.txt", "rt"); // 읽기 모드로 파일 열기
    FILE *wp = fopen("./data/wnote02.txt", "wt"); // 쓰기 모드로 파일 열기

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