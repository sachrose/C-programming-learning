/*Реализовать алгоритм последовательного поиска*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int* create_array(int m)
{
    if (m <= 0)
    {
        printf("Invalid size!\n");
        return NULL;
    }
    
    int *arr = (int*)malloc(m * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation error!\n");
        return NULL;
    }
    for (int i = 0; i < m; i++)
        {
            arr[i] = rand() % 1000;
        }

    return arr;
}

int main()
{
    int m, n, i, j, N;
    printf("Enter the number of array elements and the number of elements to search for: \n");
    scanf("%d %d", &m, &n);
    while (getchar() != '\n');

    srand(time(NULL));
    int *arr = create_array(m);  
    
    if (arr == NULL)
    {
        return -1;
    }
    
    while (n > 0)
    {
        j = 0;
        N = rand() % 1000;
        for (i = 0; i < m; i++)
        {
            if (N == arr[i])
            {
                j++;
            }         
        }

        if (j > 0)
        {
            printf("The number %d occurs %d times\n", N, j);
        }
        
        n--;
    }

    free(arr);
    return 0;
}