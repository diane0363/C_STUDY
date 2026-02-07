/* 텍스트 파일에 쓰기 (1문자 단위) 지정한 디렉토리에 파일이 생성 파일의 크기는 4 byte. */
#include <stdio.h>
int main()
{ // 없으면 만들고, 있으면 Overwrite
    FILE *p = fopen("./data/wnote1.txt", "wt");
    if (p == NULL)
    {
        printf("파일을 열수 없습니다.\n");
        return 0;
    }
    fputc('a', p); //'a'를 파일에 쓴다.
    fputc('b', p);
    fputc('c', p);
    fputc('d', p);
    fputc(65, p);

    fclose(p);
    return 0;
}