#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
void input(int*, int);
void calcul(int*, int*, int);

int main()
{
	int n, *ary;
	printf("* 입력할 숫자의 개수 : ");
	scanf("%d", &n);
	ary = (int*)malloc(sizeof(int) * n);
	if (ary == NULL)return 1;
	int* arr = (int*)calloc(n, sizeof(int));
	if (arr == NULL) return 1;
	input(ary, n);
	calcul(ary, arr, n);
	free(ary);
}

void input(int *ary, int n)
{
	printf("* 숫자 입력 : ");
	for (int i = 0; i < n; i++)
		scanf("%d", (ary + i));
}

void calcul(int *ary, int *arr, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++) {
			if (ary[i] == ary[j])
				arr[i] += 1;
		}
		if (arr[i] == 0) sum++;
	}
	printf("  서로 다른 수의 개수 : %d\n", sum);
	free(arr);
}