#pragma warning (disable : 4996)
#include <stdio.h>

int main()
{
	int n, m;
	printf("# 출력 라인수를 입력하시오 : ");
	while (scanf("%d", &n)) {
		if (n <= 30 && n > 0)
		{
			m = 2 * n + 3;
			for (int i = 1; i <= n; i++)
			{
				for (int j = 0; j < i; j++)
				{
					printf("*");
				}
				for (int j = 0; j < m - 2 * i; j++)
				{
					printf(" ");
				}
				for (int j = 0; j < i; j++)
				{
					printf("*");
				}
				printf("\n");
			}
			printf("\n# 출력 라인수를 입력하시오 : ");
		}
		else printf("다시 입력하시오 : ");
	}
}