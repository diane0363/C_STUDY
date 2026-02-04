/*
자기 참조 구조체
단방향 링크드 리스트 만들기(CRUD)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char name[20];
    struct Node *next;
} Node;

// headp : 첫 번째 노드를 가리키는 포인터.
//          노드가 하나도 없으면 NULL. 데이터가 없다.
//          더미 노드 - 무조건 첫번째 노드를 가리키는 포인터
// tailp : 마지막 노드를 가리키는 포인터.
//          노드가 하나도 없으면 NULL.
//          없어도 되지만, 추가할 때 편리하다고..?
// currp : 현재 노드를 가리키는 포인터.

// 첫번째 헤드포인터는 무조건 전역 변수로 선언
struct Node *headp = NULL;

// struct Node *tailp = NULL;

// 함수 프로토타입
void init_list();
void create_list();
void display_list();
void search_node(); // 특정 노드 검색
void delete_node(); // 특정 노드 삭제
// void free_list();   // 메모리 해제
void append_node(); // 노드 추가
void sort_list();   // 노드 정렬
void free_all();    // 프로그램 종료시 동적 생성된 노드 전부 삭제 (노드 삭제 = 메모리 해제?)
void menu();

int main()
{
    char choice;
    init_list();
    while (1)
    {
        menu();
        printf("메뉴 선택: ");
        scanf(" %c", &choice); // %c 앞에 공백을 넣어 이전 입력의 개행문자 제거 (버퍼 비우기)

        // fflush(stdin); // 데이터를 밀어내기 위해 사용. 원래 버퍼 비우기 용도는 아님

        // 입력 버퍼의 데이터를 반복적으로 삭제해서 stdin 비우기
        while (getchar() != '\n')
            ;

        switch (choice)
        {
        case '1':
            create_list();
            break;
        case '2':
            display_list();
            break;
        case '3':
            break;
        case '4':
            delete_node();
            break;
        case '5':
            append_node();
            break;
        case '6':
            sort_list();
            break;
        case '0':
            printf("프로그램 종료\n");
            free_all(); // 종료하기 전 동적 생성된 메모리 해제
            return 0;
        default:
            printf("잘못된 선택입니다. 다시 시도하세요.\n");
        }
    }
    create_list();
    display_list();
    delete_node();
    display_list();
    free_all();

    return 0;
}

// headp 초기화
void init_list()
{
    headp = (Node *)malloc(sizeof(Node)); // 더미 노드 생성
    headp->next = NULL;
    // tailp = NULL;
}

// 노드 추가(명단 입력)
void create_list()
{
    char iname[20];
    printf("\n=== 명단 추가 ===\n");

    // printf("이름 입력: ");
    // scanf("%s", iname);

    while (1)
    {
        printf("이름 입력(엔터 시 종료): ");
        fgets(iname, sizeof(iname), stdin); // 개행 문자 포함 입력 받기
        // fgets는 입력 버퍼

        // 다 같은 의미?
        // if(iname == NULL) {
        // if(strcmp(iname, "\n") == 0) {
        if (iname[0] == '\0')
        {
            printf("입력 오류\n");
            continue;
        }

        if (strcmp(iname, "exit\n") == 0)
        {
            printf("입력 종료\n");
            break;
        }

        printf("입력된 이름: %s", iname);

        // 개행 문자 제거
        if (iname[strlen(iname) - 1] == '\n')
        {
            iname[strlen(iname) - 1] = '\0';
        }

        // 새 노드 동적 생성
        Node *newNode = (Node *)malloc(sizeof(Node));

        // malloc으로 새로운 node 생성을 실패한 경우 Null 이므로
        // malloc은 연속적으로 메모리를 할당해야하는데 메모리가 부족한 경우 NULL 반환
        if (newNode == NULL)
        {
            printf("메모리 할당 실패\n");
            return;
        }

        strcpy(newNode->name, iname);

        newNode->next = NULL; // 새 노드의 다음 포인터를 NULL로 초기화

        // current pointer : 현재 노드를 가리키는 포인터
        Node *currp = headp;
        while (currp->next != NULL)
            currp = currp->next; // 커런트 포인터를 다음 노드로 이동

        currp->next = newNode;
    }

    // // 새 노드 동적 생성
    // Node *newNode = (Node *)malloc(sizeof(Node));
    // strcpy(newNode->name, name);
    // newNode->next = NULL;

    // // 리스트의 마지막에 새 노드 추가
    // Node *currp = headp;
    // while (currp->next != NULL)
    // {
    //     currp = currp->next;
    // }
    // currp->next = newNode;

    // printf("명단에 %s 추가 완료!\n", name);
}

// 노드 출력(명단 출력)
// 헤드포인터가 가리키고 있는 첫 번째 노드부터 출력
void display_list()
{
    printf("\n=== 명단 출력 ===\n");
    Node *currp = headp->next; // 첫번째 노드의 주소를 가져와 더미 노드 다음 노드부터 출력

    if (currp == NULL) // 마지막 노드는 NULL을 가리키므로
    {
        printf("명단이 비어 있습니다.\n");
        return;
    }

    while (currp != NULL)
    {
        printf("이름: %s\n", currp->name);
        currp = currp->next;
    }
}

void delete_node()
{
    // 삭제할 노드를 순차적으로 탐색
    // 이전 노드 포인터가 있어야 다음 노드 탐색 가능

    // !!!!! 노드를 그냥 삭제하면 안 된다!
    // 이전 노드의 next 포인터를 삭제할 노드의 next 포인터로 변경한 후 삭제!
    // currp가 가지고 있는 next 포인터를 prevp의 next 포인터에 연결
    // 그런 다음 currp를 해제
    printf("\n=== 명단 삭제 ===\n");
    Node *currp = headp->next; // 첫 번째 노드
    Node *prevp = headp;       // 이전 노드(더미 노드부터 시작)
    char dname[20];

    printf("삭제할 이름 입력: ");
    scanf("%s", dname);

    //
    while (currp != NULL)
    {
        // strcmp는 같으면 0 반환, 앞이 크면 양수, 뒤가 크면 음수 반환
        if (strcmp(currp->name, dname) == 0) // 이름이 일치하는 경우
        {
            prevp->next = currp->next; // 이전 노드의 next 포인터를 삭제할 노드의 next 포인터로 연결
            free(currp);               // 삭제할 노드 메모리 해제
            printf("%s 노드 삭제 완료!\n", dname);
            return;
        }
        prevp = currp;       // 이전 노드를 현재 노드로 이동
        currp = currp->next; // 현재 노드를 다음 노드로 이동
    }
    printf("이름 %s를 찾을 수 없습니다.\n", dname);
}
void free_all()
{
    // 모든 노드 메모리 해제
    // 노드 해제 시 연결 고리가 끊기지 않게 주의
    // currp가 가리키는 노드를 temp에 저장한 후 메모리 해제
    // currp를 다음 노드로 이동
    Node *currp = headp; // 더미 노드부터 시작
    Node *temp;

    while (currp != NULL)
    {
        temp = currp;
        currp = currp->next;
        free(temp);

        // 아래와 같은 방법도 가능
        // temp = currp->next;
        // free(currp);
        // currp = temp;
    }
}

void menu()
{
    printf("\n--- [ 명단 관리 ] ---\n");
    printf(" 1 ) 입력 (Create)\n");
    printf(" 2 ) 출력 (Read)\n");
    printf(" 3 ) 검색 (Search)\n");
    printf(" 4 ) 삭제 (Delete)\n");
    printf(" 5 ) 추가 (Insert)\n");
    printf(" 6 ) 정렬 (Sort)\n");
    printf(" 0 ) 종료 (Exit)\n");
}
