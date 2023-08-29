#pragma warning (disable : 4996)
#include <stdio.h>
void input(int *);
int yearCheck(int);
int cal_days(int, int, int);
void print(int, int, int, int);

int main()
{
	int a, days[3];
	input(days);
	a = cal_days(days[0], days[1], days[2]);
	print(days[0], days[1], days[2], a);
	return 0;
}

void input(int *a)
{
	printf("* 년 월 일을 입력하시오 : ");
	int n, m = 0;
	while (m == 0) { //문자 거르기
		m = 1;
		if (scanf("%d %d %d", &a[0], &a[1], &a[2]) != 3) m = 0;
		n = yearCheck(a[0]);
		if (a[0] < 1900 || a[1] < 1 || a[2] < 1 || a[1] > 12) m = 0; //  음수값 거르기
		switch (a[1]) { // 월별 초과일수 거르기, 윤년시 2월 29일 거르기
		case 1: if (a[2] > 31)m = 0; break;
		case 2:if (n == 1) {
			if (a[2] > 29) m = 0; break;
		}
			  else
			if (a[2] > 28)m = 0; break;
		case 3:if (a[2] > 31)m = 0; break;
		case 4:if (a[2] > 30)m = 0; break;
		case 5:if (a[2] > 31)m = 0; break;
		case 6:if (a[2] > 30)m = 0; break;
		case 7:if (a[2] > 31)m = 0; break;
		case 8:if (a[2] > 31)m = 0; break;
		case 9:if (a[2] > 30)m = 0; break;
		case 10:if (a[2] > 31)m = 0; break;
		case 11:if (a[2] > 30)m = 0; break;
		case 12:if (a[2] > 31)m = 0; break;
		default: m = 0;
		}
		while (getchar() != '\n');
		if (m == 0) printf("다시 입력하세요 : ");
	}
}

int yearCheck(int year)
{
	int n;
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

int cal_days(int y, int m, int d)
{
	int n;
	int day = 0;
	int _2d;
	for (int i = 1900; i < y; i++){
		n = yearCheck(i);
		if (n == 0)
			day += 365;
		else
			day += 366;
	}
	n = yearCheck(y);
	if (n == 0) _2d = 28;
	else _2d = 29;
	switch (m) {
	case 1:day += d; break;
	case 2:day += (31 + d); break;
	case 3:day += (31 + _2d + d); break;
	case 4:day += (31 + _2d + 31 + d); break;
	case 5:day += (31 + _2d + 31 + 30 + d); break;
	case 6:day += (31 + _2d + 31 + 30 + 31 + d); break;
	case 7:day += (31 + _2d + 31 + 30 + 31 + 30 + d); break;
	case 8:day += (31 + _2d + 31 + 30 + 31 + 30 + 31 + d); break;
	case 9:day += (31 + _2d + 31 + 30 + 31 + 30 + 31 + 31 + d); break;
	case 10:day += (31 + _2d + 31 + 30 + 31 + 30 + 31 + 31 + 30 + d); break;
	case 11:day += (31 + _2d + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + d); break;
	case 12:day += (31 + _2d + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + d); break;
	}
	return day % 7;
}

void print(int y, int m, int d, int a)
{
	char b[7][3] = { "일", "월", "화", "수", "목", "금", "토" };
	printf("\n%d년 %d월 %d일은 %s요일 입니다.\n", y, m ,d, b[a]);
}