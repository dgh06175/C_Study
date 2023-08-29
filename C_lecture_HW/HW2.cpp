#pragma warning(disable : 4996)
#include <stdio.h>

int main(void)
{
	int money, m50000, m10000, m5000, m1000, m500, m100, m50, m10, charge;
	printf("돈의 액수를 입력하시오 : ");
	scanf("%d", &money);
	m50000 = money / 50000;
	charge = money - m50000 * 50000;

	m10000 = charge / 10000;
	charge = charge - m10000 * 10000;

	m5000 = charge / 5000;
	charge = charge - m5000 * 5000;

	m1000 = charge / 1000;
	charge = charge - m1000 * 1000;

	m500 = charge / 500;
	charge = charge - m500 * 500;

	m100 = charge / 100;
	charge = charge - m100 * 100;

	m50 = charge / 50;
	charge = charge - m50 * 50;

	m10 = charge / 10;
	charge = charge - m10 * 10;
	
	printf("50000원권 => %d개\n", m50000);
	printf("10000원권 => %d개\n", m10000);
	printf("5000원권 => %d개\n", m5000);
	printf("1000원권 => %d개\n", m1000);
	printf("500원권 => %d개\n", m500);
	printf("100원권 => %d개\n", m100);
	printf("50원권 => %d개\n", m50);
	printf("10원권 => %d개\n", m10);

	return 0;
}