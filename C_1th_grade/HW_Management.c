#pragma warning(disable : 4996) // scanf_s, localtime_s, fopen_s�� ������� ���� �� �̹Ƿ� ��� ����
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

// �Լ��ȿ��� ���Ǵ� �Լ��� �����Ƿ� �̸� �������� 

/* ����ü �迭, ���Ǹ� �迭 ����� (�Լ������� ���ǹǷ� ���������� ����) */
struct Homework // �� �������� ��¥, ���µ� �������� �� ����ü ����, 8���� ����� 100������ ���� �迭 ����, �� ������ �⺻�� = 0
{
	int month;
	int day;
	int status; // ������ �������� 2(ȸ��)�����̸� 1(������) �ƴϸ� 0(���)
}task[8][100];

char subjects[9][20] = { // ����� �̸� ����,���Ǻ�. �����ϴ� ������ �ٸ� ��� �� �κи� �������ָ� ��
	"���̽�",
	"���ڱ���",
	"���¼ҽ�",
	"�̷����豸��",
	"������Ű���",
	"���м���",
	"ȸ�ν���",
	"ȸ���̷�",
	""
};

/* �޴�ȭ���� ����ϰ� �Է¹��� ���� ��ȯ�ϴ� �Լ� */
int print_menu(void)
{
	int n;
	printf("==========================\n");
	printf("��  1.���� ��� ����    ��\n��  2.���ο� ���� �Է�  ��\n��  3.�Ϸ��� ���� ����  ��\n��  4.���� �� ����      ��\n");
	printf("==========================\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // �Է��� �䱸�Ҷ� ��µǴ� �������� ��� �ʷϻ����� ��µǵ��� ��
	printf("������ �޴��� ��ȣ�� �Է��ϼ���: ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	while (scanf("%d", &n) != 1 || n < 1 || n > 4) { // �޴��� 1������ 4������ �����Ƿ� �� ���� ���̳� ������ �ƴ� ���� �Է��� ��� ���Է� �䱸
		while (getchar() != '\n');
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		printf("�ٽ� �Է��ϼ��� : ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	while (getchar() != '\n'); // ������ �߻����� �ʵ��� buffer�� �����
	return n;
}

/* �迭�� ������������ �����ϴ� �Լ�(�������� �˰����� ���¼ҽ��� ������) */
void sort_array(void)
{
	int k, i, j, n, min_month, min_day, index, tmp1, tmp2, tmp3;
	for (k = 0; k < 8; k++) {
		for (n = 0; task[k][n].month != 0 && task[k][n].day != 0; n++); // n�� k��° ������ ������ �� ������ �־���
		for (i = 0; i < n; i++)
		{
			min_month = 100;
			min_day = 100;
			index = i;
			for (j = i; j < n; j++)
			{
				if (min_month > task[k][j].month) { // �迭�� �ּҰ� ã��
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

/* �������� �����Ǿ��ִ� ȭ���� ����ϴ� �Լ� */
void option1(void)
{
	print_situation("���� ����� ����մϴ�.");
	sort_array();
	for (int i = 0; i < 8; i++) //�ʱ�ȭ�鿡 ������ �������� ���
	{							//i = �����ȣ - 1, j = ������ȣ(�ִ� = �� ����)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // �ణ �帰 ��� (cmd�� �⺻ ��)
		printf("%s(%d)", subjects[i], i + 1); // ������ ���� ��ȣ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		for (int j = 0; task[i][j].month > 0 && task[i][j].day > 0; j++) // ��ȿ�� ���� ���ִ� �迭�� ����ϱ� ���� task.month�Ǵ� day�� 0���� ���� ������ �ݺ�����
		{
			if (task[i][j].status == 2) { // ���� ���� -> ȸ��
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
				printf("\t%d/%d", task[i][j].month, task[i][j].day);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else if (task[i][j].status == 1) { // ���� ���� -> ������
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("\t%d/%d", task[i][j].month, task[i][j].day);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else // ������ -> ���
				printf("\t%d/%d", task[i][j].month, task[i][j].day);
		}
		printf("\n");
	}
}

/* �迭�� ���ο� ������ �Է��ϴ� �Լ� */
void option2(void)
{
	int n, m, d;
	char* msg = "\n\n������ ���� ��ȣ�� ���� ������ �Է��Ͻÿ� (�� �� ��)(-1 �Է½� ����) : ";
	if (input(&n, &m, &d, msg) != -1) { // input() �Լ��� n(�����ȣ), m(��), n(��) ������ �Է� ����. -1 �Է½� input() �Լ��� -1�� ��ȯ�ϰ� �޴� ȭ������ ���ư�{
		int k = 0;
		for (k = 0; task[n - 1][k].month > 0 && task[n - 1][k].day > 0; k++); // k = �ش� ���� ������ �� ����
		task[n - 1][k].month = m;
		task[n - 1][k].day = d;
		print_situation("������ �ԷµǾ����ϴ�.");
		return;
	}
	print_situation("���� �Է��� ����߽��ϴ�. �޴� ȭ������ ���ư��ϴ�.");
}

/* ������ �����ϴ� �Լ� */
void option3(void)
{
	int n, m, d;
	int check = -1;
	char* msg = "\n\n������ ������ ���� ��ȣ�� ���� ������ �Է��Ͻÿ� (�� �� ��)(-1 �Է½� ����) : ";
	if (input(&n, &m, &d, msg) != -1) { // input() �Լ��� n(�����ȣ), m(��), n(��) ������ �Է� ����. -1 �Է½� input() �Լ��� -1�� ��ȯ�ϰ� �޴� ȭ������ ���ư�
		for (int i = 0; task[n - 1][i].month > 0 && task[n - 1][i].day > 0; i++) { // n�� ���񿡼� ��(i)��° ������ �Է��� ��¥�� ��ġ�ϴ��� �˻��ϱ� ���� ù��° �������� ������ �˻��Ѵ�
			if (task[n - 1][i].month == m && task[n - 1][i].day == d) { // i��° ������ �Է��� ��¥�� ��ġ�ϴٸ�
				check = 1; // ��ġ�ϴ� ������ ���� ��쿡�� check = 1 ����
				for (int j = i; task[n - 1][j].month > 0 && task[n - 1][j].day > 0; j++) { // �ش��° ������ ������° ������ ������ �۾��� i��°���� ������ �Ѵ�
					task[n - 1][j].month = task[n - 1][j + 1].month;
					task[n - 1][j].day = task[n - 1][j + 1].day; // status �׸��� main�Լ����� �޴��� �ҷ��ö� ������Ʈ �ǹǷ� �Ű��� �ʿ䰡 ����
				}
				break;
			}
		}
		if (check == -1) // ���� ���� ����(��ġ�ϴ� ���� X)
			print_situation("�ش� ��¥�� ������ �������� �ʽ��ϴ�.");
		else // ���� ���� ����
			print_situation("�ش� ������ �����Ǿ����ϴ�.");
		return;
	}
	print_situation("���� �Է��� ����߽��ϴ�. �޴� ȭ������ ���ư��ϴ�."); // -1 �Է� ��
}

/* ���ο� ���� �Է½� ��ȿ�� ���� ������ �ֵ��� ���ִ� �Լ� */
int input(int *num, int *month, int *day, char *str) // num = ������ ��ȣ, month = ������ �ּ�, day = �ϰ��� �ּ� �ް� ��ȿ�� ��¥�� �Է¹޴� �Լ�
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf(str);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	int m = 0; // �߸� �Է½� 0�� �Ǵ� ��, �ʱⰪ �ο�
	while (m == 0) {
		m = 1;
		if (scanf("%d", num) != 1) m = 0; // ���� �Ÿ���
		if (*num == -1) return -1; // -1 �Է½� ����
		if (scanf("%d %d", month, day) != 2) m = 0; // ���� �Ÿ���
		if (*month < 1 || *day < 1 || *month > 12 || *num < 1 || *num > 8) m = 0; // �߸��� num, month, 0���� day �Ÿ���
		switch (*month) { // ���� �ʰ��ϼ� �Ÿ���
		case 1:if (*day > 31)m = 0; break;
		case 2:if (*day > 29)m = 0; break; // 2020���� �����̹Ƿ� 2�� 29�ϱ��� �ִ� -> 2���� 30 �̻� �Է½� ����
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
		while (getchar() != '\n'); // ���� ����
		if (m == 0) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��ϼ��� : "); // ������ ���Է� �䱸
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
	}
	return 1;
}

/* �μ��� ���޹��� ���ڿ��� ����ϴ� �Լ� */
void print_situation(char* msg)
{
	int len = (int)strlen(msg) + 4;
	printf("\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); // �ȳ� ���ڿ��� ��������� ���
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

/* ���� ��¥�� ���� status �׸��� ������Ʈ�ϴ� �Լ� */
void update_status(int now_mon, int now_day)
{
	for (int i = 0; i < 8; i++){
		for (int j = 0; task[i][j].month > 0 && task[i][j].day > 0; j++){
			if (now_mon > task[i][j].month) // ������ �������� 2(ȸ��) �����̸� 1(������) �ƴϸ� 0(���)
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
	int option = 5; // ������ ����� ��ȿ�� �ʱⰪ �ο�
	int i = 0;
	int j = 0;
	char a, b;
	int count = 0; // �Ʒ��� while�� �ȿ��� �̹��� ���� ���� month���� day���� �����ϱ� ���� ����
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int now_mon = tm.tm_mon + 1; // ���� ��¥�� �ҷ����� ���� ����
	int now_day = tm.tm_mday;
	FILE* fp1 = fopen("homework.txt", "a"); // homework ������ �������� ���� ��� �ڵ����� �����ǰ� �ϱ� ���� a���� fopen�� fclose ����
	fclose(fp1);
	FILE* fp = fopen("homework.txt", "r+"); // �ؽ�Ʈ ������ �а� ���� �� �� �ؾ��ϹǷ� r+���� ������.
	if (fp == NULL) // ���� ���� ���н� ����
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // ���� �޼����� ���������� ���
		printf("File open error\n");
		fclose(fp);
		return 0;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // ���α׷��� �������� ���� �⺻ ���ڻ��� ���� �⺻ ���򺸴� �� ���� �Ͼ������ ��
	/* �ؽ�Ʈ ������ ����ü �迭�� �����ϴ� �κ� */
	while (a = fgetc(fp))
	{
		b = fgetc(fp);			 // �̹� ���� a�� �������� ������
		fseek(fp, -1, SEEK_CUR); // Ŀ���� �ٽ� ���ư�
		if (a == EOF || b == EOF) break; // ���Ͽ� ���� �ؽ�Ʈ�� ���� ��� break
		if (isdigit(a)) // a�� ����(��ȿ�� ��)�ϰ��
		{
			if (isdigit(b)) // a, b�� ��� �����ϰ�� (������ �ؽ�Ʈ�� ������ 2�ڸ����� ���)
			{
				if (count % 2 == 0) { // month�� ������ ���� ������ ���
					task[i][j].month = (a - '0') * 10 + b - '0'; // 12�� a=1, b=2�� �������� �� �̹Ƿ� 12�� ���� ��������
				}
				else {
					task[i][j].day = (a - '0') * 10 + b - '0';
					j++;
					count++;
				}
				fseek(fp, 1, SEEK_CUR); // b�� ��ȿ�� ���̿����Ƿ� Ŀ���� �ٽ� �̵�
			}
			else // b�� ��ȿ�� ���� �ƴϿ����Ƿ� (���ڸ��� ����) a ����
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
			if (a == '\n') // �� ������ ������ ��� �������̹Ƿ� i(�����ȣ)�� �ϳ� �÷��ְ�, j(������ȣ)�� count�� 0���� �ʱ�ȭ ����
			{
				i++;
				j = 0;
				count = 0;
			}
			else if (a == '/') // �� -> �� �� �Ѿ�� �κп� Ŀ���� �ִ°��̹Ƿ� day�� ���� ����ֱ� ���� count���� �ϳ� �÷���
				count++;
			else; // \t ��� �ʿ���� ���� �׳� Ŀ���� ����������
		}
	}

	/* �޴������ ����ϰ�, ������ �޴��� ��ȣ�� �ް� �����ϴ� �κ� */
	while (option != 4) // 4�Է½� �ݺ� ���� (����)
	{
		update_status(now_mon, now_day); // �ƹ� �޴��� ���� �Ҷ����� status�� ������Ʈ ����
		option = print_menu(); // 1. ���� ȭ�� ��� 2. ���ο� ���� �Է� 3. �Ϸ��� ���� ���� 4. ����
		if (option == 1) option1();
		else if (option == 2) option2();
		else if (option == 3) option3();
		else break;// �ݺ� ���� (����)
	}

	/* �����迭�� �ؽ�Ʈ ���Ͽ� �����ϰ� �����ϴ� �κ� */
	rewind(fp); // Ŀ���� �� ������ �Űܼ� ������ ó������ �ٽ� ���� ��
	for (int j = 0; j < 8; j++)
	{
		for (int k = 0; task[j][k].month > 0 && task[j][k].day > 0; k++)
		{
			fprintf(fp, "\t%d/%d", task[j][k].month, task[j][k].day);
		}
		if (j != 7) fputs("\n", fp);
	}
}