#pragma warning (disable : 4996)
#include <stdio.h>
void input(double*);
double MAX1(double*);
double MIN1(double*);
void print_result(double, double);

int main()
{
    double a[5];
    input(a);
    print_result(MAX1(a), MIN1(a));
    return 0;
}

void input(double* a)
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d번 방 값 : ", i);
        scanf("%lf", &a[i]);
    }
}

double MAX1(double* a)
{
    double n = a[0];
    for (int i = 0; i < 5; i++)
    {
        if (n < a[i])
            n = a[i];
    }
    return n;
}

double MIN1(double* a)
{
    double n = a[0];
    for (int i = 0; i < 5; i++)
    {
        if (n > a[i])
            n = a[i];
    }
    return n;
}

void print_result(double max, double min)
{
    printf("\n\n가장 큰 값 : %.2lf\n가장 작은 값 : %.2lf\n", max, min);
}