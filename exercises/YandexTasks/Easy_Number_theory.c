/* Даны 2 натуральных числа a a и b b. Необходимо посчитать НОД(a, b) и НОК(a, b).
Напомним, что:
НОД ( a , b ) − НОД(a,b)− наибольшее натуральное число, на которое числа a, b делятся без остатка.
НОК ( a , b ) − НОК(a,b)− наименьшее натуральное число, которое делится на числа a, b без остатка.
Формат ввода:
Единственная входная строка содержит два числа − − a , b ( 1 ≤ a , b ≤ 1 0 9 ) a,b(1≤a,b≤109).
Формат вывода:
Выведите 2 целых числа − − НОД ( a , b ) НОД(a,b) и НОК ( a , b ) НОК(a,b). */

#include <stdio.h>

int get_GCD(int a, int b);
int get_LCM(int a, int b);

int main()
{
    int a, b;
    printf("Enter 2 numbers: \n");
    while (1)
    {
        if (scanf("%d %d", &a, &b) == 2)
        {
            if (a > 0 && b > 0)
            {
                break;
            }
            else
            {
                printf("Numbers must be greather than 0!\n");
                while(getchar() != '\n');
            }
        }
        else
        {
            while(getchar() != '\n');
            printf("Invalid input. Enter 3 numbers: ");
        }
    }
    
    printf("НОД: %d, НОК: %d\n", get_GCD(a, b), get_LCM(a, b));
    return 0;
}

int get_GCD(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a >= b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }
    return (a > b) ? a : b;
}

int get_LCM(int a, int b)
{
    return (a * b) / get_GCD(a, b);
}