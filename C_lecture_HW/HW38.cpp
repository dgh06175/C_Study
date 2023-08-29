#pragma warning (disable : 4996)
#include <stdio.h>

int main()
{
	int money, money1, money2, Cream_p = 500, Shrimp_p = 700, Cola_p = 400, count;
	printf("현재 당신의 소유 금액 입력 : ");
	while (scanf("%d", &money))
	{
		money2 = money;
		count = 0;
		if (money >= 1600){
			for (int i = 1; i <= (money - (Shrimp_p + Cola_p)) / Cream_p; i++){
				money1 = money;
				money -= Cream_p * i;
				for (int j = 1; j <= (money - Cola_p) / Shrimp_p; j++){
					money2 = money;
					money -= Shrimp_p * j;
					if (money % Cola_p == 0){
						printf("크림빵(%d 개), 새우깡(%d 봉지), 콜라(%d 병)\n", i, j, money / Cola_p);
						count++;
					}
					money = money2;
				}
				money = money1;
			}
			if (count != 0)
				printf("어떻게 구입하시겠습니까?\n\n현재 당신의 소유 금액 입력 : ");
			else
				printf("잔돈이 남습니다. 다시 입력해주세요 : ");
		}
		else
			printf("다시 입력해 주세요 : ");
	}
	return 0;
}