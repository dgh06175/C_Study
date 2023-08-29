#pragma warning (disable : 4996)
#include <stdio.h>
#include <math.h>
int input(void);
int primeNumber(int);

int main()
{
	int num, count = 0;
	num = input();
	printf("1 ~ %d까지의 소수 값은 다음과 같습니다.\n", num);
	for (int i = 2; i < num; i++)
	{
		if (primeNumber(i) == 1) {
			printf("%-5d", i);
			count++;
			if (count % 5 == 0) printf("\n");
		}
	}
	printf("\n1 ~ %d까지의 총 소수는 %d개 입니다.\n", num, count);
}

int input(void)
{
	int n;
	printf("*정수값 하나를 입력하시오 : ");
	while (scanf("%d", &n) != 1) {
		while (getchar() != '\n');
		printf("다시 입력하세요 : ");
	}
	return n;
}

int primeNumber(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0) return 0;
	}
	return 1;
}