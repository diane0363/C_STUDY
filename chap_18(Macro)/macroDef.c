#include <stdio.h>

// 매크로 상수 정의. PI 값 바뀔 일 없으니 상수로 박아둠.
#define PI 3.141592
// 매크로 함수. 괄호 안 치면 계산 꼬일 수 있다고 해서 괄호 떡칠함.
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int main() {
    // 매크로 써봄. 전처리기가 컴파일 전에 다 코드로 바꿔준다고 함.
    double radius = 5.0;
    double area = PI * SQUARE(radius);
    
    printf("원의 넓이: %f\n", area);

    int num1 = 10, num2 = 20;
    printf("둘 중 큰 수: %d\n", MAX(num1, num2));

    // 매크로는 디버깅이 힘들어서 요즘은 inline 함수를 더 선호한다고 들음. 그래도 알아둬야 함.
    return 0;
}
