/*Напишите программу, которая находит в массиве элемент, самый близкий по величине к данному числу.

Формат ввода:
В первой строке задается одно натуральное число N, не превосходящее 1000 — размер массива.
Во второй строке содержатся N чисел — элементы массива, целые числа, не превосходящие по модулю 1000. (в моем случае числа будут сгенерированы случайно)
В третьей строке вводится одно целое число x, не превосходящее по модулю 1000.

Формат вывода:
Вывести значение элемента массива, ближайшее к x. Если таких чисел несколько, выведите любое из них.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int input(void);
int* create_array(int size);

int main()
{
    
    srand(time(NULL));
    int size = input();  
    int *array = create_array(size);
    int x = input();
    int closer_value = 1000;
    int closer_idx = 0;

    for (int i = 0; i < size; i++)
    {
        if (abs(x - array[i]) < closer_value)
        {
            closer_value = array[i];
            closer_idx = i;
        }
    }
    printf("Closer value is %d, index %d\n", closer_value, closer_idx);    

    free(array);
    return 0;
}

int input(void)
{
    int a;
    printf("Enter the number from -1000 to 1000: ");
    while (1)
    {
        if (scanf("%d", &a) == 1)
        {
            if (1 <= a && a <= 1000)
            {
                break;
            }
            else
            {
                printf("Wrong size/ Try again!");
                while(getchar() != '\n');
            }
        }
        else
        {
            printf("Invalid input. try again!");
            while(getchar() != '\n');
        }
    }

    return a;
}

int* create_array(int size)
{
    int min = -1000;
    int max = 1000;

    int *array = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        array[i] = min + rand() % (max - min + 1);
        printf("%d ", array[i]);
    }
    printf("\n");

    return array;
}