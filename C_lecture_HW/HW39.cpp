#pragma warning (disable : 4996)
#include <stdio.h>

int main()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			printf("%4d", i + j * 10);
		printf("\n");
	}
}