/*Написать программу, которая выводит на экран квадрат Пифагора - таблицу умножения.*/

#include <stdio.h>

int main(){

    printf("\t\t=== Pifagorean Table ===\n\n");
    int size = 10;
    printf(" \t");
    for (int i = 1; i <= size; i++)
    {
        printf("%5d", i);
    }
    printf("\n\n");
    
    for (int i = 1; i <= size; i++)
    {
        printf("%d\t", i);
        for (int j = 1; j <= size; j++)
        {
            printf("%5d", i * j);
        }
        printf("\n");
    }
      
    return 0;
}