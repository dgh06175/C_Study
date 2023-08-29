#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
int input(char *, char *);
int strcheck(char *, char);

int main()
{
	int n;
	char str[99], chr;
	if(input(str, &chr)==0);
	else {
		n = strcheck(str, chr);
		if (n == -1)
			printf("\"%s\"문자열 안에 '%c'문자는 존재하지 않습니다.\n", str, chr);
		else
			printf("\"%s\"문자열 안에 '%c'문자는 %d번 위치에 존재합니다.\n", str, chr, n);
	}
}

int input(char *str, char *chr)
{
	printf("# 문자열을 입력하시오 : ");
	scanf("%s", str);
	if (strcmp(str, "end") == 0)return 0;
	while (getchar() != '\n');
	printf("# 문자를 입력하시오 : ");
	scanf(" %c", chr);
	while (getchar() != '\n');
}

int strcheck(char *str, char chr)
{
	int n = -1;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == chr)
			n = i;
	}
	return n;
}