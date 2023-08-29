#pragma warning(disable : 4996)
#include <stdio.h>

int main(void)
{
	int total_second, hour, minute, remain;
	printf("초를 입력하시오 : ");
	scanf("%d", &total_second);
	hour = total_second / 3600;
	remain = total_second - hour * 3600;
	minute = remain / 60;
	remain = remain - minute * 60;

	printf("%d초는 %d시간 %d분 %d초 입니다.\n", total_second, hour, minute, remain);

	return 0;
}