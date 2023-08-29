#pragma warning (disable : 4996)
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void randAry(int(*)[5]);
void sumAry(int(*)[5], int*, int*, int*);
void print(int(*)[5], int, int, int);

int main()
{
	int ary[5][5], sum1 = 0, sum2 = 0, sum3 = 0;
	srand((unsigned)time(NULL));
	randAry(ary);
	sumAry(ary, &sum1, &sum2, &sum3);
	print(ary, sum1, sum2, sum3);
}

void randAry(int(*ary)[5])
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			ary[i][j] = rand() % 20 + 1;
}

void sumAry(int(*ary)[5], int *sum1, int *sum2, int *sum3)
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
		*sum1 += ary[i][i];
	for (int i = 0; i < 4; i++)
		for (int j = i + 1; j < 5; j++)
			*sum2 += ary[i][j];
	for (int i = 0; i < 4; i++)
		for (int j = i + 1; j < 5; j++)
			*sum3 += ary[j][i];
}

void print(int(*ary)[5], int sum1, int sum2, int sum3)
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			printf("%3d", ary[i][j]);
		printf("\n");
	}
	/*int sum = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			sum += ary[i][j];
	printf("\nsum=%d\nsum=%d\n", sum, sum1 + sum2 + sum3);*/// 확인코드
	printf("\nsum1 = %d\nsum2 = %d\nsum3 = %d\n", sum1, sum2, sum3);
}