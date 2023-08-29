#pragma warning (disable : 4996)
#include <stdio.h>

int main()
{
	int ary[] = { 1, 2, 3, 4, 5 };
	int len = sizeof(ary)/sizeof(int);
	printf("처음 배열에 저장된 값 : ");
	for(int i = 0; i < len; i++)
	printf(" %d ", ary[i]);
	if (len % 2 == 1) //홀수
	{
		for(int i = 0; i < (len - 1) / 2; i++)
		{
			int temp;
			temp = ary[i];
			ary[i] = ary[len - i - 1];
			ary[len - i - 1] = temp;
		}
	}
	else //짝수
	{
		for(int i = 0; i < len / 2; i++)
		{
			int temp;
			temp = ary[i];
			ary[i] = ary[len - i - 1];
			ary[len - i - 1] = temp;
		}
	}
	printf("\n나중 배열에 저장된 값 : ");
	for(int i = 0; i < len; i++)
	printf(" %d ", ary[i]);
	return 0;
}