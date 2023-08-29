#pragma warning(disable : 4996)
#include <stdio.h>
int input(const char *);
int cal(int);
void print(int, int);

int main()
{
	int depth, day;
	depth = input("우물의 깊이를 입력하시오(cm단위) : ");
	day = cal(depth);
	print(depth, day);
	return 0;
}

int input(const char* msg)
{
	int depth;
	printf(msg);
	scanf("%d", &depth);
	return depth;
}

int cal(int depth)
{
	int day = 0, up = 0;
	while (up < depth)
	{
		day++;
		up += 50;
		if (up >= depth) break;
		up -=20;
	}
	return day;
}

void print(int depth, int day)
{
	printf("%d 미터 깊이의 우물을 탈출하기 위해서는 %d일이 걸립니다.\n", depth, day);
}