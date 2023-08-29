#pragma warning(disable : 4996)
#include <stdio.h>

int main()
{
	int n, a = 0;
	for (int count = 0; count < 5;) {
		printf("0보다 큰수를 입력하시오(%d 번째) : ", count + 1);
		scanf("%d", &n);
		if (n > 0) {
			a  = a + n;
			count++;
		}
	}
	printf("입력된 값의 총 합 : %d\n", a);
	return 0;
}