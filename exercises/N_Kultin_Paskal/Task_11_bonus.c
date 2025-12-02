/*Найти:
-сумму всех целых чисел от 100 до 500
-сумму всех целых чисел от а до 500
-сумму всех целых чисел от -10 до b
-сумму всех целых чисел от а до b

-среднее арифметическое всех целых чисел от 1 до 1000
-седнее арифметическое всех целых чисел от 100 до b */

#include <stdio.h>

int manager(void);
int sum(int a, int b);
int sum_100500(void);
int sum_a500(void);
int sum_minus10b(void);
int sum_ab(void);
double avrg_1_1000(void);
double avrg_100b(void);

int main()
{
    manager();
    return 0;
}

int manager(void)
{
    printf("Let's the show begin!\a\n");
    printf("%d\n", sum_100500());
    printf("%d\n", sum_a500());
    printf("%d\n", sum_minus10b());
    printf("%d\n", sum_ab());
    printf("%.2lf\n", avrg_1_1000());
    printf("%.2lf\n", avrg_100b());
}

int sum(int a, int b)
{
    int sum = 0;
    for (int i = a; i <= b; i++)
    {
        sum += i;
    }
    return sum;
}

int sum_100500(void)
{
    printf("Calculating sum from 100 to 500...");
    return sum(100, 500);
}

int sum_a500(void)
{
    int a = 0;
    printf("Enter a number no greater than 500: ");
    while (scanf("%d", &a) != 1 || a > 500)
    {
        printf("Error! Try again.\n");
        while(getchar() != '\n');
    }
    while(getchar() != '\n');

    printf("Calculating sum from %d to 500...", a);
    return sum(a, 500);
}

int sum_minus10b(void)
{
    int b = 0;
    printf("Enter a number no less than -10: ");
    while (scanf("%d", &b) != 1 || b < -10)
    {
        printf("Error! Try again.\n");
        while(getchar() != '\n');
    }
    while(getchar() != '\n');

    printf("Calculating sum from -10 to %d...", b);
    return sum(-10, b);
}

int sum_ab(void)
{
    int a = 0;
    int b = 0;

    printf("Enter two numbers: ");   
    while (scanf("%d", &a) != 1 || scanf("%d", &b) != 1 || a > b)
    {
        printf("Error! Try again.\n");
        while(getchar() != '\n');
    }
    while(getchar() != '\n');

    printf("Calculating sum from %d to %d...", a, b);
    return sum(a, b);
}

double avrg_1_1000(void)
{
    printf("Calculating average from 1 to 1000...");
    return (float)sum(1, 1000)/1000;
}

double avrg_100b(void)
{
    int b = 0;
    int count = 0;
    int sum = 0;
    printf("Enter a number no less than 100: ");
    while (scanf("%d", &b) != 1 || b < 100)
    {
        printf("Error! Try again.\n");
        while(getchar() != '\n');
    }
    while(getchar() != '\n');

    printf("Calculating average from 100 to %d...", b);
    for (int i = 100; i <= b; i++)
    {
        sum += i;
        count++;
    }
    return (double)sum/count;
}