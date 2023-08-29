#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void printall(void);
void my_equipment(int*);
void basic_spec(double*, int);

struct equipment_info
{
	char name[20];
	int level;
	int price;
	int damage;
	int armor;
	int block;
	int hp;
	int strength;
	int hitrate;
	int cri;
	double deadly_strike;
	int move;
	int hp_regen;
	int exp;
	int magic_resist;
	int fire_resist;
	int ice_resist;
	int gray_set;
}equipment[12][20];// 0투구 1갑옷 2방패 3장갑 4신발 5반지 6목걸이 7망토 8벨트 9펫 10무기

char equip_part_name[][20] = { "투구", "갑옷", "방패", "장갑", "신발",
		"반지", "목걸이", "망토", "벨트", "펫", "무기", "레벨" };
char equipment_options[][20] = { "이름","레벨제한","가격","공격","방어력","막기","체력","힘","명중","크리티컬","죽음의일격","이동속도","체력재생","경험치","마법저항","불저항","얼음저항" };


/* 등록해놓은 물품들의 정보를 모두 출력하는 함수 */
void printall(void)
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (strcmp(equipment[i][j].name, "\0") != 0)
				printf("\n%s:%s\n", equipment_options[0], equipment[i][j].name);
			if (equipment[i][j].level != 0)
				printf("%s:%d\n", equipment_options[1], equipment[i][j].level);
			if (equipment[i][j].price != 0) {
				if (equipment[i][j].price < 100)
					printf("%s:%d0,000\n", equipment_options[2], equipment[i][j].price);
				else {
					if (equipment[i][j].price % 100 == 0)
						printf("%s:%d,000,000\n", equipment_options[2], equipment[i][j].price / 100);
					else
						printf("%s:%d,%d0,000\n", equipment_options[2], equipment[i][j].price / 100, equipment[i][j].price % 100);
				}
			}
			if (equipment[i][j].damage != 0)
				printf("%s:%d\n", equipment_options[3], equipment[i][j].damage);
			if (equipment[i][j].armor != 0)
				printf("%s:%d\n", equipment_options[4], equipment[i][j].armor);
			if (equipment[i][j].block != 0)
				printf("%s:%d\n", equipment_options[5], equipment[i][j].block);
			if (equipment[i][j].hp != 0)
				printf("%s:%d\n", equipment_options[6], equipment[i][j].hp);
			if (equipment[i][j].strength != 0)
				printf("%s:%d\n", equipment_options[7], equipment[i][j].strength);
			if (equipment[i][j].hitrate != 0)
				printf("%s:%d\n", equipment_options[8], equipment[i][j].hitrate);
			if (equipment[i][j].cri != 0)
				printf("%s:%d\n", equipment_options[9], equipment[i][j].cri);
			if (equipment[i][j].deadly_strike != 0)
				printf("%s:%.1lf\n", equipment_options[10], equipment[i][j].deadly_strike);
			if (equipment[i][j].move != 0)
				printf("%s:%d\n", equipment_options[11], equipment[i][j].move);
			if (equipment[i][j].move != 0)
				printf("%s:%d\n", equipment_options[12], equipment[i][j].hp_regen);
			if (equipment[i][j].move != 0)
				printf("%s:%d\n", equipment_options[13], equipment[i][j].exp);
			if (equipment[i][j].magic_resist != 0)
				printf("%s:%d\n", equipment_options[14], equipment[i][j].magic_resist);
			if (equipment[i][j].fire_resist != 0)
				printf("%s:%d\n", equipment_options[15], equipment[i][j].fire_resist);
			if (equipment[i][j].ice_resist != 0)
				printf("%s:%d\n", equipment_options[16], equipment[i][j].ice_resist);
		}
	}
}

/* 자신의 장비 정보를 저장하는 함수 */
void my_equipment(int* my)
{
	int MaxNumPartOfEquip;
	printf("캐릭터의 레벨을 입력하세요 :");
	while (scanf("%d", &my[11]) != 1 || my[11] < 1 || my[11] > 50) {
		while (getchar() != '\n');
		printf("다시 입력하세요 :");
	}
	for (int i = 0; i < 11; i++) // i는 장비번호(투구0~무기10)
	{
		MaxNumPartOfEquip = 0;
		for (int j = 0; j < 20; j++)
		{
			if (strcmp(equipment[i][j].name, "\0") != 0)
			{
				MaxNumPartOfEquip++;
				printf("%d. %s\n", j + 1, equipment[i][j].name); // 보기편하게 보이는건 0번을 1번으로 출력
			}
		}
		printf("당신의 %s을(를) 선택하세요(숫자) :", equip_part_name[i]);
		while (scanf("%d", &my[i]) != 1 || my[i] < 1 || my[i] > MaxNumPartOfEquip || equipment[i][my[i] - 1].level > my[11]) { // 문자와 범위를 벗어난 정수(1~50아님, 장비 착용 레벨 안됨) 입력시 재입력 요구
			while (getchar() != '\n');
			printf("다시 입력하세요 :");
		}
		my[i]--; // 보기편하게 1 크게 입력받은걸 다시 제값으로 돌림
		printf("\n");
	}
}

/* 캐릭터의 기본 스펙을 정해주는 함수 */
void basic_spec(double* status, int lvl)
{
	status[2] += (double)(lvl / 4); // 방어력
	status[4] +=(28.0 + 13.8 * (double)(lvl - 1.0)) - 1.0; // 체력 (내 캐릭 기준)
	status[5] += 14; // 힘
	status[9] += 100; // 이동속도
}

int main(void)
{
	//FILE* fp1 = fopen("memo.txt", "a");
	//fclose(fp1);
	//FILE* fp = fopen("memo.txt", "r+");
	//if (fp == NULL) // 파일 열기 실패시 종료
	//{
	//	printf("File open error\n");
	//	fclose(fp);
	//	return 0;
	//}

	strcpy(equipment[0][0].name, "+5 블랙주노투구");
	equipment[0][0].price = 45;
	equipment[0][0].level = 26;
	equipment[0][0].armor = 11;
	equipment[0][0].strength = 2;
	equipment[0][0].magic_resist = 5;

	strcpy(equipment[0][1].name, "+6 블랙주노투구");
	equipment[0][1].price = 130;
	equipment[0][1].level = 26;
	equipment[0][1].armor = 12;
	equipment[0][1].strength = 2;
	equipment[0][1].magic_resist = 5;

	strcpy(equipment[0][2].name, "+ 5 회색바위투구");
	equipment[0][2].price = 200;
	equipment[0][2].level = 24;
	equipment[0][2].armor = 11;
	equipment[0][2].strength = 1;
	equipment[0][2].gray_set = 1;

	strcpy(equipment[0][3].name, "+5 무쇠투구");
	equipment[0][3].price = 40;
	equipment[0][3].level = 30;
	equipment[0][3].armor = 12;
	equipment[0][3].strength = 4;
	
	strcpy(equipment[0][4].name, "+6 무쇠투구");
	equipment[0][4].price = 140;
	equipment[0][4].level = 30;
	equipment[0][4].armor = 13;
	equipment[0][4].strength = 4;

	strcpy(equipment[0][5].name, "+5 용맹의투구");
	equipment[0][5].price = 60;
	equipment[0][5].level = 34;
	equipment[0][5].armor = 13;
	equipment[0][5].strength = 5;
	equipment[0][5].fire_resist = 6;
	
	strcpy(equipment[0][6].name, "+6 용맹의투구");
	equipment[0][6].price = 180;
	equipment[0][6].level = 34;
	equipment[0][6].armor = 14;
	equipment[0][6].strength = 5;
	equipment[0][6].fire_resist = 6;
	
	strcpy(equipment[0][7].name, "+5 다크스틸투구");
	equipment[0][7].price = 450;
	equipment[0][7].level = 38;
	equipment[0][7].armor = 14;
	equipment[0][7].strength = 6;
	equipment[0][7].fire_resist = 6;

	strcpy(equipment[1][0].name, "+6 회색바위의갑옷");
	equipment[1][0].price = 260;
	equipment[1][0].level = 24;
	equipment[1][0].armor = 23;
	equipment[1][0].hp = 10;
	equipment[1][0].gray_set = 1;

	strcpy(equipment[1][1].name, "+6 하이가드갑옷");
	equipment[1][1].price = 210;
	equipment[1][1].level = 27;
	equipment[1][1].armor = 23;
	equipment[1][1].hp = 28;
	equipment[1][1].ice_resist = 3;

	strcpy(equipment[1][2].name, "+5 스케일아머");
	equipment[1][2].price = 180;
	equipment[1][2].level = 32;
	equipment[1][2].armor = 22;
	equipment[1][2].hp = 28;
	equipment[1][2].hp_regen = 1;
	
	strcpy(equipment[1][3].name, "+6 스케일아머");
	equipment[1][3].price = 210;
	equipment[1][3].level = 32;
	equipment[1][3].armor = 25;
	equipment[1][3].hp = 28;
	equipment[1][3].hp_regen = 1;
	
	strcpy(equipment[1][4].name, "+5 스틸아머");
	equipment[1][4].price = 90;
	equipment[1][4].level = 36;
	equipment[1][4].armor = 24;
	equipment[1][4].hp = 34;
	equipment[1][4].fire_resist = 11;
	
	strcpy(equipment[1][5].name, "+6 스틸아머");
	equipment[1][5].price = 600;
	equipment[1][5].level = 36;
	equipment[1][5].armor = 27;
	equipment[1][5].hp = 34;
	equipment[1][5].fire_resist = 11;

	strcpy(equipment[1][6].name, "+5 다크스틸아머");
	equipment[1][6].price = 410;
	equipment[1][6].level = 39;
	equipment[1][6].armor = 25;
	equipment[1][6].hp = 43;
	equipment[1][6].magic_resist = 11;
	
	strcpy(equipment[1][7].name, "+6 다크스틸아머");
	equipment[1][7].price = 600;
	equipment[1][7].level = 39;
	equipment[1][7].armor = 28;
	equipment[1][7].hp = 43;
	equipment[1][7].magic_resist = 11;

	strcpy(equipment[2][0].name, "+5 아이언쉴드");
	equipment[2][0].price = 5;
	equipment[2][0].level = 21;
	equipment[2][0].armor = 10;
	equipment[2][0].block = 11;
	equipment[2][0].hp = 14;
	equipment[2][0].fire_resist = 10;

	strcpy(equipment[2][1].name, "+5 수정쉴드");
	equipment[2][1].price = 30;
	equipment[2][1].level = 25;
	equipment[2][1].armor = 10;
	equipment[2][1].block = 13;
	equipment[2][1].hp = 19;
	equipment[2][1].ice_resist = 3;

	strcpy(equipment[2][2].name, "+6 수정쉴드");
	equipment[2][2].price = 77;
	equipment[2][2].level = 25;
	equipment[2][2].armor = 11;
	equipment[2][2].block = 13;
	equipment[2][2].hp = 19;
	equipment[2][2].ice_resist = 3;

	strcpy(equipment[2][3].name, "+5 타워쉴드");
	equipment[2][3].price = 60;
	equipment[2][3].level = 30;
	equipment[2][3].armor = 11;
	equipment[2][3].block = 13;
	equipment[2][3].hp = 30;
	equipment[2][3].fire_resist = 6;

	strcpy(equipment[2][4].name, "+5 철갑쉴드");
	equipment[2][4].price = 70;
	equipment[2][4].level = 35;
	equipment[2][4].armor = 12;
	equipment[2][4].block = 15;
	equipment[2][4].hp = 35;
	equipment[2][4].magic_resist = 7;
	
	strcpy(equipment[2][5].name, "+6 철갑쉴드");
	equipment[2][5].price = 500;
	equipment[2][5].level = 35;
	equipment[2][5].armor = 13;
	equipment[2][5].block = 15;
	equipment[2][5].hp = 35;
	equipment[2][5].magic_resist = 7;
	
	strcpy(equipment[2][6].name, "+5 다크스틸쉴드");
	equipment[2][6].price = 800;
	equipment[2][6].level = 40;
	equipment[2][6].armor = 13;
	equipment[2][6].block = 15;
	equipment[2][6].hp = 41;
	equipment[2][6].magic_resist = 10;

	strcpy(equipment[3][0].name, "+5 강화가죽장갑");
	equipment[3][0].price = 28;
	equipment[3][0].level = 13;
	equipment[3][0].armor = 8;
	equipment[3][0].hitrate = 6;

	strcpy(equipment[3][1].name, "+6 강화가죽장갑");
	equipment[3][1].price = 60; // 시세모름
	equipment[3][1].level = 13;
	equipment[3][1].armor = 9;
	equipment[3][1].hitrate = 6;

	strcpy(equipment[3][2].name, "+5 스케일장갑");
	equipment[3][2].price = 20;
	equipment[3][2].level = 27;
	equipment[3][2].armor = 10;
	equipment[3][2].hitrate = 3;
	equipment[3][2].strength = 2;

	strcpy(equipment[3][3].name, "+6 스케일장갑");
	equipment[3][3].price = 35;
	equipment[3][3].level = 27;
	equipment[3][3].armor = 11;
	equipment[3][3].hitrate = 3;
	equipment[3][3].strength = 2;
	
	strcpy(equipment[3][4].name, "+6 무쇠장갑");
	equipment[3][4].price = 200;
	equipment[3][4].level = 31;
	equipment[3][4].armor = 12;
	equipment[3][4].hitrate = 4;
	equipment[3][4].hp = 4;
	
	strcpy(equipment[3][5].name, "+5 강철골렘장갑");
	equipment[3][5].price = 140;
	equipment[3][5].level = 35;
	equipment[3][5].armor = 11;
	equipment[3][5].hitrate = 4;
	equipment[3][5].strength = 3;
	
	strcpy(equipment[3][6].name, "+6 강철골렘장갑");
	equipment[3][6].price = 1000;
	equipment[3][6].level = 35;
	equipment[3][6].armor = 12;
	equipment[3][6].hitrate = 4;
	equipment[3][6].strength = 4;


	/* 무쇠장갑, 강철골렘장갑 매물보고 추가하기 */

	strcpy(equipment[4][0].name, "+5 신속의장화");
	equipment[4][0].price = 8;
	equipment[4][0].level = 5;
	equipment[4][0].armor = 7;
	equipment[4][0].move = 5;

	strcpy(equipment[4][1].name, "+6 회색바위의장화");
	equipment[4][1].price = 260; //시세모름
	equipment[4][1].level = 24;
	equipment[4][1].armor = 12;
	equipment[4][1].strength = 1;
	equipment[4][1].gray_set = 1;

	strcpy(equipment[4][2].name, "+6 무쇠부츠");
	equipment[4][2].price = 35;
	equipment[4][2].level = 29;
	equipment[4][2].armor = 12;
	equipment[4][2].fire_resist = 3;
	
	strcpy(equipment[4][3].name, "+5 샤쿤그리브");
	equipment[4][3].price = 200;
	equipment[4][3].level = 32;
	equipment[4][3].armor = 11;
	equipment[4][3].strength = 2;
	equipment[4][3].move = 6;
	
	strcpy(equipment[4][4].name, "+6 샤쿤그리브");
	equipment[4][4].price = 380;
	equipment[4][4].level = 32;
	equipment[4][4].armor = 12;
	equipment[4][4].strength = 2;
	equipment[4][4].move = 6;
	/* 샤쿤그리브 매물보고 추가하기 */

	strcpy(equipment[5][0].name, "해적의반지");
	equipment[5][0].price = 1;
	equipment[5][0].level = 15;
	equipment[5][0].armor = 1;
	equipment[5][0].cri = 1;

	strcpy(equipment[5][1].name, "합금반지");
	equipment[5][1].price = 7;
	equipment[5][1].level = 24;
	equipment[5][1].armor = 1;
	equipment[5][1].cri = 2;
	
	strcpy(equipment[5][2].name, "힘1 대천사");
	equipment[5][2].price = 200;
	equipment[5][2].level = 33;
	equipment[5][2].armor = 2;
	equipment[5][2].cri = 2;
	equipment[5][2].hp = 12;
	equipment[5][2].strength = 1;

	strcpy(equipment[6][0].name, "레이븐목걸이");
	equipment[6][0].price = 3;
	equipment[6][0].level = 14;
	equipment[6][0].armor = 1;
	equipment[6][0].hp = 17;

	strcpy(equipment[6][1].name, "해적의목걸이");
	equipment[6][1].price = 33;
	equipment[6][1].level = 15;
	equipment[6][1].armor = 1;
	equipment[6][1].cri = 2;
	
	strcpy(equipment[6][2].name, "힘1 다크스컬");
	equipment[6][2].price = 260;
	equipment[6][2].level = 10;
	equipment[6][2].armor = 2;
	equipment[6][2].cri = 3;
	equipment[6][2].strength = 1;

	strcpy(equipment[7][0].name, "불도저망토");
	equipment[7][0].price = 5;
	equipment[7][0].level = 1;
	equipment[7][0].armor = 2;

	strcpy(equipment[7][1].name, "숙련모험가의망토");
	equipment[7][1].price = 0;
	equipment[7][1].level = 20;
	equipment[7][1].armor = 1;
	equipment[7][1].hp = 10;
	equipment[7][1].deadly_strike = 0.7;

	strcpy(equipment[7][2].name, "힘1 완망");
	equipment[7][2].price = 250;
	equipment[7][2].level = 8;
	equipment[7][2].armor = 2;
	equipment[7][2].hp = 20;
	equipment[7][2].deadly_strike = 1.0;
	equipment[7][2].strength = 1;

	strcpy(equipment[8][0].name, "매드가의벨트");
	equipment[8][0].price = 0;
	equipment[8][0].level = 9;
	equipment[8][0].armor = 2;
	equipment[8][0].hp = 10;

	strcpy(equipment[8][1].name, "힘1 신념의벨트");
	equipment[8][1].price = 35;
	equipment[8][1].level = 26;
	equipment[8][1].armor = 2;
	equipment[8][1].hp = 9;
	equipment[8][1].strength = 1;
	
	strcpy(equipment[8][2].name, "체10 티타늄벨트");
	equipment[8][2].price = 400;
	equipment[8][2].level = 36;
	equipment[8][2].armor = 2;
	equipment[8][2].hp = 26;
	equipment[8][2].hp_regen = 16;



	strcpy(equipment[9][0].name, "일반펫");
	equipment[9][0].price = 9;
	equipment[9][0].level = 8;
	equipment[9][0].exp = 3;
	equipment[9][0].cri = 1;
	equipment[9][0].deadly_strike = 14.3;
	equipment[9][0].hp = 124;

	strcpy(equipment[9][1].name, "힘+2 일반펫");
	equipment[9][1].price = 19;
	equipment[9][1].level = 8;
	equipment[9][1].exp = 3;
	equipment[9][1].strength = 2;
	equipment[9][1].cri = 1;
	equipment[9][1].deadly_strike = 14.2;
	equipment[9][1].hp = 123;

	strcpy(equipment[9][2].name, "힘+3 레어펫");
	equipment[9][2].price = 60;
	equipment[9][2].level = 9;
	equipment[9][2].exp = 3;
	equipment[9][2].strength = 3;
	equipment[9][2].cri = 1;
	equipment[9][2].deadly_strike = 15.3;
	equipment[9][2].hp = 124;

	strcpy(equipment[10][0].name, "+7 글라디우스");
	equipment[10][0].price = 110;
	equipment[10][0].level = 27;
	equipment[10][0].damage = 47;
	equipment[10][0].hitrate = 3;

	strcpy(equipment[10][1].name, "+8 글라디우스");
	equipment[10][1].price = 420;
	equipment[10][1].level = 27;
	equipment[10][1].damage = 48;
	equipment[10][1].hitrate = 3;

	strcpy(equipment[10][2].name, "+7 백색레이피어");
	equipment[10][2].price = 1000;
	equipment[10][2].level = 30;
	equipment[10][2].damage = 57;
	equipment[10][2].hitrate = 4;
	equipment[10][2].cri = 2;
	equipment[10][2].strength = 3;

	strcpy(equipment[10][3].name, "+7 레이피어");
	equipment[10][3].price = 500;
	equipment[10][3].level = 32;
	equipment[10][3].damage = 52;
	equipment[10][3].hitrate = 6;
	equipment[10][3].strength = 4;

	strcpy(equipment[10][4].name, "+7 룬블레이드");
	equipment[10][4].price = 600;
	equipment[10][4].level = 35;
	equipment[10][4].damage = 57;
	equipment[10][4].hitrate = 5;
	equipment[10][4].strength = 5;
	equipment[10][4].magic_resist = 11;

	strcpy(equipment[10][5].name, "+7 다크스틸소드");
	equipment[10][5].price = 600;
	equipment[10][5].level = 38;
	equipment[10][5].damage = 61;
	equipment[10][5].hitrate = 6;

	strcpy(equipment[10][5].name, "+8 다크스틸소드");
	equipment[10][5].price = 2000;
	equipment[10][5].level = 38;
	equipment[10][5].damage = 62;
	equipment[10][5].hitrate = 6;

	int my[12];/*= {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28};*/ // 내 장비, 레벨정보 저장할 배열
	double status[16] = { 0.0, };
	// 0:price 1:damage 2:armor 3:block 4:hp 5:strength 6:hitrate 7:cri 8:deadly_strike
	// 9:move 10: hp_regen 11:exp 12:magic_resist 13:fire_resist 14:ice_resist
	my_equipment(my);
	basic_spec(status, my[11]);
	// printall();

	for (int i = 0; i < 11; i++) {
		int j = 0;
		status[j] += (double)equipment[i][my[i]].price; //0
		j++;
		status[j] += (double)equipment[i][my[i]].damage; //1
		j++;
		status[j] += (double)equipment[i][my[i]].armor; //2
		j++;
		status[j] += (double)equipment[i][my[i]].block; //3
		j++;
		status[j] += (double)equipment[i][my[i]].hp; //4
		j++;
		status[j] += (double)equipment[i][my[i]].strength; //5
		j++;
		status[j] += (double)equipment[i][my[i]].hitrate; //6
		j++;
		status[j] += (double)equipment[i][my[i]].cri; //7
		j++;
		status[j] += (double)equipment[i][my[i]].deadly_strike; //8
		j++;
		status[j] += (double)equipment[i][my[i]].move; //9
		j++;
		status[j] += (double)equipment[i][my[i]].hp_regen; //10
		j++;
		status[j] += (double)equipment[i][my[i]].exp; //11
		j++;
		status[j] += (double)equipment[i][my[i]].magic_resist; //12
		j++;
		status[j] += (double)equipment[i][my[i]].fire_resist; //13
		j++;
		status[j] += (double)equipment[i][my[i]].ice_resist; //14
		j++;
		status[j] += (double)equipment[i][my[i]].gray_set; //15
	}
	printf("캐릭터의 전체 스펙은\n");
	if (status[15] >= 2) {
		status[4] += 40;
		if (status[15] == 3) {
			status[5] += 3;
			status[9] += 5;
		}
	}
	for (int i = 0; i < 15; i++)
	{
		if (i == 8)printf("%s:%.1lf\n", equipment_options[i + 2], status[i]);
		else if (i == 9)printf("%s:%.0lf%%\n", equipment_options[i + 2], status[i]);
		else printf("%s:%.0lf\n", equipment_options[i + 2], status[i]);
	}

	/*for (int i = 0; i < 12; i++) // 입력한 장비, 레벨의 정보 출력해서 미리보기
		printf("%d\n", my[i]);*/

	// my_equipment() 매번 넣기 귀찮아서 int my에 임의로 값 넣어둠!!!
}