#pragma warning(disable : 4996)
#include <stdio.h>
int fibo(int);

int main()
{
	int N, f, sum = 0;
	printf("피보나치 수열의 항수를 입력하시오 : ");
	while (scanf("%d", &N) != 1 || N<=0) {
		while (getchar() != '\n');
		printf("다시 입력하세요 : ");
	}
	for (int i = 0; i < N; i++)
	{
		f = fibo(i + 1);
		sum += f;
		if (i != N-1)
			printf("%d + ", f);
		else
			printf("%d = %d", f, sum);
	}
	return 0;
}

int fibo(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return fibo(n - 1) + fibo(n - 2);
}