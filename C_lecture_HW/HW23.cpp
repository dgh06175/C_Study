#pragma warning(disable : 4996)
#include <stdio.h>

int main()
{
	int a, b, tmp;
	while (1) {
		printf("# 두개의 정수를 입력하세요 : ");
		if (scanf("%d %d", &a, &b) != 2)
			break;
		
		if (a < b) {
			tmp = a;
			a = b;
			b = tmp;
		}
		printf("%d - %d = %d\n", a, b, a - b);
	}
	return 0;
}