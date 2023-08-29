#pragma warning(disable : 4996)
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int input(const char*);
void output(int, int);

int main()
{
	int n = 0, ans, count = 0;
	srand((unsigned int)time(NULL));
	ans = rand() % 100 + 1;
	int a = 0, b = 100;
	while (1)
	{
		n = input("# 숫자를 입력하시오 : ");
		if (ans != n) {
			if (ans < n) 
				b = n;
			else
				a = n;
		}
		count++;
		if (n == ans) break;
		output(a, b);
	}
	printf("우와~ 맞았당~~~ 추카추카~~ %d번째 만에 맞추셨습니다.\n", count);
	return 0;
}

int input(const char* msg)
{
	int n;
	while (1) {
		printf(msg);
		scanf("%d", &n);
		while (getchar() != '\n');
		if (n >= 1 && n<=100) break;
	}
	return n;
}

void output(int a, int b)
{
	printf("%d 보다는 크고 %d 보다는 작습니다.\n", a, b);
}