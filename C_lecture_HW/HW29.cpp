#pragma warning(disable : 4996)
#include <stdio.h>
int transNumber(int);
int inputUInt(int, const char*);
void print(int);

int main()
{
	int p1, p2, n, i, k, N = 0, count = 0;
	p1 = inputUInt(1, "시작 값(P1) : ");
	p2 = inputUInt(1, "끝 값(P2) : ");
	n = inputUInt(2, "고집수(N) : ");
	printf("고집수가 %d인 숫자 출력\n", n);
	for (i = p1; i < p2; i++)
	{
		N = 0;
		k = transNumber(i);
		N++;
		while (k > 10)
		{
			k = transNumber(k);
			N++;
		}
		if (N == n)
		{
			printf("%d\n", i);
			count++;
		}
	}
	print(count);
	return 0;
}

int transNumber(int num)
{
	if (num < 100) // 2자리
	{
		return (num / 10) * (num % 10);
	}
	else if (num < 1000) // 3자리
	{
		return (num / 100) * ((num % 100) / 10) * (num % 100 % 10);
	}
	else if (num < 10000) // 4자리
	{
		return (num / 1000) * ((num % 1000) / 100) * (((num % 1000) % 100) / 10) * (((num % 1000) % 100) % 10);
	}
	else
		return 0;
}

int inputUInt(int a, const char* msg)
{
	int n;
	printf(msg);
	switch (a) {
	case 1:
		while (1) {
			if (scanf("%d", &n) == 1)
				if (n >= 100 && n <= 10000)
					break;
			while (getchar() != '\n');
			printf("다시 입력하세요 : ");
		}
		break;
	case 2:
		while (1) {
			if (scanf("%d", &n) == 1)
				if(n >= 1 && n <= 10)
				break;
			while (getchar() != '\n');
			printf("다시 입력하세요 : ");
		}
	}
	return n;
}

void print(int count)
{
	printf("총 개수 : % d개", count);
}