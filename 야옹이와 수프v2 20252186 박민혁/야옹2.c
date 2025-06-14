#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

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

	int turn = 0;

	int soup = 0;
	int frdshp = 2;

	int cat_pos = HME_POS;
	int previous_pos = -1;

	int cat_feel = 3;
	int cp = 0;

	int toy_mouse = 0, laser_pointer = 0, scratcher = 0, cat_tower = 0;
	int scratcher_pos = -1, tower_pos = -1;

	while (1) {

		turn++;

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

		if (turn % 3 == 0) {
			printf("=== 돌발 이벤트 발생! ===\n");
			printf("[고양이 퀴즈]\n1번. 다음 중 실제 고양이에 대한 설명으로 '틀린 것'은?\n");
			printf("1. 고양이는 야행성이다.\n");
			printf("2. 고양이는 수영을 잘한다.\n");
			printf("3. 고양이는 수염이 있다.\n");
			printf("4. 고양이는 높은 곳을 좋아한다.\n");
			printf(">> ");
			int quiz_ans = 0;
			scanf_s("%d", &quiz_ans);
			if (quiz_ans == 2) {
				printf("정답입니다!\n");
			}
			else {
				printf("오답입니다. 정답은 2번입니다.\n");
			}
			Sleep(2000);
			system("cls");

			printf("[고양이 퀴즈]\n2번. 다음 중 실제 고양이에 대한 설명으로 '옳은 것'은?\n");
			printf("1. 고양이는 단맛을 매우 좋아해서 과일을 자주 먹는다.\n");
			printf("2. 모든 고양이는 발톱을 완전히 숨길 수 없다.\n");
			printf("3. 고양이는 평균적으로 100가지 이상의 소리를 낼 수 있다.\n");
			printf("4. 고양이는 태어나면서부터 앞발보다 뒷발이 먼저 발달한다.\n");
			printf(">> ");
			scanf_s("%d", &quiz_ans);
			if (quiz_ans == 3) {
				printf("정답입니다!\n");
			}
			else {
				printf("오답입니다. 정답은 3번입니다.\n");
			}
			Sleep(2000);
			system("cls");

			printf("[고양이 퀴즈]\n3번. 다음 중 고양이와 관련된 '과학적으로 정확한 설명'은 무엇일까요?\n");
			printf("1. 고양이의 소리내기 중 '그르릉'은 폐의 기도 진동에 의해 발생하며, 근육과 신경계의 고유반사 작용이 필수적이다.\n");
			printf("2. 고양이의 털 색깔은 오직 X염색체에 위치한 유전자들에 의해 결정되며, 수컷 고양이는 반드시 한 가지 색깔만 가진다.\n");
			printf("3. 고양이의 야행성 행동은 멜라토닌 수치가 낮기 때문이며, 이는 유전자 PER2와 직접 연관되어 있다.\n");
			printf("4. 고양이의 후각 수용체 유전자는 개에 비해 약 40% 더 많은 변이를 보여서, 후각 능력이 매우 떨어진다.\n");
			printf(">> ");
			scanf_s("%d", &quiz_ans);
			if (quiz_ans == 1) {
				printf("정답입니다!\n");
			}
			else {
				printf("오답입니다. 정답은 1번입니다.\n");
			}
			Sleep(2000);
			system("cls");

			printf("[고양이 퀴즈]\n4번. 다음 중 고양이에서 발견된 'Vomeronasal Organ (보모로나잘 기관)'의 역할과 관련된 진실은?\n");
			printf("1. 보모로나잘 기관은 고양이의 발톱 성장 속도를 조절하는 데 중요한 역할을 하며, 특히 생식기 호르몬과 연관되어 있다.\n");
			printf("2. 고양이의 보모로나잘 기관은 주로 페로몬 신호를 감지하며, 이를 통해 사회적 행동과 영역 표시를 조절하지만, 청각 자극과는 무관하다.\n");
			printf("3. 보모로나잘 기관은 고양이에게서만 발견되는 독특한 기관으로, 일반적인 포유류에는 존재하지 않는다.\n");
			printf("4. 이 기관은 고양이의 야행성 행동 조절에 직접 관여하며, 빛의 세기에 따라 활성도가 달라진다.\n");
			printf(">> ");
			scanf_s("%d", &quiz_ans);
			if (quiz_ans == 2) {
				printf("정답입니다!\n");
			}
			else {
				printf("오답입니다. 정답은 2번입니다.\n");
			}
			Sleep(2000);
			system("cls");
		}

		printf("%d-%d: 주사위 눈이 %d이하이면 그냥 기분이 나빠집니다.\n", 6, frdshp, 6 - frdshp);
		printf("주사위를 굴립니다. 또르륵...\n");

		previous_pos = cat_pos;
		int moved = 0;

		srand((unsigned int)time(NULL));
		for (int i = 0; i < 1; i++) {
			int dice = rand() % 6 + 1;
			printf("%d이(가) 나왔습니다.\n", dice);
			
			//야옹2 기분 나빠짐
			if (dice <= (6 - frdshp) && cat_feel > 0) {
				printf("%s의 기분이 나빠집니다: %d->%d\n", catname, cat_feel, cat_feel - 1);
				cat_feel--;
				if (cat_feel < 0) cat_feel = 0;
			}

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

			//야옹이 위치에 따른 행동
			//집
			if (cat_pos == HME_POS && previous_pos == HME_POS && cat_feel < 3) {
				cat_feel++;
				printf("집에서 한 턴을 쉬어서 기분이 좋아졌습니다.\n");
			}
			//냄비
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
			//스크래처
			if (cat_pos == scratcher_pos && scratcher) {
				if (cat_feel < 3) cat_feel++;
				printf("%s이(가) 스크래처를 긁고 놀았습니다. 기분이 조금 좋아졌습니다.\n", catname);
			}
			//z캣 타워
			if (cat_pos == tower_pos && cat_tower) {
				if (cat_feel <= 1) cat_feel += 2;
				else if (cat_feel == 2) cat_feel++;
				printf("%s이(가) 캣타워를 뛰어다닙니다. 기분이 제법 좋아졌습니다.\n", catname);
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
				else if (i == scratcher_pos) {
					printf("S");
				}
				else if (i == tower_pos) {
					printf("T");
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

			//상호작용
			int move;
			printf("어떤 상호작용을 하시겠습니까?\n0. 아무것도 하지 않음\n1. 긁어 주기\n");
			if (toy_mouse) printf("2. 장난감 쥐로 놀아 주기\n");
			if (laser_pointer) printf("3. 레이저 포인터로 놀아 주기\n");


			while (1) {
				printf(">> ");
				scanf_s("%d", &move);

				if (move == 0) {
					printf("아무것도 하지 않았습니다.\n");
					printf("%s의 기분이 나빠졌습니다: %d -> %d\n", catname, cat_feel, cat_feel - 1);
					cat_feel--;
					printf("주사위가 5 이하면 친밀도가 감소합니다.\n");
					printf("주사위를 굴립니다. 또르륵...\n");

					srand((unsigned int)time(NULL));
					for (int i = 0; i < 1; i++) {
						int dice = rand() % 6 + 1;
						if (dice > 5) {
							printf("%d이(가) 나왔습니다!\n", dice);
							printf("다행이 친밀도가 떨어지지 않았습니다.\n");
						}
						else if (dice <= 5) {
							printf("%d이(가) 나왔습니다!\n", dice);
							if (frdshp > 0) {
								printf("집사와의 관계가 나빠집니다.\n");
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
					printf("%s의 기분은 그대로 입니다: %d\n", catname, cat_feel);
					printf("친밀도는 주사위가 5 이상이면 증가합니다.\n");
					printf("주사위를 굴립니다. 또르륵...\n");

					srand((unsigned int)time(NULL));
					for (int i = 0; i < 1; i++) {
						int dice = rand() % 6 + 1;
						if (dice >= 5) {
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
				else if (move == 2 && toy_mouse) {
					if (cat_feel < 3) {
						printf("%s과(와) 장난감 쥐로 놀아주었습니다. %s의 기분이 조금 좋아졌습니다: %d -> %d\n", catname, catname, cat_feel, cat_feel + 1);
					}
					if (cat_feel >= 3) {
						printf("%s과(와) 장난감 쥐로 놀아주었습니다. %s의 기분이 조금 좋아졌습니다: %d -> %d\n", catname, catname, cat_feel, cat_feel);
					}
					if (cat_feel < 3) {
						cat_feel++;
					}
					if (dice >= 4 && frdshp < 4) {
						printf("친밀도가 올랐습니다.");
						frdshp++;
					}
					else {
						printf("친밀도는 그대로입니다.");
					}
					break;
				}
				else if (move == 3 && laser_pointer) {
					if (cat_feel <= 1) {
						printf("%s과(와) 레이저 포인터로 신나게 놀아주었습니다. %s의 기분이 꽤 좋아졌습니다: %d -> %d\n", catname, catname, cat_feel, cat_feel += 2);
						cat_feel += 2;
					}
					if (cat_feel == 2) {
						printf("%s과(와) 레이저 포인터로 신나게 놀아주었습니다. %s의 기분이 꽤 좋아졌습니다: %d -> %d\n", catname, catname, cat_feel, cat_feel += 1);
						cat_feel++;
					}
					if (cat_feel > 2) {
						printf("%s과(와) 레이저 포인터로 신나게 놀아주었습니다. %s의 기분이 꽤 좋아졌습니다: %d -> %d\n", catname, catname, cat_feel, cat_feel);
					}
					if (dice >= 2 && frdshp < 4) {
						printf("친밀도가 상승했습니다.");
						frdshp++;
					}
					else {
						printf("친밀도는 그대로입니다.");
					}
					break;
				}
				else {
				}
			}
			printf("현재 친밀도: %d\n", frdshp);

			//cp 생산
			int amount = (cat_feel - 1 >= 0 ? cat_feel - 1 : 0) + frdshp;
			cp += amount;
			printf("%s의 기분과 친밀도에 따라서 CP가 %d 포인트 생산되었습니다.\n보유 CP: %d 포인트\n", catname, amount, cp);

			//상점
			int buy;
			printf("상점에서 물건을 살 수 있습니다.\n0. 아무 것도 사지 않는다.\n");
			printf("1. 장난감 쥐: 1 CP%s\n", toy_mouse ? " (품절)" : "");
			printf("2. 레이저 포인터: 2 CP%s\n", laser_pointer ? " (품절)" : "");
			printf("3. 스크래처: 4 CP%s\n", scratcher ? " (품절)" : "");
			printf("4. 캣 타워: 6 CP%s\n", cat_tower ? " (품절)" : "");
			printf(">> ");
			scanf_s("%d", &buy);
			switch (buy) {
				case 1:
					if (toy_mouse) {
						printf("장난감 쥐를 이미 구매했습니다.\n");
					}
					else if (!toy_mouse && cp >= 1) { 
						toy_mouse = 1; cp -= 1; 
					}
					else if (cp < 1) {
						printf("CP가 부족합니다.\n");
					}
					break;
				case 2:
					if (laser_pointer) {
						printf("레이저 포인터를 이미 구매했습니다.\n");
					}
					else if (cp < 2) {
						printf("CP가 부족합니다.\n");
					}
					else if (!laser_pointer && cp >= 2) { 
						laser_pointer = 1; cp -= 2; 
					}
					break;
				case 3:
					if (scratcher) {
						printf("스크래처를 이미 구매했습니다.\n");
					}
					else if (cp < 4) {
						printf("CP가 부족합니다.\n");
					}
					else if (!scratcher && cp >= 4) {
						scratcher = 1; cp -= 4;
						do {
							scratcher_pos = rand() % (ROOM_WIDTH - 2) + 1;
						} 
						while (scratcher_pos == HME_POS || scratcher_pos == BWL_PO);
					}
					break;
				case 4:
					if (cat_tower) {
						printf("캣 타워를 이미 구매했습니다.\n");
					}
					else if (cp < 6) {
						printf("CP가 부족합니다.\n");
					}
					else if (!cat_tower && cp >= 6) {
						cat_tower = 1; cp -= 6;
						do {
							tower_pos = rand() % (ROOM_WIDTH - 2) + 1;
						} 
						while (tower_pos == HME_POS || tower_pos == BWL_PO || tower_pos == scratcher_pos);
					}
					break;
				default:
					break;
				}

			Sleep(2500);
			system("cls");
		}
	}

	return 0;
}