#include <stdio.h>
int max(x, y)
{
	if (x > y)
		return x;
	else if (x < y)
		return y;
	else
		return 0;
}

int main()
{
	int a, b;
	scanf_s("%d %d", &a, &b);
	printf("%d�� Ů�������������ϴ�", max(a, b));
}������������