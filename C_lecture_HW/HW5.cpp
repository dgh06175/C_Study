#pragma warning(disable : 4996)
#define BASIC_CHARGE 660.0
#include <stdio.h>

int input_kw(void);
void print_price(double final_charge);

int main(void)
{
	double charge, tax, final_charge;
	int kw = input_kw();
	charge = BASIC_CHARGE + (kw * 88.5);
	tax = 0.09 * charge;
	final_charge = charge + tax;
	print_price(final_charge);
	return 0;
}

int input_kw(void)
{
	int use_kw;
	printf("전기 사용량을 입력하세요(kw) : ");
	scanf("%d", &use_kw);
	return use_kw;
}

void print_price(double final_charge)
{
	printf("전기 사용요금은 %lf원 입니다.\n", final_charge);
}
