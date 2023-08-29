#pragma warning (disable : 4996)
#include <stdio.h>
void input(int*, int*);
int e_or_o(int, int);
void print(int, int, int);

int main()
{
	int start, end;
	input(&start, &end);
	print(start, end, e_or_o(start, end));
}

void input(int* start, int* end)
{
	while (1) {
		printf("# 시작 값을 입력하시오 : ");
		while (scanf("%d", start) != 1) {
			while (getchar() != '\n');
			printf("# 시작 값을 입력하시오 : ");
		}
		if (*start > 0) break;
	}
	while (1) {
		printf("# 끝 값을 입력하시오 : ");
		while (scanf("%d", end) != 1) {
			while (getchar() != '\n');
			printf("# 끝 값을 입력하시오 : ");
		}
		if (*end > * start) break;
	}
}

int e_or_o(int start, int end)
{
	char e_o;
	while (1){
		printf("* %d~%d 까지의 짝수의 합을 구할까요? 홀수의 합을 구할까요?(짝수:e/홀수:o) : ", start, end);
		scanf(" %c", &e_o);
		if (e_o == 'e') return 0;
		if (e_o == 'o') return 1;
	}
}

void print(int start, int end, int e_o)
{
	int sum = 0;
	printf("  %d~%d 까지의 짝수(", start, end);
	if (e_o == 0){
		for (int i = start; i <= end; i++){
			if (i % 2 == 0) {
				printf("%d ", i);
				sum += i;
			}
		}
	}
	else {
		for (int i = start; i <= end; i++) {
			if (i % 2 == 1) {
				printf("%d ", i);
				sum += i;
			}
		}
	}
	printf("\b)의 합은 %d 입니다.\n", sum);

}