//#pragma warning (disable : 4996)
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//void input(char*);
//int calcul(char*);
//void print(char*, int);
//
//int main()
//{
//	int sum;
//	char str[100];
//	input(str);
//	sum = calcul(str);
//	print(str, sum);
//}
//
//void input(char* str)
//{
//	printf("# 문장을 입력하시오 : ");
//	scanf("%s", str);
//}
//
//int calcul(char* str)
//{
//	int i = 0;
//	char a[10][10];
//	for (int j = 0; j < strlen(str) - i;) {
//		for (i = 0; i < strlen(str); i++) {
//			if (str[i] >= '0' && str[i] <= '9') {
//				a[j][i] = str[i];
//				if (str[++i] >= '0' && str[++i] <= '9') {
//					a[j][i] = str[i];
//					if (str[++i] >= '0' && str[++i] <= '9') {
//						a[j][i] = str[i];
//					}
//				}
//				j++;
//			}
//		}
//	}
//	for (i = 0; i < 3; i++)
//		for (int j = 0; j < 4; j++)
//			printf("%d ", a[i][j]);
//	
//	
//	return 0;
//}
//
//void print(char* str, int sum)
//{
//
//}

#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
void input(char*);
int cal(char*, int);
void output(char*, int);

int main() {
    char str[100] = { 0 };
    int len, sum;
    while (1) {
        input(str);
        if (strcmp(str, "end") == 0)
            break;
        len = strlen(str);
        sum = cal(str, len);
        output(str, sum);
    }
}

void input(char* sp) {
    printf("# 문장을 입력하시오 : ");
    scanf("%s", sp);
}

int cal(char* sp, int len) {
    int i, sum = 0, a, j = 0;
    for (i = j; i < len; i++) {
        a = 0;
        if (48 <= sp[i] && sp[i] <= 57) {
            a += sp[i] - '0';
            for (j = i + 1; j < len; j++) {
                if (48 <= sp[j] && sp[j] <= 57)
                {
                    a = 10 * a + (sp[j] - '0');
                    /*if (j == len - 1) {

                        sum += a;
                        break;
                    }*/
                    i++;
                }
                else {

                    j++;
                    break;
                }
            }

        }
        else
            ;
        sum += a;

    }
    return sum;

}

void output(char* sp, int sum) {
    printf("%s 내의 총 숫자는 [%d]입니다.\n\n", sp, sum);
}
//== '0' || '1' || '2' || '3' || '4' || '5' || '6' || '7' || '8' || '9'