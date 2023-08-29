#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
#define player 2
#define TYPE 4
#define NUM 13

const char* ctypes[TYPE] = { "♠","♥","♣","◆" };
const char* ntypes[NUM] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
//52장의 카드를 임의로 배열 array[52]에 순차적으로 넣기
void generate(int array[]);
//player1[7], player2[7]에 array배열 0부터 13까지 숫자 넣기
void change(int player1[], int player2[], int array[]);
//컴퓨터의 두 장은 ***로 나타내고 나머지 한 장과 나의 카드 3장을 오픈하기
void open1(int player1[], int player2[]);
//게임을 계속 진행할지 종료할지 기권하고 새 게임을 받을지 결정
int bet();
//x까지의 카드를 오픈
void show(int player1[], int player2[], int x);
//컴퓨터와 나의 카드 모두를 오픈
void showall(int player1[], int player2[]);
//컴퓨터의 카드가 무슨 조합인지 체크
int made1(int player1[]);
//나의 카드가 무슨 조합인지 체크
int made2(int player2[]);
//컴퓨터의 카드를 오름차순으로 정렬
void sort1(int player1[]);
//나의 카드를 오름차순으로 정렬
void sort2(int player2[]);
void swap(int* xp, int* yp);
//컴퓨터의 조합과 나의 조합을 비교하여 승자를 결정
void winner(int result1, int result2);
//count1=컴퓨터가 이긴 횟수 , count2=내가 이긴 횟수, count3=무승부 횟수
int count1 = 0, count2 = 0, count3 = 0;
void main()
{
    printf("================================================\n");
    printf("           포커게임 (Player 2는 나)             \n");
    printf("================================================\n");
    srand((unsigned)time(NULL));
    while (1)
    {

        int b = 0;//bet함수에 입력받는 b를 초기화
        int result1 = 0, result2 = 0; // 컴퓨터와 나의 조합을 입력할만한 변수 초기화
        int array[52] = { 0 };
        int player1[7];
        int player2[7];
        generate(array);
        change(player1, player2, array);
        open1(player1, player2);
        if (bet() == 1)//3장이 오픈된 상황에서 배팅을 걸고 b==1일 때 다음 작업 실행
        {
            show(player1, player2, 3);
            if (bet() == 1)
            {
                show(player1, player2, 4);
                if (bet() == 1)
                {
                    show(player1, player2, 5);
                    if (bet() == 1)
                    {
                        show(player1, player2, 6);
                        showall(player1, player2);
                        sort1(player1);
                        sort2(player2);
                        result1 = made1(player1);
                        result2 = made2(player2);
                        winner(result1, result2);
                    }
                }
            }


        }
    }


}

void generate(int array[])
{
    int i;
    for (i = 0; i < 52; i++)
    {
        while (1)
        {
            int n = 0;//중복된 카드가 있는지 확인하기 위한 변수 초기화
            array[i] = rand() % 52;
            if (i == 0) break;//첫번째로 뽑고 중복 결과 확인 안하고 두 번째 카드 뽑기
            for (int j = 0; j < i; j++)
                if (array[i] == array[j])
                    n++;
            if (n == 0)
                break;
        }
    }
}

void change(int player1[], int player2[], int array[])
{
    int i, j;
    for (i = 0; i < 7; i++)
        player1[i] = array[i];
    for (j = 0; j < 7; j++)
        player2[j] = array[j + 7];

}

void open1(int player1[], int player2[])
{
    int type1, num1, type2, num2;//type1은 player1의 카드의 모양, num1은 player1의 카드의 숫자
    printf("     <Player 1 의 카드>\n");
    type1 = player1[2] / NUM;//0="♠",1="♥",2="♣",3="◆"
    num1 = player1[2] % NUM;//0="A", 10="J", 11="Q", 12="K"
    printf("   ***   ***");
    printf("   %s %s\n", ctypes[type1], ntypes[num1]);
    printf("     <Player 2 의 카드>\n");
    for (int i = 0; i < 3; i++)
    {
        type2 = player2[i] / NUM;
        num2 = player2[i] % NUM;
        printf("   %s %s", ctypes[type2], ntypes[num2]);
    }
}

int bet()
{
    printf("\n계속 받기 : 1     게임 종료 : 2     기권후 새 게임 : 3\n");
    int b;
    scanf("%d", &b);

    if (b == 1)
    {
        printf("한 장씩 더 받도록 하겠습니다.\n\n");
        return 1;
    }
    else if (b == 2)
    {
        count1++;
        printf("모든 게임이 종료되었습니다.\n");
        printf("당신은 Player 1 상대로 %d승 %d무 %d패 하였습니다.\n\n", count2, count3, count1);
        exit(1);
        return 0;
    }
    else if (b == 3)
    {
        count1++;
        printf("Player 1 님께서 승리하셨습니다.\n\n");
        return 0;
    }
    return 0;
}

void show(int player1[], int player2[], int x)
{
    int type1, num1, type2, num2;
    printf("     <Player 1 의 카드>\n");
    printf("   ***   ***");
    for (int i = 2; i <= x; i++)
    {
        type1 = player1[i] / NUM;
        num1 = player1[i] % NUM;
        printf("   %s %s", ctypes[type1], ntypes[num1]);
    }
    printf("\n");
    printf("     <Player 2 의 카드>\n");
    for (int i = 0; i <= x; i++)
    {
        type2 = player2[i] / NUM;
        num2 = player2[i] % NUM;
        printf("   %s %s", ctypes[type2], ntypes[num2]);
    }

}

void showall(int player1[], int player2[])
{
    int i;
    int type1, num1, type2, num2;
    printf("\n모든 카드를 오픈하겠습니다.\n\n");
    printf("   Player 1의 카드:   ");
    for (i = 0; i < 7; i++)
    {
        type1 = player1[i] / NUM;
        num1 = player1[i] % NUM;
        printf("   %s %s", ctypes[type1], ntypes[num1]);
    }
    printf("\n");
    printf("   Player 2의 카드:   ");
    for (i = 0; i < 7; i++)
    {
        type2 = player2[i] / NUM;
        num2 = player2[i] % NUM;
        printf("   %s %s", ctypes[type2], ntypes[num2]);
    }
    printf("\n");
}

int made1(int player1[])
{
    int check1 = 0;//중복이 있을 때마다 check가 하나씩 증가하는데 그 전에 check를 0으로 초기화
    int i, j;
    int result1 = 0;
    for (i = 0; i < 6; i++)
    {
        for (j = i + 1; j < 7; j++)
            if (player1[i] % 13 == player1[j] % 13)
                check1++;
    }

    switch (check1)
    {
    case 1: result1 = 1;// 원페어
        break;
    case 2: result1 = 2;// 투페어
        break;
    case 3: result1 = 3;// 트리플
        break;
    case 4: result1 = 4;// 풀 하우스(원페어+투페어)
        break;
    case 6: result1 = 6;// 포 카드
        break;
    default:
        break;
    }
    int check2 = 0;// 플러쉬를 체크하기 위한 check2변수를 0으로 초기화
    for (int i = 0; i < 6; i++)
    {

        for (int j = i + 1; j < 7; j++)
            if (player1[i] / NUM == player1[j] / NUM)// NUM으로 나눈 몫으로 모양을 가지고 판단한다
                check2++;
    }
    if (check2 == 10)
        result1 = 10;

    for (int k = 0; k < 3; k++)
        if ((player1[k] % 13) + 1 == player1[k+1] && (player1[k] % 13) + 2 == player1[k+2] && (player1[k] % 13) + 3 == player1[k+3] && (player1[k] % 13) + 4 == player1[k+4])
            result1 = 15;

    printf("Player 1의 카드는 : ");
    if (result1 == 1)// check1,check2의 숫자를 result1에 넣어 case별로 결과 출력
        printf("원페어\n");
    else if (result1 == 2)
        printf("투페어\n");
    else if (result1 == 3)
        printf("트리플\n");
    else if (result1 == 4)
        printf("풀 하우스\n");
    else if (result1 == 6)
        printf("포카드\n");
    else if (result1 == 10)
        printf("플러쉬\n");
    else if (result1 == 15)
        printf("스트레이트\n");
    else if (result1 == 0)
        printf("탑\n");
    return result1;
}

int made2(int player2[])
{
    int check3 = 0;
    int i, j;
    int result2 = 0;
    for (i = 0; i < 6; i++)
    {
        for (j = i + 1; j < 7; j++)
            if (player2[i] % 13 == player2[j] % 13)
                check3++;
    }


    switch (check3)
    {
    case 1: result2 = 1;// 원페어
        break;
    case 2: result2 = 2;// 투페어
        break;
    case 3: result2 = 3;// 트리플
        break;
    case 4: result2 = 4;// 풀 하우스(원페어+투페어)
        break;
    case 6: result2 = 6;// 포 카드
        break;
    default:
        break;
    }
    int check4 = 0;
    for (int i = 0; i < 6; i++)
    {

        for (int j = i + 1; j < 7; j++)
            if (player2[i] / NUM == player2[j] / NUM)
                check4++;
    }
    if (check4 == 10)
        result2 = 10;
    printf("Player 2의 카드는 : ");
    if (result2 == 1)
        printf("원페어\n");
    else if (result2 == 2)
        printf("투페어\n");
    else if (result2 == 3)
        printf("트리플\n");
    else if (result2 == 4)
        printf("풀 하우스\n");
    else if (result2 == 6)
        printf("포카드\n");
    else if (result2 == 10)
        printf("플러쉬\n");
    else if (result2 == 0)
        printf("탑\n");
    return result2;
}

void swap(int* xp, int* yp)
{
    int temp;
    temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort1(int player1[])
{
    int n, m, minindex;//minindex는 최소값을 가진 인덱스
    for (n = 0; n < 6; n++)
    {
        minindex = n;// n을 minindex로 설정해놓고 그 다음것들 과 비교했을 때 더 작은 숫자가 있으면 swap
        for (m = n + 1; m < 7; m++)
            if (player1[minindex] > player1[m])
                minindex = m;
        swap(&player1[minindex], &player1[n]);
    }
}
void sort2(int player2[])
{
    int n, m, minindex;
    for (n = 0; n < 6; n++)
    {
        minindex = n;
        for (m = n + 1; m < 7; m++)
            if (player2[minindex] > player2[m])
                minindex = m;
        swap(&player2[minindex], &player2[n]);
    }
}

void winner(int result1, int result2)
{

    if (result1 > result2)
    {
        printf("\nPlayer 1이 승리하였습니다.\n\n");
        count1++;
    }
    else if (result1 == result2)
    {
        printf("\n\n무승부 입니다.\n\n");
        count3++;
    }
    else
    {
        printf("\nPlayer 2가 승리하였습니다.\n\n");
        count2++;
    }
}