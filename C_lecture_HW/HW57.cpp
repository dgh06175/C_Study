#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
void input(char(*)[20]);
void sort(char(*)[20]);
void print(char(*)[20]);

int main()
{
	char str[5][20];
	input(str);
	sort(str);
	print(str);
}

void input(char(*str)[20])
{
	for (int i = 0; i < 5; i++) {
		printf("# %d번 문자열을 입력하시오 : ", i + 1);
		scanf("%s", str[i]);
	}
}

void sort(char(*str)[20])
{
	char temp[20];
	int n = -1;
	for (int i = 0; i < 5; i++) {
		for (int j = i; j < 5; j++) {
			if (strcmp(str[i], str[j]) > 0) {
				strcpy(temp, str[j]);
				strcpy(str[j], str[i]);
				strcpy(str[i], temp);
			}
		}
	}
}

void print(char(*str)[20])
{
	for (int i = 0; i < 5; i++){
		printf("str[%d] = %s   %c  %c\n", i, str[i], str[i][0], str[i][strlen(str[i]) - 1]);
	}
}