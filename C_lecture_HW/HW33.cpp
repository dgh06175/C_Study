#pragma warning(disable : 4996)
#include <stdio.h>
int menu(void);
int openFan(void);
int offFan(void);
int reverseFan(int);
void displayFan(int);

int main()
{
	int mu;
	unsigned char state = 0;
	displayFan(state);
		while (1) {
		mu = menu();
		if (mu == 1) {
			state = state | openFan();
			displayFan(state);
		}
		else if (mu == 2) {
			state = state & offFan();
			displayFan(state);
		}
		else if (mu == 3) {
			state = reverseFan(state);
			displayFan(state);
		}
		else
			break;
	}
		return 0;
}

int menu(void)
{
	int n;
	printf("\n1. 환풍구 열기 / 2. 환풍구 닫기 / 3. 환풍구 전체 전환 / 4. 종료 : ");
	while (scanf("%d", &n) != 1 || n > 4 || n < 1)
	{
		while (getchar() != '\n');
		printf("잘못 입력하셨습니다.\n");
	}
	while (getchar() != '\n');
	return n;
}

int openFan(void)
{
	int n;
	printf("-----------------------------------------------------------------\n");
	printf("\t\t\tFan 열기 작업 실행 화면\n");
	printf("-----------------------------------------------------------------\n");
	printf(" * OPEN할 FAN 번호를 입력하시오(1-8) : ");
	while (scanf("%d", &n) != 1 || n < 1 || n > 8)
	{
		while (getchar() != '\n');
		printf("잘못 입력하셨습니다.\n");
	}
	while (getchar() != '\n');
	return 1 << (n - 1);
}

int offFan(void)
{
	int n;
	printf("-----------------------------------------------------------------\n");
	printf("\t\t\tFan 닫기 작업 실행 화면\n");
	printf("-----------------------------------------------------------------\n");
	printf(" * CLOSE할 FAN 번호를 입력하시오(1-8) : ");
	while (scanf("%d", &n) != 1 || n < 1 || n > 8)
	{
		while (getchar() != '\n');
		printf("잘못 입력하셨습니다.\n");
	}
	while (getchar() != '\n');
	return 0x00FF - (1 << (n - 1));
}

int reverseFan(int state)
{
	printf("-----------------------------------------------------------------\n");
	printf("\t\t\tFan 전체 전환 작업 실행 화면\n");
	printf("-----------------------------------------------------------------\n");
	printf("전체 FAN의 상태가 전환되었습니다. (ON, OFF 상태 뒤바뀜)\n");
	return 0x00FF - state;
}

void displayFan(int num)
{
	int res;
	printf("-----------------------------------------------------------------\n");
	for (int i = 8; i > 0; i--)
		printf("%d번FAN  ", i);
	printf("\n");
	for (int j = 7; j >= 0; j--)
	{
		res = num & 1 << j;
		if (res != 0)
			printf("  ON    ");
		else
			printf("  OFF   ");
	}
	printf("\n-----------------------------------------------------------------\n\n");
}