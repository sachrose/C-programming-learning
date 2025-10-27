/*Что делает программа:

    Хранит названия времён года в массиве строк

    Запрашивает расходы для каждого времени года

    Выводит расходы и общую сумму*/

#include <stdio.h>

const int SEASONS = 4;
const char *SNAMES[] = {"Spring", "Summer", "Fall", "Winter"};

void fill(double expenses[])
{
    for(int i = 0; i < SEASONS; i++)
    {
        printf("Enter %s expenses:\n", SNAMES[i]);
        scanf("%lf", &expenses[i]);
        while (getchar() != '\n');
    }
}

void show(double expenses[])
{
    double total = 0.0;
    for(int i = 0; i < SEASONS; i++)
    {
        printf("%s: $%.2lf\n", SNAMES[i], expenses[i]);
        total += expenses[i];
    }
    printf("Total expenses: %.2lf\n", total);
}

int main() {
    double expenses[SEASONS];
    fill(expenses);
    show(expenses);
    return 0;
}