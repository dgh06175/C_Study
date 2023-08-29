#pragma warning(disable : 4996)
#include <stdio.h>
int input(const char *);
int yearCheck(int);
void print(int, int);

int main()
{
	int year = input("년도를 입력하시오 : ");
	print(yearCheck(year), year);
}

int input(const char* msg)
{
	int year;
	printf(msg);
	scanf("%d", &year);
	return year;
}

int yearCheck(int year)
{
	if (year % 4 == 0)
		if (year % 100 == 0)
			if (year % 400 == 0)
				return 1;
			else
				return 0;
		else
			return 1;
	else
		return 0;
}

void print(int x, int year)
{
	if (x == 0)
		printf("%d년은 평년(Common year)입니다.\n", year);
	else
		printf("%d년은 윤년(Leap year)입니다.\n", year);
}