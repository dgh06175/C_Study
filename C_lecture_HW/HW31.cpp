#pragma warning(disable : 4996)
#include <stdio.h>
char menu(void);
int inputInt(const char*);
int deposit(void);
int withdraw(int);

int main()
{
	char option;
	int money = 0;
	printf("* 현재 잔액은 0원 입니다.\n\n");
	while (1)
	{
		option = menu();
		if (option == 'i')
		{
			money += deposit();
			printf("* 현재 잔액은 %d원 입니다.\n\n", money);
		}
		else if (option == 'o')
		{
			money += withdraw(money);
			printf("* 현재 잔액은 %d원 입니다.\n\n", money);
		}
		else if (option == 'q')
		{
			break;
		}
		else
			printf("* 잘못 입력하셨습니다.\n\n");
	}
	return 0;
}

char menu(void)
{
	char op;
	printf("# 메뉴를 입력하시오(i-입금, o-출금, q-종료) : ");
	scanf(" %c", &op);
	while (getchar() != '\n');
	return op;
}

int inputInt(const char* msg)
{
	int money;
	printf(msg);
	while (scanf("%d", &money) != 1 || money < 0) {
		while (getchar() != '\n');
		printf("* 잘못 입력하셨습니다. 다시 입력하세요 : ");
	}
	return money;
}

int deposit(void)
{
	return inputInt("# 입금액을 입력하세요 : ");
}

int withdraw(int money)
{
	int mon = inputInt("# 출금액을 입력하세요 : ");
	if (money < mon) {
		printf("* 잔액이 부족합니다.\n");
		return 0;
	}
	return -mon;
}
