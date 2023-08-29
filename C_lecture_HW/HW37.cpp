#pragma warning(disable : 4996)
#include <stdio.h>

int main()
{
	int n, gold = 0, day = 0, count;
	printf("* 기사의 근무일수를 입력하시오 : ");
	while (scanf("%d", &n) != 1 || n<=0) {
		while (getchar() != '\n');
		printf("다시 입력하세요 : ");
	}
	for (int i = 1; i <= n; i++)
	{
		count = 1;
		while (count <= i)
		{
			if (day == n)
				break;
			gold += i;
			count++;
			day++;
		}
		if (day == n)
			break;
	}
	printf("  근무일 : %d일 / 총 금화 수 : %d개.\n", n, gold);
	return 0;
}