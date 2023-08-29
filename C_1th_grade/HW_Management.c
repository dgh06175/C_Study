#pragma warning(disable : 4996) // scanf_s, localtime_s, fopen_s를 사용하지 않을 것 이므로 경고 무시
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

int print_menu(void);
void sort_array(void);
void option1(void);
void option2(void);
void option3(void);
int input(int*, int*, int*, char*);
void print_situation(char*);
void update_status(int, int);

// 함수안에서 사용되는 함수가 있으므로 미리 선언해줌 

/* 구조체 배열, 강의명 배열 선언부 (함수에서도 사용되므로 전역범위에 선언) */
struct Homework // 각 과제들의 날짜, 상태등 정보들이 들어갈 구조체 정의, 8과목에 과목당 100개까지 들어가는 배열 선언, 각 값들의 기본값 = 0
{
	int month;
	int day;
	int status; // 기한이 지났으면 2(회색)당일이면 1(빨간색) 아니면 0(흰색)
}task[8][100];

char subjects[9][20] = { // 과목들 이름 선언,정의부. 수강하는 과목이 다를 경우 이 부분만 수정해주면 됨
	"파이썬",
	"전자기학",
	"오픈소스",
	"미래설계구현",
	"정보통신개론",
	"공학수학",
	"회로실험",
	"회로이론",
	""
};

/* 메뉴화면을 출력하고 입력받은 값을 반환하는 함수 */
int print_menu(void)
{
	int n;
	printf("==========================\n");
	printf("§  1.과제 목록 보기    §\n§  2.새로운 과제 입력  §\n§  3.완료한 과제 삭제  §\n§  4.저장 및 종료      §\n");
	printf("==========================\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // 입력을 요구할때 출력되는 문구들은 모두 초록색으로 출력되도록 함
	printf("선택할 메뉴의 번호를 입력하세요: ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	while (scanf("%d", &n) != 1 || n < 1 || n > 4) { // 메뉴가 1번부터 4번까지 있으므로 그 외의 값이나 정수가 아닌 값을 입력할 경우 재입력 요구
		while (getchar() != '\n');
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		printf("다시 입력하세요 : ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	while (getchar() != '\n'); // 오류가 발생하지 않도록 buffer를 비워줌
	return n;
}

/* 배열을 오름차순으로 정렬하는 함수(선택정렬 알고리즘은 오픈소스를 참고함) */
void sort_array(void)
{
	int k, i, j, n, min_month, min_day, index, tmp1, tmp2, tmp3;
	for (k = 0; k < 8; k++) {
		for (n = 0; task[k][n].month != 0 && task[k][n].day != 0; n++); // n에 k번째 과목의 과제의 총 개수를 넣어줌
		for (i = 0; i < n; i++)
		{
			min_month = 100;
			min_day = 100;
			index = i;
			for (j = i; j < n; j++)
			{
				if (min_month > task[k][j].month) { // 배열중 최소값 찾기
					min_month = task[k][j].month;
					min_day = task[k][j].day;
					index = j;
				}
				else if (min_month == task[k][j].month && min_day > task[k][j].day) {
					min_month = task[k][j].month;
					min_day = task[k][j].day;
					index = j;
				}
			}
			tmp1 = task[k][i].month;
			tmp2 = task[k][i].day;
			tmp3 = task[k][i].status;
			task[k][i].month = task[k][index].month;
			task[k][i].day = task[k][index].day;
			task[k][i].status = task[k][index].status;
			task[k][index].month = tmp1;
			task[k][index].day = tmp2;
			task[k][index].status = tmp3;
		}
	}
}

/* 과제들이 나열되어있는 화면을 출력하는 함수 */
void option1(void)
{
	print_situation("과제 목록을 출력합니다.");
	sort_array();
	for (int i = 0; i < 8; i++) //초기화면에 과목명과 과제들을 출력
	{							//i = 과목번호 - 1, j = 과제번호(최대 = 총 개수)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 약간 흐린 흰색 (cmd의 기본 색)
		printf("%s(%d)", subjects[i], i + 1); // 과목명과 과제 번호
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		for (int j = 0; task[i][j].month > 0 && task[i][j].day > 0; j++) // 유효한 값이 들어가있는 배열만 출력하기 위해 task.month또는 day에 0이하 값이 나오면 반복중지
		{
			if (task[i][j].status == 2) { // 기한 지남 -> 회색
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
				printf("\t%d/%d", task[i][j].month, task[i][j].day);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else if (task[i][j].status == 1) { // 기한 당일 -> 빨간색
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("\t%d/%d", task[i][j].month, task[i][j].day);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else // 나머지 -> 흰색
				printf("\t%d/%d", task[i][j].month, task[i][j].day);
		}
		printf("\n");
	}
}

/* 배열에 새로운 과제를 입력하는 함수 */
void option2(void)
{
	int n, m, d;
	char* msg = "\n\n과제의 과목 번호와 제출 기한을 입력하시오 (번 월 일)(-1 입력시 종료) : ";
	if (input(&n, &m, &d, msg) != -1) { // input() 함수로 n(과목번호), m(월), n(일) 값들을 입력 받음. -1 입력시 input() 함수가 -1을 반환하고 메뉴 화면으로 돌아감{
		int k = 0;
		for (k = 0; task[n - 1][k].month > 0 && task[n - 1][k].day > 0; k++); // k = 해당 과목 과제의 총 개수
		task[n - 1][k].month = m;
		task[n - 1][k].day = d;
		print_situation("과제가 입력되었습니다.");
		return;
	}
	print_situation("과제 입력을 취소했습니다. 메뉴 화면으로 돌아갑니다.");
}

/* 과제를 삭제하는 함수 */
void option3(void)
{
	int n, m, d;
	int check = -1;
	char* msg = "\n\n삭제할 과제의 과목 번호와 제출 기한을 입력하시오 (번 월 일)(-1 입력시 종료) : ";
	if (input(&n, &m, &d, msg) != -1) { // input() 함수로 n(과목번호), m(월), n(일) 값들을 입력 받음. -1 입력시 input() 함수가 -1을 반환하고 메뉴 화면으로 돌아감
		for (int i = 0; task[n - 1][i].month > 0 && task[n - 1][i].day > 0; i++) { // n번 과목에서 몇(i)번째 과제가 입력한 날짜와 일치하는지 검사하기 위해 첫번째 과제부터 끝까지 검사한다
			if (task[n - 1][i].month == m && task[n - 1][i].day == d) { // i번째 과제가 입력한 날짜와 일치하다면
				check = 1; // 일치하는 과제가 있을 경우에만 check = 1 대입
				for (int j = i; task[n - 1][j].month > 0 && task[n - 1][j].day > 0; j++) { // 해당번째 과제를 다음번째 과제로 덮어씌우는 작업을 i번째부터 끝까지 한다
					task[n - 1][j].month = task[n - 1][j + 1].month;
					task[n - 1][j].day = task[n - 1][j + 1].day; // status 항목은 main함수에서 메뉴를 불러올때 업데이트 되므로 옮겨줄 필요가 없음
				}
				break;
			}
		}
		if (check == -1) // 과제 삭제 실패(일치하는 과제 X)
			print_situation("해당 날짜의 과제가 존재하지 않습니다.");
		else // 과제 삭제 성공
			print_situation("해당 과제가 삭제되었습니다.");
		return;
	}
	print_situation("과제 입력을 취소했습니다. 메뉴 화면으로 돌아갑니다."); // -1 입력 시
}

/* 새로운 과제 입력시 유효한 값만 받을수 있도록 해주는 함수 */
int input(int *num, int *month, int *day, char *str) // num = 과목의 번호, month = 월값의 주소, day = 일값의 주소 받고 유효한 날짜만 입력받는 함수
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf(str);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	int m = 0; // 잘못 입력시 0이 되는 값, 초기값 부여
	while (m == 0) {
		m = 1;
		if (scanf("%d", num) != 1) m = 0; // 문자 거르기
		if (*num == -1) return -1; // -1 입력시 종료
		if (scanf("%d %d", month, day) != 2) m = 0; // 문자 거르기
		if (*month < 1 || *day < 1 || *month > 12 || *num < 1 || *num > 8) m = 0; // 잘못된 num, month, 0이하 day 거르기
		switch (*month) { // 월별 초과일수 거르기
		case 1:if (*day > 31)m = 0; break;
		case 2:if (*day > 29)m = 0; break; // 2020년은 윤년이므로 2월 29일까지 있다 -> 2월에 30 이상 입력시 오류
		case 3:if (*day > 31)m = 0; break;
		case 4:if (*day > 30)m = 0; break;
		case 5:if (*day > 31)m = 0; break;
		case 6:if (*day > 30)m = 0; break;
		case 7:if (*day > 31)m = 0; break;
		case 8:if (*day > 31)m = 0; break;
		case 9:if (*day > 30)m = 0; break;
		case 10:if (*day > 31)m = 0; break;
		case 11:if (*day > 30)m = 0; break;
		case 12:if (*day > 31)m = 0; break;
		default: m = 0;
		}
		while (getchar() != '\n'); // 버퍼 비우기
		if (m == 0) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			printf("잘못 입력하셨습니다. 다시 입력하세요 : "); // 오류시 재입력 요구
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
	}
	return 1;
}

/* 인수로 전달받은 문자열을 출력하는 함수 */
void print_situation(char* msg)
{
	int len = (int)strlen(msg) + 4;
	printf("\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // 안내 문자열은 노란색으로 출력
	for (int i = 0; i < len; i++)
		printf("=");
	if (len % 2 == 0)
		printf("\n   %s   \n", msg);
	else
		printf("\n  %s   \n", msg);
	for (int i = 0; i < len; i++)
		printf("=");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("\n");
}

/* 현재 날짜에 따라 status 항목을 업데이트하는 함수 */
void update_status(int now_mon, int now_day)
{
	for (int i = 0; i < 8; i++){
		for (int j = 0; task[i][j].month > 0 && task[i][j].day > 0; j++){
			if (now_mon > task[i][j].month) // 기한이 지났으면 2(회색) 당일이면 1(빨간색) 아니면 0(흰색)
				task[i][j].status = 2;
			else if (now_mon == task[i][j].month){
				if (now_day > task[i][j].day)
					task[i][j].status = 2;
				else if (now_day == task[i][j].day)
					task[i][j].status = 1;
				else
					task[i][j].status = 0;
			}
			else
				task[i][j].status = 0;
		}
	}
}



int main()
{
	int option = 5; // 오류를 대비해 무효한 초기값 부여
	int i = 0;
	int j = 0;
	char a, b;
	int count = 0; // 아래의 while문 안에서 이번에 받은 값이 month인지 day인지 구분하기 위한 변수
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int now_mon = tm.tm_mon + 1; // 현재 날짜를 불러오기 위한 변수
	int now_day = tm.tm_mday;
	FILE* fp1 = fopen("homework.txt", "a"); // homework 파일이 존재하지 않을 경우 자동으로 생성되게 하기 위해 a모드로 fopen후 fclose 해줌
	fclose(fp1);
	FILE* fp = fopen("homework.txt", "r+"); // 텍스트 파일을 읽고 쓰기 둘 다 해야하므로 r+모드로 열어줌.
	if (fp == NULL) // 파일 열기 실패시 종료
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // 에러 메세지는 빨간색으로 출력
		printf("File open error\n");
		fclose(fp);
		return 0;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 프로그램의 가독성을 위해 기본 글자색을 원래 기본 색깔보다 더 밝은 하얀색으로 함
	/* 텍스트 파일을 구조체 배열에 저장하는 부분 */
	while (a = fgetc(fp))
	{
		b = fgetc(fp);			 // 이미 뽑은 a의 다음문자 가져옴
		fseek(fp, -1, SEEK_CUR); // 커서는 다시 돌아감
		if (a == EOF || b == EOF) break; // 파일에 남은 텍스트가 없을 경우 break
		if (isdigit(a)) // a가 정수(유효한 값)일경우
		{
			if (isdigit(b)) // a, b가 모두 정수일경우 (가져온 텍스트의 정수가 2자리수인 경우)
			{
				if (count % 2 == 0) { // month에 들어가야할 값을 가져온 경우
					task[i][j].month = (a - '0') * 10 + b - '0'; // 12를 a=1, b=2로 가져왔을 것 이므로 12로 만들어서 저장해줌
				}
				else {
					task[i][j].day = (a - '0') * 10 + b - '0';
					j++;
					count++;
				}
				fseek(fp, 1, SEEK_CUR); // b가 유효한 값이였으므로 커서를 다시 이동
			}
			else // b가 유효한 값이 아니였으므로 (한자리수 받음) a 대입
			{
				if (count % 2 == 0)
					task[i][j].month = a - '0';
				else {
					task[i][j].day = a - '0';
					j++;
					count++;
				}
			}
		}
		else
		{
			if (a == '\n') // 한 과목의 과제를 모두 받은것이므로 i(과목번호)를 하나 늘려주고, j(과제번호)과 count를 0으로 초기화 해줌
			{
				i++;
				j = 0;
				count = 0;
			}
			else if (a == '/') // 월 -> 일 로 넘어가는 부분에 커서가 있는것이므로 day에 값을 집어넣기 위해 count값을 하나 늘려줌
				count++;
			else; // \t 등등 필요없는 값은 그냥 커서가 지나가게함
		}
	}

	/* 메뉴목록을 출력하고, 선택한 메뉴의 번호를 받고 실행하는 부분 */
	while (option != 4) // 4입력시 반복 중지 (종료)
	{
		update_status(now_mon, now_day); // 아무 메뉴나 실행 할때마다 status를 업데이트 해줌
		option = print_menu(); // 1. 과제 화면 출력 2. 새로운 과제 입력 3. 완료한 과제 삭제 4. 종료
		if (option == 1) option1();
		else if (option == 2) option2();
		else if (option == 3) option3();
		else break;// 반복 중지 (종료)
	}

	/* 과제배열을 텍스트 파일에 저장하고 종료하는 부분 */
	rewind(fp); // 커서를 맨 앞으로 옮겨서 파일을 처음부터 다시 쓰게 함
	for (int j = 0; j < 8; j++)
	{
		for (int k = 0; task[j][k].month > 0 && task[j][k].day > 0; k++)
		{
			fprintf(fp, "\t%d/%d", task[j][k].month, task[j][k].day);
		}
		if (j != 7) fputs("\n", fp);
	}
}