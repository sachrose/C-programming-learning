/*Спроектировать функцию calculate(), которая принимает 2 значения типа double и указатель на функцию, принимающую 2 агрумента double и возвращаюую значение double.
Например, есть функция dd():

double add(double x, double y)
{
    return x + y;
}
Вызов функции calculate() должен заставить передать 2 значения в функцию add() и вернуть результат: double q = calculate(2.5, 10.4, add);
Использовать в программе эту функцию и хотябы еще одну дополнительную, подобную add(). Организовать цикл, приглашающий пользователя вводить пары чисел.
Для каждой пары calculate() должна вызывать add() и хотя бы еще одну функцию такого рода. Попробовать создать массив указателей на функции, подобные add() и организовать цикл,
применяя calculate() для вызова функций по их указателям. */


#include <stdio.h>

double calculate(double x, double y, double (*func)(double, double))
{
    return func(x, y);
}

double add(double x, double y) { return x + y; }
double multiply(double x, double y) { return x * y; }
double subtract(double x, double y) { return x - y; }

int main(){

    double a, b;
    double (*ops[3])(double, double) = {add, multiply, subtract};
    const char *op_names[] = {"Addition", "Multiplication", "Subtraction"};
    const char op_symbols[] = {'+', '*', '-'};

    printf("Enter pairs of numbers (q to quit): ");
    while (scanf("%lf %lf", &a, &b))
    {
        for(int i = 0; i < 3; i++)
        {
            double result = calculate(a, b, ops[i]);
            printf("%s: %.2f %c %.2f = %.2f\n", op_names[i], a, op_symbols[i], b, result);
        }
        printf("Next pair: ");
    }
    
    return 0;
}