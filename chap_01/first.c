#include <stdio.h> // import와 비슷한 개념
// 헤더파일(studio.h)이 필요하다.
// io는 input,output 그럼 std는 standard
// .h 는 헤더파일

// 메인은 항상 있어야하는데 임베디드 코딩을 할 때는 필요X
// 환경에 따라 메인 필요 유무 바뀜
int main()
{
    // 내가 만들지 않은 함수 호출 => #include 필요
    printf("Hello, world!!");

    return 0;
}