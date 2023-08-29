#pragma warning(disable : 4996)
#include <stdio.h>

int main()
{
	unsigned int num, res;
	while (1) {
		printf("* 10진수 정수를 입력하시오 : ");
		if (scanf("%d", &num) == 1)
			break;
		while (getchar() != '\n');
	}
	printf("%d(10) = ",num);
	for (int i = 31; i >= 0; i--)
	{
		res = num & 1<<i;
		if (res != 0)
			printf("1");
		else
			printf("0");
	}
	printf("(2)\n");
	return 0;
}