#include <stdio.h>
void main()
{
	int 변의길이, 둘레, 면적;
	printf("변의 길이를 입력하세요\n");
	scanf_s("%d", &변의길이);
	면적 = 변의길이*변의길이;
	둘레 = 변의길이 * 4;
	printf("면적은 %d 이고, 둘레는 %d 입니다.", 면적, 둘레);
}