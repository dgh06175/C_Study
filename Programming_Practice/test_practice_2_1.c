#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

//조건문!
//{
//	int n,m;
//	scanf_s("%d", &n);
//
//
//	m = (n > 0) ? 1 : 0; //조건 연산자
//
//
//	if (n > 0)	//if문
//		m = 1;
//	else
//		m = 0;
//
//
//	switch (n>0) //switch문
//	{
//	case 1:
//		m = 1;
//		break;
//	case 0:
//		m = 0;
//		break;
//	} //switch(이안에 조건식 넣을수 있음. 참은1 거짓은 0)
//	printf("%d", m);
//}
//
//반복문!
//{
//	int i = 0;
//	while (i < 5)
//	{
//	printf("hello\n");
//	i++;
//}


//do
//{
//	printf("hello\n");
//	i++;
//}
//while (i < 5);

//for (;;)
//{
//	printf("hello\n");
//	i++;
//	if (i == 5)
//		break;
//}
//}


//{
//	int n;
//	scanf_s("%d", &n);
//	switch (n)
//	{
//	case 1:
//		printf("case 1 실행\n");
//	case 2:
//		printf("case 2 실행\n");
//	case 3:
//		printf("case 3 실행\n");
//	case 4:
//		printf("case 4 실행\n");
//	}								//break; 없으면 다음에있는 case들이 맞든 틀리든 끝까지 실행함
//}
//
//{
//RE:
//	printf("hello\n");
//	goto RE;
//}


//{
//	for (int x = 10; x > 0; x--)
//	{
//		for (int y = 10; y > x; y--)
//		{
//			printf(" ");
//		}
//		for (int y = 0; y < x; y++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//}

//{
//	char LET;
//	printf("소문자를 입력하세요 : ");
//	scanf_s("%c", &LET,sizeof(LET));
//	LET -= 32;
//	printf("대문자는 %c 입니다.\n",LET);
//}

//{
//char UNI_NAME[100], NAME[100];
//int STD_NO;
//printf("학교명을 입력하세요 : ");
//scanf_s("%s", &UNI_NAME, sizeof(UNI_NAME));
//printf("성함을 입력하세요 : ");
//scanf_s("%s", &NAME, sizeof(NAME));
//printf("학번을 입력하세요 : ");
//scanf_s(" %d", &STD_NO);
//printf("\n학교명 : %s\n성함 : %s\n학번 : %d\n", UNI_NAME, NAME, STD_NO);
//}
//{
//	int n;
//	srand((unsigned)time(NULL)); //rand()(시드)값을 랜덤으로 바꿔줌
//	n = rand()%101; //n이 1~100사이의 수가됨
//	printf("난수는 %d 입니다.", n);
//}


//#define SIZE 5
//{
//int score[SIZE];
//for (int i = 1; i <= SIZE; i++)
//{
//	printf("학생%d의 성적을 입력하시오 : ", i);
//	scanf_s("%d", &score[i - 1]);
//}
//for (int i = 1; i <= SIZE; i++)
//printf("학생%d의 성적은 %d 입니다.\n", i, score[i - 1]);
//}


//{
//	int s[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14 },a;
//	a = sizeof(s[0]);
//	printf("%d", a);
//
//}


//#define SIZE 6
//{
//	int f[SIZE] = { 0 };
//	for (int i = 0; i < 10000; i++)
//	{
//		++f[rand() % 6];
//	}
//	for (int i = 0; i < SIZE ; i++)
//	{
//		printf("%d면은 %d번 나왔습니다.\n",i+1,f[i]);
//	}
//}



//char answer;
//int answer2;
//int seat[10] = { 0,0,0,0,0,0,0,0,0,0 };
//while (1)
//{
//printf("좌석을 예약 하시겠습니까? (y or n) : ");
//scanf_s(" %c", &answer,4);
//
//if (answer == 'n')
//break;
//else
//{
//	printf("\n-----------------------------------\n");
//	printf("   1  2  3  4  5  6  7  8  9  10   \n ");
//	for (int i = 0; i < 10; i++)
//	{
//		printf("  %d", seat[i]);
//	}
//	printf("   \n-----------------------------------\n");
//
//	printf("몇번을 예약 하시겠습니까? : ");
//	scanf_s(" %d", &answer2);
//	seat[answer2 - 1] = 1;
//}
//}

//srand((unsigned)time(NULL));
//int price[10];
//int m;
//for (int i = 0; i < 10; i++)
//{
//	price[i] = 40+rand()%60;
//}
//printf("--------------------------------------\n");
//for (int i = 0; i < 10; i++)
//{
//	printf("%-4d", price[i]);
//}
//printf("\n--------------------------------------\n");
//m = price[0];
//for (int i = 0; i < 10; i++)
//{
//	if (price[i] < m)
//		m = price[i];
//}
//printf("최저가는 %d 입니다.\n", m);
//
//}

//{
//int a, b;
//scanf_s("%d %d", &a, &b);
//printf("합은 %d 입니다", add(a, b));
//}

//int add(int n,int m)
//{
//	return n + m;
//}

//{
//int score[5] = { 1,2,3,4,5 };
//int s = 5;
//int avg;
//avg = get_avg(score, s);
//printf("평균은 %d 입니다.\n", avg);
//return 0;
//}
//
//int get_avg(int score[], int s)
//{
//	int sum = 0;
//	for (int i = 0; i < 5; i++)
//	{
//		sum += score[i];
//	}
//	return sum/5;
//}

//{
//	int x = 10;
//	int y = 10;
//
//	printf("x = %d\n", x);
//	printf("++x의 값 = %d\n", ++x);
//	printf("x = %d\n\n", x);
//
//	printf("y = %d\n", y);
//	printf("y++의 값 = %d\n", y++);
//	printf("y = %d\n", y);
//} //x++과 ++x의 차이

//void main()
//{
//	int sort[10];
//	printf("정수를 10번 입력하시오.\n");
//	for (int i = 0; i < 10; i++)
//	{
//		printf("\n%d번째 정수 : ", i + 1);
//		scanf_s("%d", &sort[i]);
//	}
//	int min = sort[0];
//
//	for (int j = 0; j < 10; j++)
//	{
//		for (int i = j; i < 10; i++)
//		{
//			if (min > sort[i])
//			{
//				min = sort[i];
//			}
//		}
//		for (int i = j; i < 10; i++)
//		{
//			if (min == sort[i])
//			{
//				sort[i] = sort[j];
//				sort[j] = min;
//			}
//		}
//	}
//
//	printf("\n정리한 배열은 ");
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", sort[i]);
//	}
//	printf(" 입니다.");
//}

//void main()
//{
//char UNI_NAME[100], NAME[100];
//int STD_NO;
//printf("학교명을 입력하세요 : ");
//scanf_s("%s", &UNI_NAME, sizeof(UNI_NAME));
//printf("성함을 입력하세요 : ");
//scanf_s("%s", &NAME, sizeof(NAME));
//printf("학번을 입력하세요 : ");
//scanf_s(" %d", &STD_NO);
//printf("\n학교명 : %s\n성함 : %s\n학번 : %d\n", UNI_NAME, NAME, STD_NO);
//
//for (int i = 0; i < 100; i++)
//{
//	printf("학교명의 %d 번째 배열요소 : %c\n", i, UNI_NAME[i]);
//	if (UNI_NAME[i] == 0)
//		break;
//}
//for (int i = 0; i < 100; i++)
//{
//	printf("성함의 %d 번째 배열요소 : %c\n", i, NAME[i]);
//	if (NAME[i] == 0)
//		break;
//}
//
//}

//void main()
//{
//	int sort[10];
//	int min, temp;
//	printf("정수를 10번 입력하시오.\n");
//	for (int i = 0; i < 10; i++)
//	{
//		printf("\n%d번째 정수 : ", i + 1);
//		scanf_s("%d", &sort[i]);
//	}
//	for (int i = 0; i < 9; i++)
//	{
//		min = i;
//		for (int j = i + 1; j < 10; j++)
//		{
//			if (sort[j] < sort[min])
//				min = j;
//		}
//		temp = sort[i];
//		sort[i] = sort[min];
//		sort[min] = temp;
//	}
//	for(int i=0;i<10;i++)
//	{
//		printf("%d ", sort[i]);
//	}
//	printf("\n");
//}
//void main()
//{
//	int list[10];
//	int min;
//	int temp;
//	printf("정수를 10번 입력하시오.\n");
//	for (int i = 0; i < 10; i++)
//	{
//		printf("\n%d번째 정수 : ", i + 1);
//		scanf_s("%d", &list[i]);
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		min = i;
//		for (int j = i + 1; j < 10; j++)
//		{
//			if (list[j] < list[min])
//			{
//				min = j;
//			}
//		}
//		temp = list[i];
//		list[i] = list[min];
//		list[min] = temp;
//	}
//	printf("\n정리한 배열은 ");
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", list[i]);
//	}
//	printf(" 입니다.");
//}


//void main()
//{
//	int x;
//	int m = 0;
//	int M = 101;
//	int T = 0;
//	srand((unsigned)time(NULL));
//	int n = rand() % 100 + 1;
//	while (T<10)
//	{
//		printf("임의로 정해진 n이 있을거같은 주소를 입력하시오 범위(%d~%d) : ",m+1,M-1);
//		scanf_s("%d", &x);
//		if (x == n)
//		{
//			printf("맞췄습니다.\n");
//			break;
//		}
//		else if (x < n)
//		{
//			m = x;
//
//		}
//		else if (x>n)
//		{
//			M = x;
//		}
//		T++;
//	}
//}

//void main()
//{
//	int x;
//	int m = 0;
//	int M = 101;
//	srand((unsigned)time(NULL));
//	int n = rand() % 100 + 1;
//	while (1)
//	{
//		printf("임의로 정해진 n이 있을거같은 주소를 입력하시오.");
//		scanf_s("%d", &x);
//		if (x == n)
//		{
//			printf("\n\n맞췄습니다!.\n\n");
//			break;
//		}
//		else if (x < n)
//		{
//			printf("\n\n업\n\n");
//
//		}
//		else if (x>n)
//		{
//			printf("\n\n다운\n\n");
//		}
//	}
//}

//void main()
//{
//	srand((unsigned)time(NULL));
//	int list[3][5];
//	for (int h = 0; h < 3; h++)
//	{
//		for (int y = 0; y < 5; y++)
//		{
//			list[h][y] = rand() % 100 + 1;
//		}
//	}
//	for (int h = 0; h < 3; h++)
//	{
//		for (int y = 0; y < 5; y++)
//		{
//			printf("%02d ",list[h][y]);
//		}
//		printf("\n");
//	}
//}

//void main()
//{
//	int h, y;
//	int list[3][5];
//
//	for (h = 0; h < 3; h++)
//		for (y = 0; y < 5; y++)
//			list[h][y] = 0;
//
//	for (h = 0; h < 3; h++)
//	{
//		for (y = 0; y < 5; y++)
//		{
//			printf("%d ", list[h][y]);
//		}
//		printf("\n");
//	}
//}

//void main()
//{
//	char board[3][3];
//	int x, y, k;
//	for (x = 0; x < 3; x++)
//		for (y = 0; y < 3; y++)board[x][y] = ' ';
//
//	for (k = 1; k <= 9; k++)
//	{
//		printf("좌표를 입력하시오 (가로 세로) : ");
//		scanf_s("%d %d", &x, &y);
//		board[3-y][x-1] = (k % 2 == 1) ? 'O' : 'X';
//		for (x = 0; x < 3; x++) {
//			for (y = 0; y < 3; y++)
//				printf(" %c", board[x][y]);
//			printf("\n");
//		}
//	}
//}

//void main()
//{
//	int h, y;
//	static int list[3][5];
//	int list2[3][5];
//
//	for (h = 0; h < 3; h++)
//	{
//		for (y = 0; y < 5; y++)
//		{
//			printf("%d ", list[h][y]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//	for (h = 0; h < 3; h++)
//	{
//		for (y = 0; y < 5; y++)
//		{
//			printf("%d ", list2[h][y]);
//		}
//		printf("\n");
//	}
//}

//main()
//{
//	int i = 10;
//	int *k;
//	int    *   p;
//	p = &i;
//	*p = 20;
//	printf("p는%d i는%d\n", *p, i);
//}

//main()
//{
//	int i = 10;
//	int *p = &i;
//
//	printf("i = %d, p = %p\n", i, p);
//	printf("i = %d, p = %p\n", i, p);
//	(*p)++;
//	printf("i = %d, p = %p\n", i, p);
//	printf("i = %d, p = %p\n", i, p);
//}

//void swap(int *x,int *y);
//
//int main()
//{
//	int a = 100;
//	int b = 200;
//	printf("a = %d, b = %d\n", a, b);
//	swap(&a, &b);
//	printf("a = %d, b = %d\n", a, b);
//	return 0;
//}
//void swap(int *x,int *y)
//{
//	int n;
//	n = *x; 
//	*x = *y;
//	*y = n;
//}


//swt(int []);
//void main() 
//{
//	int a[5] = {1,2,3,4,5};
//	swt(a);
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d ", a[i]);
//	}
//}
//swt(int x[])
//{
//	for (int i = 0; i < 5; i++)
//	{
//		x[i] = 5 - i;
//	}
//}


//void main()
//{
//	int *s;
//	s = (int *)calloc(100 , sizeof(int));
//	for (int i = 0; i < 10; i++)
//	{
//		s[i] = i;
//	}
//
//	int *t;
//	t = (int *)malloc(100 * sizeof(int));
//	memset(t, 0, 100 * sizeof(int));
//	for (int i = 0; i < 20; i++)
//	{
//		printf("%d ", s[i]);
//	}
//
//	memset(s, 0, 5*sizeof(int));
//	printf("\n");
//	for (int i = 0; i < 20; i++)
//	{
//		printf("%d ", s[i]);
//	}
//
//	printf("\n");
//	for (int i = 0; i < 20; i++)
//	{
//		printf("%d ", t[i]);
//	}
//	free(s);
//	free(t);
//}

//main()
//{
//	int a,b;
//	scanf_s("%d %d", &a, &b);
//	printf("%d %d", a, b);
//}

//void get_math(int x, int y, float *p_square, float *p_plus);
//main()
//{
//	int x, y;
//	float x_square_y, x_plus_y;
//	printf("x,y를 입력하시오 : ");
//	scanf_s("%d%d", &x, &y);
//	get_math(x,y,&x_square_y,&x_plus_y);
//	printf("x^y는 %.2f 이고 x+y는 %.f 입니다.", x_square_y, x_plus_y);
//}
//void get_math(int x, int y, float *p_square, float *p_plus)
//{
//	*p_plus = x + y;
//	*p_square = pow(x, y);
//}

//main()
//{
//	double sum = 0.0, variance, avg, x_square = 0.0;
//	int x[10] , i, n = 10;
//	for (i = 0; i < n; i++)
//		scanf_s("%d", &x[i]);
//	for (i = 0; i < n; i++)
//	{
//		sum = sum + x[i];
//		x_square = x_square + x[i] * x[i];
//	}
//	avg = sum / n;
//	variance = x_square / n - avg*avg;
//
//	printf("합은 %.2lf이고, 분산은 %.2lf 입니다.",sum, variance);
//}


//long double fact(int);
//long double exper(void);
//main()
//{
//	int x;
//	scanf_s("%d", &x);
//	printf("자연대수 e는 %.20lf 입니다.\n", exper());
//}
//
//long double fact(int n)
//{
//	if (n == 1 || n == 0)
//		return 1;
//	return fact(n - 1)*n;
//}
//
//long double exper(void)
//{
//	int n = 1;
//	long double oldexp = 0, newexp = 1;
//	while (oldexp != newexp)
//	{
//		oldexp = newexp;
//		newexp = newexp + 1 / fact(n);
//		n++;
//	}
//	return newexp; 
//}

//main()
//{
//	long double pi = 0;
//	long double tmp = 0;
//	for (int i = 1; i <= 10000; i++)
//	{
//		tmp = tmp + 6 / pow(i, 2);
//		pi = sqrt(tmp);
//		if (i % 1000 == 0)
//		{
//			printf("%.20lf,%.20lf\n", pi, M_PI);
//			printf("오차율 : %.20lf\n", ((M_PI - pi)/M_PI)*100);
//		}
//	}
//	printf("%.20lf\n", pi);
//}

#define F(x) (1.0/1.0+(x))
main()
{
	double integ, h, x;
	double log2 = log(2);
	printf("구간\tlog2\t\t\t사다리꼴 적분\t\t오차\n");
	printf("==============================================================\n");

	for (int n = 10; n < 10000000; n *= 10)
	{
		integ = 0.0;
		for (int k = 0; k <= n; k++)
		{
			h = 1.0 / (double)n;
			x = h * (double)k;
			if ((k == 0) || (k == n))
				integ += F(x);
			else
				integ += 2*F(x);
		}
		integ = h * integ / 2.0;
		printf("%d\t%.18lf\t%.18lf\t%.18lf\n", n, log2, integ, log2 - integ);
	}
}
