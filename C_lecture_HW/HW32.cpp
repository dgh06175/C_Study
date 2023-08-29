#pragma warning(disable : 4996)
#include <stdio.h>
int inputUint(const char*);
double inputDouble(const char*);
int ipow(int, int);
double fpow(double, int);

int main()
{
	int Inum, IN, FN, I;
	double Fnum, F;
	Inum = inputUint("* 양의 정수 밑을 입력 하시오 : ");
	IN = inputUint("* 양의 승을 입력 하시오 : ");
	I = ipow(Inum, IN);
	printf("%d의 %d승은 %d입니다.\n\n", Inum, IN, I);

	Fnum = inputDouble("* 양의 실수 밑을 입력 하시오 : ");
	FN = inputUint("* 양의 승을 입력 하시오 : ");
	F = fpow(Fnum, FN);
	printf("%.2lf의 %d승은 %.3lf입니다.\n", Fnum, FN, F);
	return 0;
}

int inputUint(const char* msg)
{
	int n;
	printf(msg);
	while (1) {
		scanf("%d", &n);
		while (getchar() != '\n');
		if (n >= 0)
			break;
		else
			printf("잘못 입력하셨습니다.\n");
	}
	return n;
}

double inputDouble(const char* msg)
{
	double n;
	printf(msg);
	while (1) {
		scanf("%lf", &n);
		while (getchar() != '\n');
		if (n >= 0.0)
			break;
		else
			printf("잘못 입력하셨습니다.\n");
	}
	return n;
}

int ipow(int num, int N)
{
	int a = 1;
	for (int i = 0; i < N; i++)
		a = a * num;
	return a;
}

double fpow(double num, int N)
{
	double a = 1;
	for (int i = 0; i < N; i++)
		a *= num;
	return a;
}
