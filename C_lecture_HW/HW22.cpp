#pragma warning(disable : 4996)
#include <stdio.h>
int input(const char*);

int main()
{
	int n = input("#정수값을 입력하세요 : ");
	for (int i = 0; i < n; i++)
	{
		if (i % 5 == 0 && i != 0)
			printf("\n");
		printf("*");
	}
	return 0;
}

int input(const char* msg)
{
	int n;
	printf(msg);
	scanf("%d", &n);
	return n;
}