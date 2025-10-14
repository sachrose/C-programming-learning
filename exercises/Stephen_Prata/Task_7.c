/*Написать программу, которая приглашает пользователя ввести 3 результата забега на 40 метров и затем отображает эти значения и среднее.
Для хранения данных применить объект array (если array недоступен - воспользоваться встроенным массивом).*/

#include <stdio.h>
#define SIZE 3

int main() {

    float results[SIZE];
    float sum = 0;

    for(int i = 0; i < SIZE; i++){
        printf("\nEnter result for turn %d: ", i+1);
        scanf("%f", &results[i]);
        sum += results[i];
    }

    printf("\nYour results is: ");
    for(int i = 0; i < SIZE; i++){
        printf("%.1f, ", results[i]);
    }
    printf("Average: %.1f\n", sum / SIZE);

    return 0;
}