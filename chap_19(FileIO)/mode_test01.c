#include <stdio.h>

int main()
{
    FILE *p1 = fopen("./data/mode1.txt", "rt");
    if (p1 == NULL)
    {
        printf("파일 열기 실패\n");
        return -1;
    }

    int result = fgetc(p1);
    printf("읽은 문자: %c\n", result);

    // ======= 쓰기 모드로 파일 열기 =======
    FILE *p2 = fopen("./data/mode2.txt", "wt");
    if (p2 == NULL)
    {
        printf("파일 열기 실패\n");
        return -1;
    }
    fputc('A', p2);
    fputc('B', p2);
    fputc('C', p2);
    fclose(p2);

    // ======= 다시 읽기 모드로 열기 =======
    p2 = fopen("./data/mode2.txt", "rt");
    if (p2 == NULL)
    {
        printf("파일 열기 실패\n");
        return -1;
    }
    result = fgetc(p2);
    printf("읽은 문자: %c\n", result);
    fclose(p2);
    printf("성공!\n");

    // ======= at : 추가 모드로 열기 =======
    FILE *p3 = fopen("./data/mode3.txt", "at");
    if (p3 == NULL)
    {
        printf("파일 열기 실패\n");
        return -1;
    }
    fputc('X', p3);
    fputc('Y', p3);
    fputc('Z', p3);
    fclose(p3);
    printf("추가 모드 쓰기 성공!\n");

    // ======= r + t : 파일 읽기 및 쓰기 모드로 열기 =======
    FILE *p4 = fopen("./data/mode4.txt", "r+t");
    if (p4 == NULL)
    {
        printf("파일 열기 실패\n");
        return -1;
    }
    result = fgetc(p4);
    printf("읽은 문자: %c\n", result);
    fputc('M', p4); // 파일의 현재 위치에 문자 'M' 쓰기
    fclose(p4);

    fcloseall();
    return 0;
}