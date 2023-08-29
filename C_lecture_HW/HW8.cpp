#pragma warning(disable : 4996)
#include <stdio.h>

int main()
{
	int his, cul, art;
	printf("역사, 문학, 예능 점수를 입력하세요 : ");
	scanf("%d %d %d", &his, &cul, &art);
	printf("총점은 %d 이고 평균은 %.2lf 입니다.\n", his + cul + art, ((double)his + cul + art) / 3);
	return 0;
}