#include <stdio.h>
#include <math.h>
int main()
{
	int a, b, c;
	int n;
	printf("피타고라스의 수를 찾습니다. 가장 긴 변의 길이가 몇일떄 까지 구할까요? : ");
	scanf_s("%d", &n);
	for (a = 1; a <= n; a++)
	{
		for (b = 1; b < a; b++)
		{
			for (c = 1; c < a; c++)
			{
				if (a*a == b*b + c*c)
				{
					printf("%d %d %d\n",b,c,a);
				}
				else {}
			}
		}
	}
}