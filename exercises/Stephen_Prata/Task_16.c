/*Написать программу, которая читает в массив double до 10 значений пожертвований.
Программа должна прекращать ввод при полуении нечисловой величины.
Она Должна выдавать среднее значение полученных чисел, а также количество значений в массиве, превышающих среднее. */

#include <stdio.h>

int main(){

    double donations[10];
    double sum = 0;
    double average = 0;
    int count = 0;
    int above_average = 0;

    printf("Enter the donation amount:\n");

    while(count < 10 && scanf("%lf", &donations[count]) == 1){
        sum += donations[count];
        count++;
    }

    average = (count > 0) ? sum/count : 0.0;

    for(int i = 0; i < count; i++){
        if (donations[i] > average){
            above_average++;
        }
    }

    printf("Average is %.2lf, %d values exceed the average\n", average, above_average);

    return 0;
}