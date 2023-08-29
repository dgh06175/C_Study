#pragma warning(disable : 4996)
#include <stdio.h>
int input(const char *);

int main()
{
	int count = 0, g;
	while (count < 10)
	{
		g = input("# 계란의 무게를 입력하세요(단위 : g) : ");
		if (g >= 150 && g <= 500)
			printf("현재 달걀의 수 : %d\n", ++count);
		else if (g < 150)
			printf("메추리알 가지고 장난하지 마시오~ ^^\n");
		else
			printf("타조알 가지고 장난하지 마시오~ ^^\n");
	}
	printf("달걀 표장이 끝났습니다.\n");
	return 0;
}

int input(const char* msg)
{
	int g;
	printf(msg);
	while (scanf("%d", &g) != 1) {
		while (getchar() != '\n');
		printf("다시 입력하세요 : ");
	}
	return g;
}