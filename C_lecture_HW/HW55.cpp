#pragma warning (disable : 4996)
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void random(int (*)[4]);
void print(int(*)[4]);

int main()
{
	int num[3][4];
	random(num);
	print(num);
}

void random(int (*num)[4])
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4; j++)
			num[i][j] = rand() % 9 + 1;
}

void print(int(*num)[4])
{
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			sum += num[i][j];
			if (j == 0)printf("%d행\t:", i);
			printf("%3d", num[i][j]);
			if (j == 3)printf("\t%d행의 합 : %d", i, sum);
		}
		printf("\n"); sum = 0;
	}
	printf("열의 합 :");
	for (int i = 0; i < 4; i++) {
		sum = 0;
		for (int j = 0; j < 3; j++) {
			sum += num[j][i];
		}
		printf("%3d", sum);
	}

}