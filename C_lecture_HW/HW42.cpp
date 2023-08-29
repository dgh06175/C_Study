#pragma warning (disable : 4996)
#include <stdio.h>

int main()
{
	for (int i = 1; i <= 9; i++){
		for (int j = 2; j <= 5; j++){
			printf("%d*%d= %d", j, i, i * j);
			printf("\t\t");
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 1; i <= 9; i++) {
		for (int j = 6; j <= 9; j++) {
			printf("%d*%d= %d", j, i, i * j);
			printf("\t\t");
		}
		printf("\n");
	}
	printf("---------------------------------------------------------------\n\n");
	printf("<3중 for문을 이용한 출력>\n");
	for (int i = 2; i <= 9; i += 4){
		for (int j = 1; j <= 9; j++) {
			for (int k = i; k <= i+3; k++) {
				printf("%d*%d= %d", k, j, j * k);
				printf("\t\t");
			}
			printf("\n");
		}
		printf("\n");
	}
}