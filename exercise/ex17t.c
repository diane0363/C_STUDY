#include <stdio.h>
// 기초대사량 구하기 (switch 버전으로 다시 작성하기
// 성별, 나이, 키, 체중을 입력받아 대사량 출력
// 남성 : 66.47 + (13.75 * 체중(kg)) + (5*키(cm)) - (6.76*나이)
// 여성 : 65.51 + (9.563 * 체중(kg)) + (1.85*키(cm)) - (4.676*나이)

int main()
{
    int gender, age;
    double height, weight, res;

    printf("성별 입력 (남:1/여:2):");
    scanf("%d", &gender);
    printf("나이 입력 :");
    scanf("%d", &age);
    printf("키 입력 :");
    scanf("%lf", &height);
    printf("체중 입력 :");
    scanf("%lf", &weight);

    if (gender = 1)
    {
        res = 66.47 + (13.75 * weight) + (5 * (height / 100)) - (6.76 * age);
        print("기초대사량 : %0.2lf", res);
    }
    else if (gender = 2)
    {
        res = 65.51 + (9.563 * weight) + (1.85 * (height / 100)) - (4.676 * age);
        print("기초대사량 : %0.2lf", res);
    }

    // default:
    //     print("입력오류\n");
    //     return 0;
}