#include <stdio.h>
void printOptions()
{
	printf("������ ȭ���� ���� : c �Է�\nȭ���� ������ ���� : f\n������ : q\n\n�Է��Ͻÿ� : ");
}
double CtoF(double C_temp)
{
	return C_temp*9/5 + 32;
}
double FtoC(double F_temp)
{
	return (F_temp - 32) / 9 * 5;
}

int main(void)
{
	double temp;
	char choice;
	while (1) {
		printOptions();
		choice = getchar();
		if (choice == 'q') break;
		else if (choice == 'c')
		{
			printf("�����µ��� �Է��Ͻÿ� : ");
			scanf_s("%lf", &temp);
			printf("ȭ���µ��� %.2lf �Դϴ�\n\n\n", CtoF(temp));
		}
		else if (choice == 'f')
		{
			printf("ȭ���µ��� �Է��Ͻÿ� : ");
			scanf_s("%lf", &temp);
			printf("�����µ��� %.2lf �Դϴ�\n\n\n", FtoC(temp));
		}
		getchar();
	}
	return 0;
}