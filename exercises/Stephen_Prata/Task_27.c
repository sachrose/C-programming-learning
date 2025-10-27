/*Определить рекурсивную функцию, принимающую целый аргумент и возвращающую его факториал.
Факториал 3 записывается как 3!, а вычисляется как 3*2! и т.д., причем 0! равен 1. В общем случае, если n больше нуля, то n! = n*(n-1)!
Необходимо протестировать функцию в программе, использующей цикл, где пользователь может вводить различные значения,
для которых программа вычисляет и отображает факториалы. */

#include <stdio.h>

unsigned long long factorial(int n) {
    if (n == 0)
    {
        return 1;
    }
    
    else
    {
        return n * factorial(n -1);
    }
}

int main(){

    int number;
    printf("Enter numbers to calculate factorial (negative to quit): ");

    while(scanf("%d", &number) && number >= 0)
    {
        printf("factorial %d is %llu\n", number, factorial(number));
        printf("Ener the next number: ");
    }

    return 0;
}