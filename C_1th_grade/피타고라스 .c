#include <stdio.h>
#include <math.h>
int main()
{
	int a, b, c;
	int n;
	printf("��Ÿ����� ���� ã���ϴ�. ���� �� ���� ���̰� ���ϋ� ���� ���ұ��? : ");
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