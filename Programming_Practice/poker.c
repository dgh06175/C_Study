#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#pragma warning(disable:4996)

#define MAX_CARD_TYPE 4
#define MAX_CARD_NUM 13

void PrintCard(int, int, int);
void sort_array(int*);

const char* ctypes[MAX_CARD_TYPE] = { "♠","♥","♣","◆" };
const char* ntypes[MAX_CARD_NUM] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };

/* 카드 정보 출력하는 함수 */
void PrintCard(int lcnt, int ct, int cn)
{//                n번째,    0~3,   0~12
    printf("%2d번째 카드 %s%s\n", lcnt, ctypes[ct], ntypes[cn]);
}

/* 카드들을 숫자순으로 오름차순으로 정렬하는 함수 */
void sort_array(int* array)
{
    int tmp;
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 5; j++)
            if (array[i] > array[j])
            {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
}

void main()
{
    int num, type;
    int array[5] = { -1,-1,-1,-1,-1 };
    char y = 0;
    int x;
    srand((unsigned)time(NULL));
    printf("카드를 5장 뽑는 프로그램\n");
    printf("Input number of player [1-5]: ");
    scanf("%d", &x);
    while (getchar() != '\n'); // 위의 scanf에서 숫자 넣고 엔터누르다가 \n문자가 버퍼에 남아있어서 아래에서 오류가 나므로 버퍼를 비워줌
    while (1)
    {
        if (y != 'z') // y == 'z' 인 경우 프로그램 종료
        {
            for (int l = 0; l < x; l++) // 입력한 x번만큼 카드5장을 뽑음
            {
                /* 카드 5장을 랜덤으로 뽑는 부분 */
                for (int i = 0; i < 5; i++) // 5장 뽑는거니까 5번
                {
                    while (1) //이번 패에 중복된 카드가 있는지, 페어가 있는지 검사
                    {
                        int n = 0;
                        array[i] = rand() % (MAX_CARD_TYPE * MAX_CARD_NUM); // array[i]에 0~51 저장
                        if (i == 0) break; //i=0 이면 첫번째 카드여서 중복검사,pair검사 할 필요가 없으니까 루프 탈출
                        for (int j = 0; j < i; j++)
                        {
                            if (array[i] == array[j])n++; //뽑았던 카드랑 중복이면 다시뽑아야 하므로 중복일 경우 n++해서 나중에 n이 0이 아니면 다시 뽑음
                            // if (array[i] % MAX_CARD_NUM == array[j] % MAX_CARD_NUM && n == 0) m++; //뽑았던 카드와 숫자가 같으면 pair니깐 m++ (단, 중복이 아닐 경우에) // 이건 pair인지만 검사하는 프로그램일때의 코드
                        }
                        if (n == 0) break; //n=0 이면 중복이 하나도 없었다는 뜻이므로 다시 뽑지 않기 위해 루프 탈출(array[i]값 확정)
                    }
                    type = array[i] / MAX_CARD_NUM; // array[]안의 어떤 값 / MAX_CARD_MUM 은 그 카드의 문자가 된다
                    num = array[i] % MAX_CARD_NUM; // array[]안의 어떤 값 % MAX_CARD_MUM 은 그 카드의 숫자가 된다
                    PrintCard(i + 1, type, num); // Printcard()에 몇번째에 무슨 카드가 나왔는지 전달
                    //         n번째, 0~3, 0~12
                }
                //int array[5] = { 9, 23, 37, 25, 21}; // 코딩중 사용하기 위해 임의로 카드 입력

                /* 원페어, 투페어, 트리플, 포카드 검사하는 부분 */
                int pair[5] = { 0, }; // 페어 검사에 사용할 배열 pair을 선언, 모두 0으로 초기화

                for (int i = 0; i < 4; i++) // i번째 카드와 그 다음 카드를 검사하는거라 i = 4(5번째 카드)로 할 필요는 없어서 i < 4
                {
                    for (int j = i + 1; j < 5; j++) // i번째 카드 와 그 다음카드들을 비교하니까 j = i + 1이고, 5번째 카드(j=4) 까지
                        if (array[i] % MAX_CARD_NUM == array[j] % MAX_CARD_NUM) // i번째 카드와 j번째 카드의 숫자가 같으면 pair[i]++ 이렇게 하면
                            pair[i]++;                                          // 첫번째 카드의 숫자로 페어가 나오면 pair[0] == 1, 트리플이 나오면 pair[0] == 2; 포카드가 나오면 pair[0] == 3;
                }                                                               // 두번째 카드와 세번째 카드의 숫자로 페어가 나와서 투페어면 pair배열 = { 0, 1, 1, 0, 0};
                
                int pair_count[4] = { 0, }; // pair[]안에 있는 숫자를 세기 위한 배열 pair_count[i] 는 pair[] 안에 있는 i의 개수이다 ex) pair[]가 { 2, 0, 1, 1, 0 }라면 pair_count는 { 2, 2, 1, 0 }이 됨 (0이 2개, 1이 2개, 2가 1개, 3이 0개)
                for (int i = 0; i < 5; i++)
                    for (int j = 0; j < 4; j++)
                        if (pair[i] == j) pair_count[j]++;

                /* 스트레이트 검사하는 부분 */
                /* 스트레이트의 경우의 수
                0  1  2  3  4
                1  2  3  4  5
                2  3  4  5  6
                3  4  5  6  7
                4  5  6  7  8
                5  6  7  8  9
                6  7  8  9  10
                7  8  9  10 11
                8  9  10 11 12
                0  9  10 11 12
                */
                int straight = 0;
                int mountain = 0;
                int count = 0;
                int sorted_array[5]; // 스트레이트를 검사하려면 정렬해야함
                for (int i = 0; i < 5; i++)
                    sorted_array[i] = array[i] % MAX_CARD_NUM;
                sort_array(sorted_array); // sort_array는 5가지 카드에서 숫자만 뽑아서 오름차순으로 정렬한 배열이 됨 ex) { 0, 5, 5, 8, 10 }
            
                if (sorted_array[1] + 1 == sorted_array[2])
                    if (sorted_array[2] + 1 == sorted_array[3])
                        if (sorted_array[3] + 1 == sorted_array[4])
                        {
                            if (sorted_array[0] + 1 == sorted_array[1])
                                straight = 1;
                            else if (sorted_array[1] == 9 && sorted_array[0] == 0) // 9 10 11 12 0 인 경우
                                mountain = 1;
                        }

                if (pair_count[0] == 4 && pair_count[1] == 1) printf(" one pair\n");             // pair[](예시) == { 0, 0, 1, 0, 0 } , pair_count[](고정) == { 4, 1, 0, 0 }
                else if (pair_count[0] == 3 && pair_count[1] == 2) printf(" two pair\n");        // pair[](예시) == { 0, 1, 1, 0, 0 } , pair_count[](고정) == { 3, 2, 0, 0 }
                else if (pair_count[0] == 3 && pair_count[1] == 1) printf(" three of a Kind\n"); // pair[](예시) == { 2, 1, 0, 0, 0 } , pair_count[](고정) == { 3, 1, 1, 0 }
                else if (pair_count[0] == 2 && pair_count[1] == 2) printf(" full house\n");      // pair[](예시) == { 2, 1, 1, 0, 0 } , pair_count[](고정) == { 2, 2, 1, 0 }
                else if (pair_count[0] == 2 && pair_count[1] == 1) printf(" four of a Kind\n");  // pair[](예시) == { 3, 2, 1, 0, 0 } , pair_count[](고정) == { 2, 1, 1, 1 }
                else if (straight == 1) printf(" straight\n");
                else if (mountain == 1) printf(" mountain\n");
                
                printf("\n");
            }
            printf("엔터를 누르면 다음판으로 넘어가고 z를 누르면 게임을 종료합니다.\n");
            scanf("%c", &y);
        }
        else // y == 'z' 인 경우
            break;
    }
}