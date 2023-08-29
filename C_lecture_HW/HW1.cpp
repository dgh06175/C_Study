#include <stdio.h>
void printAge(int age);
void printHeight(double height);

int main()
{
	char name[20] = "이상현";
	int age = 500;
	double height = 170.8;

	printf("성명 : %s\n", name);
	printAge(age);
	printHeight(height);

	return 0;
}

void printAge(int age)
{
	printf("나이 : %d\n", age);
	return;
}

void printHeight(double height)
{
	printf("키 : %.1lf\n", height);
	return;
}
