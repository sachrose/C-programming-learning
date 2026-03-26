/* Дан список. Определите, является ли он монотонно возрастающим (то есть верно ли, что каждый элемент этого списка строго больше предыдущего).
Выведите YES, если массив монотонно возрастает и NO в противном случае.*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 5

void create_list(int* list);
void is_growing(int* list);

int main()
{
    srand(time(NULL));
    int* list = malloc(sizeof(int) * SIZE);

    create_list(list);
    is_growing(list);

    free(list);
    return 0;
}

void create_list(int* list)
{
    for (int i = 0; i < SIZE; i++)
    {
        list[i] = rand() % 80;
        printf("%d ", list[i]);
    }
    printf("\n");
}

void is_growing(int* list)
{
    bool is_ok = true;
    for (int i = 0, j = 1; i < SIZE - 1, j < SIZE; i++, j++)
    {
        if (list[i] > list[j])
        {
            is_ok = false;
            break;
        }
    }

    if (is_ok)
    {
        printf("YES!\n");
    }
    else
    {
        printf("NO\n");
    }
}