#pragma warning(disable : 4996)
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int input(int);
void output(int, int);

int main()
{
	int com, result, win = 0, draw = 0;
	srand((unsigned int)time(NULL));
	while (1)
	{
		com = rand() % 3 + 1;
		result = input(com);
		if (result == 1)
			win++;
		else if (result == 2)
			draw++;
		else if (result == 4) {
			printf("오류입니다.\n");
			break;
		}
		else
			break;
	}
	printf("\n게임결과 : %d승 %d무\n", win, draw);
	return 0;
}

int input(int com)
{
	int user;
	printf("# 바위는 1, 가위는 2, 보는 3 중에서 선택하세요 : ");
	scanf("%d", &user);
	while (getchar() != '\n');
	if (user == 1) {
		if (com == 1) {
			output(user, com);
			return 2;
		}
		if (com == 2) {
			output(user, com);
			return 1;
		}
		if (com == 3) {
			output(user, com);
			return 3;
		}
	}
	else if (user == 2) {
		if (com == 1) {
			output(user, com);
			return 3;
		}
		if (com == 2) {
			output(user, com);
			return 2;
		}
		if (com == 3) {
			output(user, com);
			return 1;
		}
	}
	else if (user == 3) {
		if (com == 1) {
			output(user, com);
			return 1;
		}
		if (com == 2) {
			output(user, com);
			return 3;
		}
		if (com == 3) {
			output(user, com);
			return 2;
		};
	}
	else {
		printf("다시 입력해주세요.\n");
		return input(com);
	}
	return 4;
}

void output(int user, int com)
{
	if (user == 1) {
		if (com == 1) {
			printf("당신은 바위, 컴퓨터는 바위 선택 : 비겼습니다.\n");
		}
		if (com == 2) {
			printf("당신은 바위, 컴퓨터는 가위 선택 : 이겼습니다.\n");
		}
		if (com == 3) {
			printf("당신은 바위, 컴퓨터는 보 선택 : 졌습니다.\n");
		}
	}
	else if (user == 2) {
		if (com == 1) {
			printf("당신은 가위, 컴퓨터는 바위 선택 : 졌습니다.\n");
		}
		if (com == 2) {
			printf("당신은 가위, 컴퓨터는 가위 선택 : 비겼습니다.\n");
		}
		if (com == 3) {
			printf("당신은 가위, 컴퓨터는 보 선택 : 이겼습니다.\n");
		};
	}
	else if (user == 3) {
		if (com == 1) {
			printf("당신은 보, 컴퓨터는 바위 선택 : 이겼습니다.\n");
		}
		if (com == 2) {
			printf("당신은 보, 컴퓨터는 가위 선택 : 졌습니다.\n");
		}
		if (com == 3) {
			printf("당신은 보, 컴퓨터는 보 선택 : 비겼습니다.\n");
		};
	}
}
