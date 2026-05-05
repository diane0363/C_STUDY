#include <stdio.h>

// 전역 변수 선언. 웬만하면 안 쓰는 게 좋다고 함. 꼬이기 쉬움.
int global_var = 100;

void testFunc() {
    // 지역 변수. 이 함수 끝나면 사라짐.
    int local_var = 10;
    global_var += 50; // 전역 변수는 여기서도 접근 가능함.
    printf("testFunc 안: local_var = %d, global_var = %d\n", local_var, global_var);
}

int main() {
    int main_local = 20;

    printf("main 시작: global_var = %d\n", global_var);
    
    testFunc();

    // 여기서 local_var 부르면 에러남. 스코프가 다름.
    // printf("%d", local_var); // 주석 풀면 컴파일 에러남.

    printf("main 끝: main_local = %d, global_var = %d\n", main_local, global_var);

    return 0;
}
