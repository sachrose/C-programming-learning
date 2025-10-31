/*Написать программу, которая использует операцию new с размещением, чтобы поместить массив из двух таких структур в буфер.
Затем программа присваивает значения членам структуры (strcpy() для char) и отображает её содержимое с помощью цикла.
Вариант 1 предусматривает применение в качестве буфера памяти статического массива. Вариант 2 состоит в использовании обычной операции new для выделения памяти под буфер. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char uint8;

struct chaff
{
    char dross[20];
    int slag;
};

int main(){

    #if 0
    uint8 *static_buf [2 * sizeof(struct chaff)];
    struct chaff *arr = (struct chaff*)static_buf;

    #else
    uint8 *dinamic_buf = malloc(2 * sizeof(struct chaff));
    if (dinamic_buf == NULL)
    {
        printf("Memory allocation error!\n");
        return 1;
    }
    struct chaff *arr = (struct chaff*)dinamic_buf;
    #endif

    for(int i = 0; i < 2; i++)
    {
        printf("Chaff #%d\nEnter a dross: \n", i+1);
        char input[20];
        fgets(input, 20, stdin);
        input[strcspn(input, "\n")] = '\0';
        strcpy(arr[i].dross, input);

        printf("Enter a slag: ");
        scanf("%d", &arr[i].slag);
        while(getchar() != '\n');        
    }

    for (int i = 0; i < 2; i++)
    {
        printf("Chaff #%d is %s, slag %d. Adress: %p\n", i+1, arr[i].dross, arr[i].slag, &arr[i]);
    }
    
    #if 1
    free(dinamic_buf);
    #endif    

    return 0;
}

