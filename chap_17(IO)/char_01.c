#include <stdio.h>

int main()
{
    char buffer[100];
    printf("문자열을 입력하시오 : ");
    fgets(buffer, sizeof(buffer), stdin);

    if (buffer[strlen(buffer) - 1] == '\n')
    {
        buffer[strlen(buffer) - 1] = '\0'; // 개행 문자 제거
    }

    // printf("입력된 문자열: %s", buffer);

    fputs("입력한 문자열: ", stdout);
    fputs(buffer, stdout);

    return 0;
}