/*Вильям Вингейт заведует службой анализа рынка пиццы. О каждой пицце он записывает следующую информацию:
1. наименование компании (может состоять из более чем одного слова)
2. диаметр пиццы
3. вес пиццы
Необходимо разработать структуру, которая будет содержать всю эту информацию и написать программу,
использующую структурную переменную этого типа. Программа должна запрашивать у пользователя каждый показатель
и затем отображать введенную информацию.*/

#include <stdio.h>

struct Pizza {
    char company[50];
    float diameter;
    int weight;
};

int main(){

    struct Pizza sample;

    printf("Enter your data (company): ");
    scanf("%49[^\n]", sample.company);

    printf("\nEnter your data (diameter in centimeters): ");
    scanf("%f", &sample.diameter);

    printf("\nEnter your data (weight in grams): ");
    scanf("%d", &sample.weight);

    printf("\nPizza is cooked by %s, diameter is %.1f cm, weight is %d grams\n", sample.company, sample.diameter, sample.weight);

    return 0;
}