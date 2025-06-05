#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define ROOM_WIDTH 10
#define HME_POS 1
#define BWL_POS (ROOM_WIDTH - 2)

int main() {
    srand((unsigned int)time(NULL));

    char name[20];
    int intimacy = 2;
    int soupCount = 0;
    int catPos = HME_POS;
    int prevCatPos = HME_POS;

    printf("****야옹이와 수프****\n");
    printf("     /\\_/\\\n");
    printf("    ( o.o )\n");
    printf("     > ^ <\n");

    printf("야옹이의 이름을 지어 주세요: ");
    if (scanf("%19s", name) != 1) {
        printf("이름 입력에 실패했습니다. 프로그램을 종료합니다.\n");
        return 1;
    }
    printf("야옹이의 이름은 %s입니다.\n", name);
    Sleep(1000);
    system("cls");

    while (1) {
        printf("==================== 현재 상태 ===================\n");
        printf("현재까지 만든 수프: %d개\n", soupCount);
        printf("집사와의 관계(0~4): %d\n", intimacy);
        switch (intimacy) {
        case 0: printf("곁에 오는 것조차 싫어합니다.\n"); break;
        case 1: printf("간식 자판기 취급입니다.\n"); break;
        case 2: printf("그럭저럭 쓸 만한 집사입니다.\n"); break;
        case 3: printf("훌륭한 집사로 인정 받고 있습니다.\n"); break;
        case 4: printf("집사 껌딱지입니다.\n"); break;
        }

        printf("==================================================\n\n");
        printf("##########\n");
        printf("#H      B#\n#");
        for (int i = 1; i < ROOM_WIDTH - 1; i++) {
            if (i == catPos)
                printf("C");
            else if (i == prevCatPos)
                printf(".");
            else
                printf(" ");
        }
        printf("#\n##########\n\n");

        int action = -1;
        while (1) {
            printf("어떤 상호작용을 하시겠습니까?   0. 아무것도 하지 않음 1. 긁어 주기\n>> ");
            if (scanf("%d", &action) == 1 && (action == 0 || action == 1)) break;
            while (getchar() != '\n');
        }

        int dice = rand() % 6 + 1;
        if (action == 0) {
            printf("아무것도 하지 않습니다.\n");
            printf("4/6의 확률로 친밀도가 떨어집니다.\n주사위를 굴립니다. 또르륵...\n");
            printf("%d이(가) 나왔습니다!\n", dice);
            if (dice <= 4 && intimacy > 0) {
                intimacy--;
                printf("친밀도가 떨어집니다.\n");
            }
            else {
                printf("다행히 친밀도가 떨어지지 않았습니다.\n");
            }
        }
        else {
            printf("%s의 턱을 긁어주었습니다.\n", name);
            printf("2/6의 확률로 친밀도가 높아집니다.\n주사위를 굴립니다. 또르륵...\n");
            printf("%d이(가) 나왔습니다!\n", dice);
            if (dice >= 5 && intimacy < 4) {
                intimacy++;
                printf("친밀도가 높아집니다.\n");
            }
            else {
                printf("친밀도는 그대로입니다.\n");
            }
        }

        prevCatPos = catPos;
        dice = rand() % 6 + 1;
        printf("\n%s 이동: 집사와 친밀할수록 냄비 쪽으로 갈 확률이 높아집니다.\n", name);
        printf("주사위 눈이 %d 이상이면 냄비 쪽으로 이동합니다.\n", 6 - intimacy);
        printf("주사위를 굴립니다. 또르륵...\n%d이(가) 나왔습니다!\n", dice);

        if (dice >= (6 - intimacy)) {
            if (catPos < BWL_POS) catPos++;
            else printf("벽에 막혀 움직이지 못했습니다.\n");
        }
        else {
            if (catPos > HME_POS) catPos--;
            else printf("벽에 막혀 움직이지 못했습니다.\n");
        }

        if (catPos == BWL_POS) {
            int soupType = rand() % 3;
            const char* soupName;

            if (soupType == 0) {
                soupName = "감자 수프";
            }
            else if (soupType == 1) {
                soupName = "양송이 수프";
            }
            else {
                soupName = "브로콜리 수프";
            }

            printf("%s이(가) %s를 만들었습니다!\n", name, soupName);
            soupCount++;
        }
        else if (catPos == HME_POS) {
            printf("%s은(는) 자신의 집에서 편안함을 느낍니다.\n", name);
        }

        Sleep(2500);
        system("cls");
    }
    return 0;
}
