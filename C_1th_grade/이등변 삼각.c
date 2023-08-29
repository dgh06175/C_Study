#include <stdio.h>
int main(int x) {
	printf("이등변 삼각형을 출력 합니다.\n밑변의 길이를 결정할 양의 홀수를 입력해주세요 : ");
RESTART:
	scanf_s("%d", &x);		// x는 밑변의 길이이고, 높이는 (x+1)/2 이다                      
	int a, b, c;
	if (x % 2 == 0 || x <= 0)
	{
		printf("홀수를 입력해 주세요 : ");
		goto RESTART;
	}
	else
	{
		for (c = 1; c <= (x + 1) / 2; c++) //c는 현재 줄 이고, 각 줄의 가로의 길이는 c*2-1이다.
		{
			for (a = 1; a <= (x-(c*2-1))/2; a++) // 공백을 (x-c)-(x+1)/2 만큼 출력해야 한다.
			{
				printf(" ");
			}
			for (b = 0; b < c * 2 - 1; b++) // *을 c*2-1만큼 출력해야 한다.
			{
				printf("*");
			}
			printf("\n");
		}
	}
}