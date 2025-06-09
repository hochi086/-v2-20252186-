#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define ROOM_WIDTH 10
#define HME_POS 1
#define BWL_PO (ROOM_WIDTH - 2)

int main(void) {

	printf("****�߿��̿� ����****\n\n");

	printf("      /\\_/\\\n");
	printf(" /\\  / o o \\\n");
	printf("//\\\\ \\~(*)~/\n");
	printf("`  \\/   ^ /\n");
	printf("   | \\|| || \n");
	printf("   \\ '|| ||\n");
	printf("    \\)()-())\n\n");

	char catname[100];

	printf("�߿����� �̸��� ���� �ּ���: ");
	scanf_s("%s", catname, sizeof(catname));
	printf("�߿����� �̸��� %s�Դϴ�.\n", catname);

	Sleep(1000);
	system("cls");

	int soup = 0;
	int frdshp = 2;

	int cat_pos = HME_POS;
	int previous_pos = -1;

	int cat_feel = 3;
	int cp = 0;

	while (1) {
		printf("==================== �������===================\n");
		
		printf("������� ���� ����: %d��\n", soup);
		
		//����� ���
		printf("%s ���(0~3): %d\n", catname, cat_feel);
		if (cat_feel == 3) {
			printf("������ �θ��ϴ�.\n");
		}
		else if (cat_feel == 2) {
			printf("�Ļ��� �����ϴ�.\n");
		}
		else if (cat_feel == 1) {
			printf("�ɽ����մϴ�.\n");
		}
		else {
			printf("����� �ſ� ���޴ϴ�.\n");
		}

		printf("������� ����(0~4): %d\n", frdshp);

		if (frdshp == 0) {
			printf(" �翡 ���� ������ �Ⱦ��մϴ�.\n");
		}
		else if (frdshp == 1) {
			printf(" ���� ���Ǳ� ����Դϴ�.\n");
		}
		else if (frdshp == 2) {
			printf(" �׷����� �� ���� �����Դϴ�.\n");
		}
		else if (frdshp == 3) {
			printf(" �Ǹ��� ����� �����ް� �ֽ��ϴ�.\n");
		}
		else if (frdshp >= 4) {
			printf(" ���� �������Դϴ�.\n");
		}
		printf("==================================================\n\n");

		printf("%d-%d: �ֻ��� ���� %d�����̸� �׳� ����� �������ϴ�.\n", 6, frdshp, 6 - frdshp);
		printf("�ֻ����� �����ϴ�. �Ǹ���...\n");

		previous_pos = cat_pos;
		int moved = 0;

		srand((unsigned int)time(NULL));
		for (int i = 0; i < 1; i++) {
			int dice = rand() % 6 + 1;
			printf("%d��(��) ���Խ��ϴ�.\n", dice);
			
			//����� ��� ������
			if (dice <= (6 - frdshp) && cat_feel > 0) {
				printf("%s�� ����� �������ϴ�: %d->%d\n", catname, cat_feel, cat_feel - 1);
				cat_feel--;
			}

			//��п� ���� �ൿ
			int toy_mouse = 0, laser_pointer = 0, scratcher = 0, cat_tower = 0;
			int scratcher_pos = -1, tower_pos = -1;

			if (cat_feel == 0 && cat_pos > HME_POS) {
				printf("����� �ſ� ���� %s��(��) ������ ���մϴ�.\n", catname);
				cat_pos--;
			}
			else if (cat_feel == 1) {
				if (scratcher && cat_tower) {
					int dist_s, dist_t;

					if (cat_pos > scratcher_pos) dist_s = cat_pos - scratcher_pos;
					else dist_s = scratcher_pos - cat_pos;

					if (cat_pos > tower_pos) dist_t = cat_pos - tower_pos;
					else dist_t = tower_pos - cat_pos;

					if (dist_s <= dist_t) {
						printf("%s��(��) �ɽ��ؼ� ��ũ��ó ������ �̵��մϴ�.\n", catname);
						if (cat_pos < scratcher_pos) cat_pos++;
						else if (cat_pos > scratcher_pos) cat_pos--;
					}
					else {
						printf("%s��(��) �ɽ��ؼ� ĹŸ�� ������ �̵��մϴ�.\n", catname);
						if (cat_pos < tower_pos) cat_pos++;
						else if (cat_pos > tower_pos) cat_pos--;
					}
				}
				else if (scratcher) {
					printf("%s��(��) �ɽ��ؼ� ��ũ��ó ������ �̵��մϴ�.\n", catname);
					if (cat_pos < scratcher_pos) cat_pos++;
					else if (cat_pos > scratcher_pos) cat_pos--;
				}
				else if (cat_tower) {
					printf("%s��(��) �ɽ��ؼ� ĹŸ�� ������ �̵��մϴ�.\n", catname);
					if (cat_pos < tower_pos) cat_pos++;
					else if (cat_pos > tower_pos) cat_pos--;
				}
				else {
					printf("�� �Ÿ��� ��� ����� �ſ� �������ϴ�.\n");
					if (cat_feel > 0) cat_feel--;
				}
			}
			else if (cat_feel == 2) {
				printf("%s��(��) ������� �Ļ��� ���� �ֽ��ϴ�.\n", catname);
			}
			else if (cat_feel == 3 && cat_pos < BWL_PO) {
				printf("%s��(��) ������ �θ��� ������ ���鷯 ���ϴ�.\n", catname);
				cat_pos++;
			}

			else if (cat_pos == BWL_PO) {
				srand((unsigned int)time(NULL));
				for (int i = 0; i < 1; i++) {
					int soup_name = rand() % 3;

					if (soup_name == 0) {
						printf("%s��(��) ���� ������ ��������ϴ�!\n", catname);
					}
					else if (soup_name == 1) {
						printf("%s��(��) ����� ������ ��������ϴ�!\n", catname);
					}
					else if (soup_name == 2) {
						printf("%s��(��) ����ݸ� ������ ��������ϴ�!\n", catname);
					}
					soup += 1;
				}
			}

			printf("\n");
			//���� ��
			for (int i = 0; i < ROOM_WIDTH; i++) {
				printf("#");
			}
			printf("\n");
			//��, ����
			printf("#");
			for (int i = 1; i < ROOM_WIDTH - 1; i++) {
				if (i == HME_POS) {
					printf("H");
				}
				else if (i == BWL_PO) {
					printf("B");
				}
				else {
					printf(" ");
				}
			}
			printf("#\n");
			//����� ��ġ
			printf("#");
			for (int i = 1; i < ROOM_WIDTH - 1; i++) {
				if (i == cat_pos) {
					printf("C");
				}
				else if (i == previous_pos && previous_pos != cat_pos) {
					printf(".");
				}
				else {
					printf(" ");
				}
			}
			printf("#\n");
			//�Ʒ��� ��
			for (int i = 0; i < ROOM_WIDTH; i++) {
				printf("#");
			}
			printf("\n");

			int move;
			printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?  0. �ƹ��͵� ���� ����   1. �ܾ� �ֱ�\n");
			while (1) {
				printf(">> ");
				scanf_s("%d", &move);
				if (move == 0) {
					printf("�ƹ��͵� ���� �ʾҽ��ϴ�.\n");
					printf("4/6�� Ȯ���� ģ�е��� �������ϴ�.\n");
					printf("�ֻ����� �����ϴ�. �Ǹ���...\n");

					srand((unsigned int)time(NULL));
					for (int i = 0; i < 1; i++) {
						int dice = rand() % 6 + 1;
						if (dice > 4) {
							printf("%d��(��) ���Խ��ϴ�!\n", dice);
							printf("������ ģ�е��� �������� �ʾҽ��ϴ�.\n");
						}
						else if (dice <= 4) {
							printf("%d��(��) ���Խ��ϴ�!\n", dice);
							if (frdshp > 0) {
								printf("ģ�е��� �������ϴ�.\n");
								frdshp -= 1;
							}
							else {
								printf("�� �̻� �������� �ʽ��ϴ�.\n");
							}
						}
					}
					break;
				}

				else if (move == 1) {
					printf("%s�� ���� �ܾ��־����ϴ�.\n", catname);
					printf("2/6�� Ȯ���� ģ�е��� �������ϴ�.\n");
					printf("�ֻ����� �����ϴ�. �Ǹ���...\n");

					srand((unsigned int)time(NULL));
					for (int i = 0; i < 1; i++) {
						int dice = rand() % 6 + 1;
						if (dice > 4) {
							printf("%d��(��) ���Խ��ϴ�!\n", dice);
							if (frdshp < 4) {
								printf("ģ�е��� �������ϴ�.\n");
								frdshp += 1;
							}
							else {
								printf("�̹� ģ�е��� �ִ��Դϴ�.\n");
							}
						}
						else if (dice <= 4) {
							printf("%d��(��) ���Խ��ϴ�!\n", dice);
							printf("ģ�е��� �״���Դϴ�.\n");
						}
					}
					break;
				}
				else {
				}
			}
			printf("���� ģ�е�: %d\n", frdshp);

			Sleep(2500);
			system("cls");

		}
	}

	return 0;
}