#pragma warning(disable : 4996)
#include <stdio.h>
int a_input(void);
int calcul(int);
void a_print(int);

int main()
{
	a_print(calcul(a_input()));
	return 0;
}

int a_input(void)
{
	int a;
	printf("역수를 입력하시오 : ");
	scanf("%d", &a);
	return a;
}

int calcul(int a)
{
	if (a <= 5)
		return 600;
	else if (a <= 10)
		return 800;
	else
		return 800 + ((a - 11) / 2 + 1) * 100;
}

void a_print(int charge)
{
	printf("요금 : %d원\n", charge);
}