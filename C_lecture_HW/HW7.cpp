#pragma warning(disable : 4996)
#define HOUR_SEC 3600.0
#include <stdio.h>

int main()
{
	double km, km_h, total_hour, sec;
	int hour, min;
	printf("* 거리를 입력하시오(km단위) : ");
	scanf("%lf", &km);
	printf("* 시속을 입력하시오(km/h단위) : ");
	scanf("%lf", &km_h);
	total_hour = km / km_h;
	hour = (int)total_hour;
	min = (int)((total_hour - (double)hour) * 60.0);
	sec = ((total_hour - (double)hour) * 60 - min) * 60;
	printf("%.2lf km = >%d시간 %d분 %.3lf초 소요됨\n", km, hour, min, sec);
	return 0;
}