/*Предположим, что я продаю книгу. Надо написать программу, которая позволит ввести ежемесячные объемы продаж в течение года (в количестве книг).
Программа должна использовать цикл, в котором выводится приглашание с названием месяца, применяя массив указателей на char,
инициализированный строками - названиями месяцев, и сохраняя введенные значения в массиве int.Затем программа должна найти сумму содержимого массива
и выдать общий объем продаж за год.

Дополнительно: Необходимо использовать двумерный массив для хранения данных о месячных продажах за 3 года.
Выдать общую сумму продаж за каждый год и за 3 года вместе.*/

#include <stdio.h>

int main(){

    char *month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int sales[3][12];
    int sales_for_year = 0;
    int total = 0;

    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 12; j++){
            printf("Enter sales for %s: ", month[j]);
            scanf("%d", &sales[i][j]);
            sales_for_year += sales[i][j];
        }
        printf("Your sales for %d year: %d copies\n", i+1, sales_for_year);
        total += sales_for_year;
        sales_for_year = 0;
    }
    printf("%d copies were sold for all time\n", total);

    return 0;
}