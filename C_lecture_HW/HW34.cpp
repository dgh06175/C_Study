#pragma warning(disable : 4996)
#include <stdio.h>
void input(int*, int*);
int calcul(int, int);
void print(int, int, int);

int main()
{
	int code, use;
	input(&code, &use);
	print(code, use, calcul(code, use));
	return 0;
}

void input(int *pcode, int *puse)
{
	printf("* 사용자 코드를 입력하시오(1:가정용/2:상업용/3:공업용) : ");
	while (scanf("%d", pcode) != 1) {
		while (getchar() != '\n');
		printf("다시 입력하세요 : ");
	}
	printf("* 사용량을 입력하시오(ton단위) : ");
	while (scanf("%d", puse) != 1) {
		while (getchar() != '\n');
		printf("다시 입력하세요 : ");
	}
}

int calcul(int code, int use)
{
	int per_ton = 0;
	switch (code)
	{
	case 1: per_ton = 50; break;
	case 2: per_ton = 45; break;
	case 3: per_ton = 30; break;
	default: printf("잘못 입력하셨습니다.\n");
	}
	return (double)per_ton * (double)use * 1.05;
}

void print(int code, int use, int charge)
{
	char code_string[3][10] = { "가정용", "상업용", "공업용" };
	printf("\n# 사용자코드 : %d(%s)\n", code, code_string[code-1]);
	printf("# 사용량 : %d ton\n", use);
	printf("# 총수도요금 : %d원\n", charge);
}