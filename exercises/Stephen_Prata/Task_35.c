/*Написать шаблонную функцию max5(), которая принимает в качестве аргумента массив из пяти элементов типа Т и возвращает наибольший элемент в массиве.
Протестировать с int, double, char*/

#if 0
#include <stdio.h>
#define ARR_SIZE 5

int max(int *arr)
{
    int temp = arr[0];
    for(int i = 1; i < ARR_SIZE; i++)
    {
        if (arr[i] > temp)
        {
            temp = arr[i];
        }
    }
    return temp;
}

int main(){

    printf("Enter %d numbers: ", ARR_SIZE);
    int array[ARR_SIZE];
    for(int i = 0; i < ARR_SIZE; i++)
    {
        scanf("%d", &array[i]);
    }
    while (getchar() != '\n');

    printf("Max number is %d\n", max(array));

    return 0;
}

#else

#include <stdio.h>
#include <string.h>

#define ARR_SIZE 5

#define MAX(arr, type, size) \
({ \
    typeof(type) temp = arr[0]; \
    for(int i = 1; i < size; i++) \
    { \
        if (arr[i] > temp) temp = arr[i]; \
    } \
    temp; \
})

char* max_string(char* arr[], int size)
{
    char* temp = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (strlen(arr[i]) > strlen(temp)) 
        {
            temp = arr[i];
        }
    }
    return temp;
}

int main() {

    int int_arr[ARR_SIZE];
    printf("Enter %d numbers: ", ARR_SIZE);
    for(int i = 0; i < ARR_SIZE; i++)
    {
        scanf("%d", &int_arr[i]);
    }
    while (getchar() != '\n');
    printf("Max number is: %d\n", MAX(int_arr, int, ARR_SIZE));
    

    double double_arr[ARR_SIZE];
    printf("Enter another %d numbers: ", ARR_SIZE);
    for(int i = 0; i < ARR_SIZE; i++)
    {
        scanf("%lf", &double_arr[i]);
    }
    while (getchar() != '\n');
    printf("Max number is: %.2lf\n", MAX(double_arr, double, ARR_SIZE));


    char strings[ARR_SIZE][50];
    printf("Enter a %d strings: ", ARR_SIZE);
    for (int i = 0; i < ARR_SIZE; i++)
    {
        scanf("%49s", strings[i]);     
    }
    while (getchar() != '\n');

     char *string_ptrs[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; i++)
    {
        string_ptrs[i] = strings[i];
    }
    printf("String %s is the longest\n", max_string(string_ptrs, ARR_SIZE));

    return 0;
}

#endif