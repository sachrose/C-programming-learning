/*Написать программу, использующую описанные ниже функции:
fill_array()  - инимает в качестве аргумента имя массива элементов типа double и размер массива.
Приглашает пользователя ввести значения doube  для помещения их в массив. Ввод прекращается при наполнении массива,
либо когда пользователь вводит нечисловое значение и возвращает действительное количество элементов.

show_array() - принимает в качестве аргумента имя массивов значений double а также размер массива, отображает содержимое массива. 

reverce_array() - принимает в качестве аргумента имя массивов значений double а также размер массива.
Изменяет порядок его элементов на противоположный.

Программа должна использовать эти функции для наполнения массива, обращения порядка его элементов,
кроме первого и последнего, с последующим отображением. 
*/

#include <stdio.h>

#define MAX_SIZE 100

int fill_array(double *array, int a)
{
    int i = 0;
    while (i < a && scanf("%lf", &array[i]))
    {
        i++;
    }
    return i;
}

void show_array(double *array, int size)
{
    printf("Your array: ");
    for(int i = 0; i < size; i++)
    {
        printf("%.2lf ", array[i]);
    }
    printf("\n");
}

void reverse_array(double *array, int size)
{
    for (int i = 1, j = size - 2; i < j; i++, j--)
    {
        double temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

int main(){

    printf("Enter your numbers (q to quit): ");
    double new_array[MAX_SIZE];
    int real_size = fill_array(new_array, MAX_SIZE);
    reverse_array(new_array, real_size);
    show_array(new_array, real_size);

    return 0;
}