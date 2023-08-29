#pragma warning(disable : 4996)
#include <stdio.h>
double info_input(void);
double bmi_cal(double, double);
void print_info(double);
int main()
{
	double bmi = info_input();
	print_info(bmi);
	return 0;
}

double info_input(void)
{
	double weight, height;
	printf("몸무게를 입력하세요(kg) : ");
	scanf("%lf", &weight);
	printf("키를 입력하세요(m) : ");
	scanf("%lf", &height);
	return bmi_cal(weight, height);
}

double bmi_cal(double weight, double height)
{
	return weight / (height * height);
}

void print_info(double bmi)
{
	if (bmi < 18.5)
		printf("당신의 BMI는 %.1lf으로 저체중 입니다.\n", bmi);
	else if (bmi < 25.0)
		printf("당신의 BMI는 %.1lf으로 정상체중 입니다.\n", bmi);
	else if (bmi < 30.0)
		printf("당신의 BMI는 %.1lf으로 과체중 입니다.\n", bmi);
	else if (bmi < 40.0)
		printf("당신의 BMI는 %.1lf으로 비만 입니다.\n", bmi);
	else
		printf("당신의 BMI는 %.1lf으로 고도비만 입니다.\n", bmi);
}