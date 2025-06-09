#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define ROOM_WIDTH 10
#define HME_POS 1
#define BWL_PO (ROOM_WIDTH - 2)

int main(void) {

	printf("****야옹이와 수프****\n\n");

	printf("      /\\_/\\\n");
	printf(" /\\  / o o \\\n");
	printf("//\\\\ \\~(*)~/\n");
	printf("`  \\/   ^ /\n");
	printf("   | \\|| || \n");
	printf("   \\ '|| ||\n");
	printf("    \\)()-())\n\n");

	char catname[100];

	printf("야옹이의 이름을 지어 주세요: ");
	scanf_s("%s", catname, sizeof(catname));
	printf("야옹이의 이름은 %s입니다.\n", catname);

	Sleep(1000);
	system("cls");

	int soup = 0;
	int frdshp = 2;

	int cat_pos = HME_POS;
	int previous_pos = -1;

	int cat_feel = 3;
	int cp = 0;

	while (1) {
		printf("==================== 현재상태===================\n");
		
		printf("현재까지 만든 수프: %d개\n", soup);
		
		//고양이 기분
		printf("%s 기분(0~3): %d\n", catname, cat_feel);
		if (cat_feel == 3) {
			printf("골골송을 부릅니다.\n");
		}
		else if (cat_feel == 2) {
			printf("식빵을 굽습니다.\n");
		}
		else if (cat_feel == 1) {
			printf("심심해합니다.\n");
		}
		else {
			printf("기분이 매우 나쁩니다.\n");
		}

		printf("집사와의 관계(0~4): %d\n", frdshp);

		if (frdshp == 0) {
			printf(" 곁에 오는 것조차 싫어합니다.\n");
		}
		else if (frdshp == 1) {
			printf(" 간식 자판기 취급입니다.\n");
		}
		else if (frdshp == 2) {
			printf(" 그럭저럭 쓸 만한 집사입니다.\n");
		}
		else if (frdshp == 3) {
			printf(" 훌륭한 집사로 인정받고 있습니다.\n");
		}
		else if (frdshp >= 4) {
			printf(" 집사 껌딱지입니다.\n");
		}
		printf("==================================================\n\n");

		printf("%d-%d: 주사위 눈이 %d이하이면 그냥 기분이 나빠집니다.\n", 6, frdshp, 6 - frdshp);
		printf("주사위를 굴립니다. 또르륵...\n");

		previous_pos = cat_pos;
		int moved = 0;

		srand((unsigned int)time(NULL));
		for (int i = 0; i < 1; i++) {
			int dice = rand() % 6 + 1;
			printf("%d이(가) 나왔습니다.\n", dice);
			
			//고양이 기분 나빠짐
			if (dice <= (6 - frdshp) && cat_feel > 0) {
				printf("%s의 기분이 나빠집니다: %d->%d\n", catname, cat_feel, cat_feel - 1);
				cat_feel--;
			}

			//기분에 따른 행동
			int toy_mouse = 0, laser_pointer = 0, scratcher = 0, cat_tower = 0;
			int scratcher_pos = -1, tower_pos = -1;

			if (cat_feel == 0 && cat_pos > HME_POS) {
				printf("기분이 매우 나쁜 %s은(는) 집으로 향합니다.\n", catname);
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
						printf("%s은(는) 심심해서 스크래처 쪽으로 이동합니다.\n", catname);
						if (cat_pos < scratcher_pos) cat_pos++;
						else if (cat_pos > scratcher_pos) cat_pos--;
					}
					else {
						printf("%s은(는) 심심해서 캣타워 쪽으로 이동합니다.\n", catname);
						if (cat_pos < tower_pos) cat_pos++;
						else if (cat_pos > tower_pos) cat_pos--;
					}
				}
				else if (scratcher) {
					printf("%s은(는) 심심해서 스크래처 쪽으로 이동합니다.\n", catname);
					if (cat_pos < scratcher_pos) cat_pos++;
					else if (cat_pos > scratcher_pos) cat_pos--;
				}
				else if (cat_tower) {
					printf("%s은(는) 심심해서 캣타워 쪽으로 이동합니다.\n", catname);
					if (cat_pos < tower_pos) cat_pos++;
					else if (cat_pos > tower_pos) cat_pos--;
				}
				else {
					printf("놀 거리가 없어서 기분이 매우 나빠집니다.\n");
					if (cat_feel > 0) cat_feel--;
				}
			}
			else if (cat_feel == 2) {
				printf("%s은(는) 기분좋게 식빵을 굽고 있습니다.\n", catname);
			}
			else if (cat_feel == 3 && cat_pos < BWL_PO) {
				printf("%s은(는) 골골송을 부르며 수프를 만들러 갑니다.\n", catname);
				cat_pos++;
			}

			else if (cat_pos == BWL_PO) {
				srand((unsigned int)time(NULL));
				for (int i = 0; i < 1; i++) {
					int soup_name = rand() % 3;

					if (soup_name == 0) {
						printf("%s이(가) 감자 수프를 만들었습니다!\n", catname);
					}
					else if (soup_name == 1) {
						printf("%s이(가) 양송이 수프를 만들었습니다!\n", catname);
					}
					else if (soup_name == 2) {
						printf("%s이(가) 브로콜리 수프를 만들었습니다!\n", catname);
					}
					soup += 1;
				}
			}

			printf("\n");
			//위쪽 벽
			for (int i = 0; i < ROOM_WIDTH; i++) {
				printf("#");
			}
			printf("\n");
			//집, 냄비
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
			//고양이 위치
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
			//아래쪽 벽
			for (int i = 0; i < ROOM_WIDTH; i++) {
				printf("#");
			}
			printf("\n");

			int move;
			printf("어떤 상호작용을 하시겠습니까?  0. 아무것도 하지 않음   1. 긁어 주기\n");
			while (1) {
				printf(">> ");
				scanf_s("%d", &move);
				if (move == 0) {
					printf("아무것도 하지 않았습니다.\n");
					printf("4/6의 확률로 친밀도가 떨어집니다.\n");
					printf("주사위를 굴립니다. 또르륵...\n");

					srand((unsigned int)time(NULL));
					for (int i = 0; i < 1; i++) {
						int dice = rand() % 6 + 1;
						if (dice > 4) {
							printf("%d이(가) 나왔습니다!\n", dice);
							printf("다행이 친밀도가 떨어지지 않았습니다.\n");
						}
						else if (dice <= 4) {
							printf("%d이(가) 나왔습니다!\n", dice);
							if (frdshp > 0) {
								printf("친밀도가 떨어집니다.\n");
								frdshp -= 1;
							}
							else {
								printf("더 이상 떨어지지 않습니다.\n");
							}
						}
					}
					break;
				}

				else if (move == 1) {
					printf("%s의 턱을 긁어주었습니다.\n", catname);
					printf("2/6의 확률로 친밀도가 높아집니다.\n");
					printf("주사위를 굴립니다. 또르륵...\n");

					srand((unsigned int)time(NULL));
					for (int i = 0; i < 1; i++) {
						int dice = rand() % 6 + 1;
						if (dice > 4) {
							printf("%d이(가) 나왔습니다!\n", dice);
							if (frdshp < 4) {
								printf("친밀도가 높아집니다.\n");
								frdshp += 1;
							}
							else {
								printf("이미 친밀도가 최대입니다.\n");
							}
						}
						else if (dice <= 4) {
							printf("%d이(가) 나왔습니다!\n", dice);
							printf("친밀도는 그대로입니다.\n");
						}
					}
					break;
				}
				else {
				}
			}
			printf("현재 친밀도: %d\n", frdshp);

			Sleep(2500);
			system("cls");

		}
	}

	return 0;
}