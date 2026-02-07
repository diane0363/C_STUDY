#include <stdio.h>

int main()
{
    int data;

    printf("문자를 입력하세요: ");
    while (1)
    {
        // printf("문자를 입력하세요: ");
        data = getchar(); // 문자 1개를 입력받음
        if (data == -1)   // EOF(End Of File) 체크, ctrl + c 입력 시
            break;
        printf("입력된 문자는 %c(%d)입니다.\n", data, data);
    }

    // 입출력 결과 예시
    // a -> a(97)
    // \n -> \n(10)

    // ctrl + c -> 프로그램 종료

    return 0;
}
