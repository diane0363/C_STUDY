/*
파일에 저장된 학생들의 점수를 입력받아 평균을 구하고 화면에 출력
김다인 90 80 100 90
*/
#include <stdio.h>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(65001); // UTF-8 출력 설정
    char name[30];
    int kor, eng, math;

    FILE *fp = fopen("./data/rnote03.txt", "rt");

    printf("이름과 점수를 연달아 입력 : ");
    fscanf(fp, "%s %d", name, &score);

    printf("입력 받은 정보 : %s, %d\n", name, score);

    fclose(fp);
    return 0;
}