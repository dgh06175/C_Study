#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int input(char*);
int level_check(char*);
void print(char*, int);

int main()
{
	char str[100] = { 0, };
	while (strcmp(str, "end") != 0)
	{
		if (input(str) == 1)break;
		print(str, level_check(str));
	}
}

int input(char* str)
{
	printf("# 단어 입력 : ");
	scanf("%s", str);
	if (strcmp(str, "end") == 0) return 1;
	else return 0;
}

int level_check(char* str1)
{
	int len = strlen(str1);
	char str[100];
	strcpy(str, str1);
	for (int i = 0; i < len; i++)
		str[i] = tolower(str[i]);
	int count = 0;;;;;;;;;;;;
	if (len % 2 == 1) { //홀수길이
		for (int i = 0; i < (len - 1) / 2; i++){
			if (str[i] != str[len -1 - i])
				count++;
		}
	}
	else{
		for (int i = 0; i < len / 2; i++) {
			if (str[i] != str[len -1 - i])
				count++;
		}
	}
	if (count == 0)
		return 1;
	else
		return 0;
}

void print(char* str, int check)
{
	char a[2][20] = { "이 아닙", "입" };
	printf("\"%s\" : 회문%s니다!\n\n", str, a[check]);
}