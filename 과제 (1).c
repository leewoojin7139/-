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

    printf("****�߿��̿� ����****\n");
    printf("     /\\_/\\\n");
    printf("    ( o.o )\n");
    printf("     > ^ <\n");

    printf("�߿����� �̸��� ���� �ּ���: ");
    if (scanf("%19s", name) != 1) {
        printf("�̸� �Է¿� �����߽��ϴ�. ���α׷��� �����մϴ�.\n");
        return 1;
    }
    printf("�߿����� �̸��� %s�Դϴ�.\n", name);
    Sleep(1000);
    system("cls");

    while (1) {
        printf("==================== ���� ���� ===================\n");
        printf("������� ���� ����: %d��\n", soupCount);
        printf("������� ����(0~4): %d\n", intimacy);
        switch (intimacy) {
        case 0: printf("�翡 ���� ������ �Ⱦ��մϴ�.\n"); break;
        case 1: printf("���� ���Ǳ� ����Դϴ�.\n"); break;
        case 2: printf("�׷����� �� ���� �����Դϴ�.\n"); break;
        case 3: printf("�Ǹ��� ����� ���� �ް� �ֽ��ϴ�.\n"); break;
        case 4: printf("���� �������Դϴ�.\n"); break;
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
            printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?   0. �ƹ��͵� ���� ���� 1. �ܾ� �ֱ�\n>> ");
            if (scanf("%d", &action) == 1 && (action == 0 || action == 1)) break;
            while (getchar() != '\n');
        }

        int dice = rand() % 6 + 1;
        if (action == 0) {
            printf("�ƹ��͵� ���� �ʽ��ϴ�.\n");
            printf("4/6�� Ȯ���� ģ�е��� �������ϴ�.\n�ֻ����� �����ϴ�. �Ǹ���...\n");
            printf("%d��(��) ���Խ��ϴ�!\n", dice);
            if (dice <= 4 && intimacy > 0) {
                intimacy--;
                printf("ģ�е��� �������ϴ�.\n");
            }
            else {
                printf("������ ģ�е��� �������� �ʾҽ��ϴ�.\n");
            }
        }
        else {
            printf("%s�� ���� �ܾ��־����ϴ�.\n", name);
            printf("2/6�� Ȯ���� ģ�е��� �������ϴ�.\n�ֻ����� �����ϴ�. �Ǹ���...\n");
            printf("%d��(��) ���Խ��ϴ�!\n", dice);
            if (dice >= 5 && intimacy < 4) {
                intimacy++;
                printf("ģ�е��� �������ϴ�.\n");
            }
            else {
                printf("ģ�е��� �״���Դϴ�.\n");
            }
        }

        prevCatPos = catPos;
        dice = rand() % 6 + 1;
        printf("\n%s �̵�: ����� ģ���Ҽ��� ���� ������ �� Ȯ���� �������ϴ�.\n", name);
        printf("�ֻ��� ���� %d �̻��̸� ���� ������ �̵��մϴ�.\n", 6 - intimacy);
        printf("�ֻ����� �����ϴ�. �Ǹ���...\n%d��(��) ���Խ��ϴ�!\n", dice);

        if (dice >= (6 - intimacy)) {
            if (catPos < BWL_POS) catPos++;
            else printf("���� ���� �������� ���߽��ϴ�.\n");
        }
        else {
            if (catPos > HME_POS) catPos--;
            else printf("���� ���� �������� ���߽��ϴ�.\n");
        }

        if (catPos == BWL_POS) {
            int soupType = rand() % 3;
            const char* soupName;

            if (soupType == 0) {
                soupName = "���� ����";
            }
            else if (soupType == 1) {
                soupName = "����� ����";
            }
            else {
                soupName = "����ݸ� ����";
            }

            printf("%s��(��) %s�� ��������ϴ�!\n", name, soupName);
            soupCount++;
        }
        else if (catPos == HME_POS) {
            printf("%s��(��) �ڽ��� ������ ������� �����ϴ�.\n", name);
        }

        Sleep(2500);
        system("cls");
    }
    return 0;
}
