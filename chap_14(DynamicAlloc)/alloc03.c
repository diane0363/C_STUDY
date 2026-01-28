/*
[연습] 키보드로부터 문자열(단어 1개)을 입력받아
입력받은 문자열의 길이 +1 크기만큼 동적으로 메모리를 할당받은 후
복사하고 출력하는 코드 완성

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strlen, strcpy

int main()
{
    // 입력을 받아야 크기를 알 수 있다!
    char keyin[50]; // 최대 49개의 영문자 입력받을 수 있음. stack 메모리에 저장????
    // char *p;

    printf("영단어 입력 :");
    scanf("%s", keyin);        // 띄어쓰기가 있으면 fscanf사용

    strlen(keyin); // 입력받은 문자열의 길이 계산

    // null이 들어가는 공간까지 고려해서 +1
    // char *p = (char *)malloc(sizeof(char) * (strlen(keyin) + 1)); // +1 : null문자
    char *cptr = (char *)malloc(strlen(keyin) + 1); // +1 : null문자

    // 메모리 할당 여부 체크
    if (cptr == NULL)
    {
        printf("메모리 할당 실패\n");
        exit(0);
    }

    strcpy(cptr, keyin);
    printf("입력받은 단어 : %s\n", cptr);
    
    free(cptr);

    return 0;
}
