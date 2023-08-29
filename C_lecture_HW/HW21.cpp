#pragma warning(disable : 4996)
#include <stdio.h>

int main()
{
	double height, add = 0.0;
	for (int i = 0; i < 5; i++) {
		printf("- %d 번 학생의 키는? ", i + 1);
		scanf("%lf", &height);
		add += height;
	}
	printf("다섯 명의 평균 키는 %.1lf cm 입니다.\n", add / 5);
	return 0;
}