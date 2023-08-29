#pragma warning(disable : 4996)
#include <stdio.h>
double inputF(void);
void printC(double c);

int main()
{
	double f = inputF();
	printC(((double)5 / 9) * (f - 32));
	return 0;
}

double inputF(void)
{
	double f;
	printf("화씨 온도를 입력하세요 : ");
	scanf("%lf", &f);
	return f;
}

void printC(double c)
{
	printf("섭씨 온도는 %.1lf도 입니다.\n", c);
}