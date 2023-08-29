#pragma warning(disable:4996)
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX_NUM 13
#define MAX_SYM 4

int main()
{
	int x, i, j, k, l, m, n, o, r, random, pair;
	char exit = '\0';
	char* num[MAX_NUM] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
	char* sym[MAX_SYM] = { "♥","◆","♠","♣" };
	srand((unsigned)time(NULL));
	printf("플레이어 수를 입력하세요 (1~5명) :");
	while (scanf("%d", &x) != 1 || x <1 || x > 5) {
		while (getchar() != '\n');
		printf("다시 입력하세요 : ");
	}
	while (getchar() != '\n');
	while (exit != 'z') {
		for (k = 0; k < x; k++)
		{
			int card[5] = { -1,-1,-1,-1,-1 };
			i = 0;
			while (i != 5)
			{
				random = rand() % (MAX_NUM * MAX_SYM); // 총 52장의 카드중 1개 택 (random = 0~52)
				n = 0;
				for (j = 0; j < i; j++)
					if (random == card[j]) n++; // 이전에 뽑은 카드중에 중복이 있을 경우 n++
				if (n == 0)
				{
					card[i] = random;
					i++;
				}
			}
			int p[5] = { 0, };

			for (m = 0; m < 5; m++)
				for (o = m + 1; o < 5; o++)
					if (card[m] % MAX_NUM == card[o] % MAX_NUM) p[m]++;
			pair = p[0];
			for (r = 0; r < 5; r++)
				if (pair < p[r])
					pair = p[r];
			for (l = 0; l < 5; l++) {
				printf("%2s%s", num[card[l] % MAX_NUM], sym[card[l] % MAX_SYM]);
				if (l < 4) printf(",");
			}
			switch (pair) {
			case 1: printf(" pair"); break;
			case 2: printf(" triple"); break;
			case 3: printf(" four card"); break;
			default: break;
			}
			printf("\n\n");
		}
		printf("그만두려면 'z'를 입력하세요: ");
		scanf("%c", &exit);
	}
}