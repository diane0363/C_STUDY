#include <stdio.h>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(65001); // UTF-8 출력 설정
    char name[30];
    int score;

    FILE *fp = fopen("./data/rnote03.txt", "rt");

    printf("이름과 점수를 연달아 입력 : ");
    fscanf(fp, "%s %d", name, &score);

    printf("입력 받은 정보 : %s, %d\n", name, score);

    fclose(fp);
    return 0;
}