#include <stdio.h>
void printOptions()
{
	printf("섭씨를 화씨로 변경 : c 입력\n화씨를 섭씨로 변경 : f\n나가기 : q\n\n입력하시오 : ");
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
			printf("섭씨온도를 입력하시오 : ");
			scanf_s("%lf", &temp);
			printf("화씨온도는 %.2lf 입니다\n\n\n", CtoF(temp));
		}
		else if (choice == 'f')
		{
			printf("화씨온도를 입력하시오 : ");
			scanf_s("%lf", &temp);
			printf("섭씨온도는 %.2lf 입니다\n\n\n", FtoC(temp));
		}
		getchar();
	}
	return 0;
}