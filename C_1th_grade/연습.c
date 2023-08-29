#include <stdio.h>
int main()
{
	double 가로,세로,넓이;
	printf("가로와 세로를 입력하세요.\n");
	scanf_s("%lf%lf", &가로,&세로);
	넓이 = 가로*세로;
	printf("넓이는 %7.0lf 입니다.", 넓이);
	return 0;
}