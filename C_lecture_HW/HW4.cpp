#pragma warning(disable : 4996)
#include <stdio.h>

int main(void)
{
	double iday = 365.2422;
	int day, hour, min;
	double sec;
	day = (int)iday;
	hour = (int)((iday - day) * 24);
	min = (int)((iday - (double)day) * 1440 - (double)hour * 60);
	sec = ((iday - day) * 86400 - (double)hour * 3600 - (double)min * 60);
	printf("%.4lf일은 %d일 %d시간 %d분 %.2lf초 입니다.\n", iday, day, hour, min, sec);
	return 0;
}