#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int* p = arr; // 배열 이름은 포인터 상수임. 배열의 첫 번째 요소 주소를 가리킴.

    printf("배열 요소를 포인터로 출력해봄:\n");
    for (int i = 0; i < 5; i++) {
        // p[i] 랑 *(p + i) 랑 완전 똑같은 거임
        printf("*(p + %d) = %d\n", i, *(p + i));
    }

    // 포인터 연산 해봄. int형이라 4바이트씩 점프함.
    p++;
    printf("p++ 한 뒤의 *p 값: %d\n", *p); // 2 나와야 정상임

    return 0;
}
