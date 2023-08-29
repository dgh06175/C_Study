#pragma warning (disable : 4996)
#include <stdio.h>
int input(int *);
void sort(int *, int);
void print(int *, int , int);

int main()
{
	int ary[1000];
	int len = 0;
	for (int i = 0; i < 3; i++)
	{
		printf("\n%d차 데이터를 집어넣으시오 (0입력시 중지) : ", i + 1);
		len = input(ary);
		print(ary, len, 0);
		sort(ary, len);
		print(ary, len, 1);
	}
}

int input(int* ary)
{
	int i = 0;
	while (1) {
		scanf("%d", &ary[i]);
		if (ary[i] == 0) break;
		++i;
	}
	return i;
}

void sort(int* ary, int len)
{
	int min, tmp, index;

	for (int i = 0; i < len; i++){
		min = 9999;
		for (int j = i; j < len; j++) {
			if (min > ary[j]) {
				min = ary[j];
				index = j;
			}
		}
		tmp = ary[i];
		ary[i] = ary[index];
		ary[index] = tmp;
	}
}

void print(int* ary, int len, int mode)
{
	char chr[2][3] = { "전", "후" };
	printf("# 소트 %s 데이터 : ", chr[mode]);
	for (int i = 0; i < len; i++)
		printf("%d ", ary[i]);
	printf("\n");
}