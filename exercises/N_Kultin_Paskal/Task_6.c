/*написать программу которая проверяет не составляет ли последовательность чисел, введенная с клавиатуры, возрастающую или убывающую последовательность. */

#include <stdio.h>

int main(){
    
    int n = 0;
    printf("How many number would you to enter?\n");
    scanf("%d", &n);

    int arr[n];
    printf("Enter numbers: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int strictly_inc = 1, non_dec = 1;
    int strictly_dec = 1, non_inc = 1;
    
    for (int i = 0; i < n-1; i++) {
        if (arr[i] >= arr[i+1]) strictly_inc = 0;
        if (arr[i] > arr[i+1]) non_dec = 0;
        if (arr[i] <= arr[i+1]) strictly_dec = 0;
        if (arr[i] < arr[i+1]) non_inc = 0;
    }

    if (strictly_inc)
    {
        printf("The sequence is strictly increasing\n");
    }
    else if (non_dec)
    {
        printf("The sequence is non-decreasing\n");
    }
    else if (strictly_dec)
    {
        printf("The sequence is strictly decreasing\n");
    }
    else
    {
        printf("The sequence is non-increasing\n");
    }

    return 0;
}