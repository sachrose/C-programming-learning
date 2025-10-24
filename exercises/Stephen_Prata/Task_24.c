/*Написать программу, которая запрашивает у пользователя 10 результатов игры в гольф, сохраняя их в массиве.
При этом необходимо обеспечить возможность прекращения ввода до ввода всех 10 результатов.
Программа должна отобразить все результаты в одной строке и сообщить их среднее значение.
Реализуйте ввод, отображение и вычисление среднего в трёх отдельных функциях, работающих с массивами. */

#include <stdio.h>
#define MAX_SIZE 10

int input_scores(float *results)
{
    int count = 0;

    printf("Enter your results up to %d (non-number to stop): ", MAX_SIZE);

    while(count < MAX_SIZE && scanf("%f", &results[count]) == 1)
    {
        count++;
    }

    while (getchar() != '\n');
    return count;        
}

float calculate_average(float *results, int count)
{
    float sum = 0.0;
    for(int i = 0; i < count; i++)
    {
        sum += results[i];
    }
    return sum/count;
}

void display_scores(float *results, int count, float average)
{
    printf("Your results: ");
    for(int i = 0; i < count; i++)
    {
        printf("%.2f ", results[i]);
    }
    printf("and the average %.2f\n", average);
}

int main(){

    float scores[MAX_SIZE];
    int count = input_scores(scores);
    float avg = calculate_average(scores, count);
    display_scores(scores, count, avg);

    return 0;
}