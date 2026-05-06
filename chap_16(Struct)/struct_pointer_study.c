#include <stdio.h>
#include <string.h>

// 게임 캐릭터 구조체 하나 만들어봄
typedef struct {
    char name[50];
    int hp;
    int mp;
    int level;
} Character;

// 포인터로 받아서 스탯 올려주는 함수임
void levelUp(Character* c) {
    c->level += 1;
    c->hp += 50;
    c->mp += 20;
    // 화살표 연산자(->) 쓰는게 (*c).level 보다 훨씬 편함
}

int main() {
    Character hero = {"용사", 100, 50, 1};

    printf("레벨업 전: 레벨 %d, HP %d\n", hero.level, hero.hp);

    // 주소값 넘겨서 함수 호출함
    levelUp(&hero);

    printf("레벨업 후: 레벨 %d, HP %d\n", hero.level, hero.hp); // 스탯 오른거 확인됨 굿

    return 0;
}
