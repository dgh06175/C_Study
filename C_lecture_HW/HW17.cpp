#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>

int main()
{
	char name[20];
	double height;
	char sex;
	printf("#성명 입력 : ");
	fgets(name, strlen(name), stdin);
	int len = strlen(name);
	name[len - 1] = '\0';
	printf("#키 입력(cm단위) : ");
	scanf("%lf", &height);
	printf("#성별입력(M/F) : ");
	scanf(" %c", &sex);
	if (sex == 'M')
		printf("%s씨의 키는 %.2lf이고 남성입니다", name, height);
	else
		printf("%s씨의 키는 %.2lf이고 여성입니다", name, height);
	return 0;
}