/*Написать программу, которая вводит с клавиатуры массив из 5 целых числе и выводит количество ненулевых элементов. Перед вводом числа должна выводиться подсказка:
а[1] -> 12
а[2] -> 0
а[3] -> -6
а[4] -> 43
а[5] -> 0
В массиве 3 ненулевых элемента.*/

#include <stdio.h>

int main(){

    int arr[5];
    int count = 0;

    printf("Enter your numbers:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("a[%d] -> ", i +1);
        scanf("%d", &arr[i]);
        if (arr[i] != 0)
        {
            count++;
        }
        
    }
        
    printf("The array contains %d non-zero elements \n", count);

    return 0;
}
