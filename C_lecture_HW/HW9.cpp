#pragma warning(disable : 4996)
#include <stdio.h>
int int_input(void);

int main()
{
	int number;
	number = int_input();
	printf("입력된 값은 8진수로 %#o 입니다.\n", number);
	printf("입력된 값은 16진수로 %#x 입니다.\n", number);
	return 0;
}

int int_input(void)
{
	int x;
	printf("정수값을 입력하세요 : ");
	scanf("%d", &x);
	return x;
}