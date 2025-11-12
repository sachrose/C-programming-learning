/**/

#include <stdio.h>
#include <stdlib.h>

#define MAX_ARR_SIZE 100

void display_menu();
void input_arr(int arr[], int *size, int max_size);
void print_arr(int arr[], int size);
int has_duplicates(int arr[], int size);
int linear_search(int arr[], int size);
void find_min_max(int arr[], int size);
void arr_sum_avrg(int arr[], int size);
void arr_reverse(int arr[], int size);
void arr_merge(int *arr1, int *size);
void sort(int arr[], int size);
void bubble_sort_asc(int arr[], int size);
void bubble_sort_desc(int arr[], int size);
void selection_sort_asc(int arr[], int size);
void selection_sort_desc(int arr[], int size);


int main(){

    int choice;
    int arr[MAX_ARR_SIZE];
    int size = 0;

    input_arr(arr, &size, MAX_ARR_SIZE);

    do
    {
        display_menu();
        scanf("%d", &choice);
        while(getchar() != '\n');

        switch (choice)
        {
        case 1:
            int result_dup = has_duplicates(arr, size);
            if (result_dup != 0)
            {
                printf("Duplicates found!");
            }
            else
            {
                printf("Not found!");
            }              
            break;
        case 2:
            int result_ls = linear_search(arr, size);
            if (result_ls != -1)
            {
                printf("Search completed. Element index %d", result_ls);
            }
            else
            {
                printf("Not found!");
            }          
            break;
        case 3:
            find_min_max(arr, size);
            break;
        case 4:
            arr_sum_avrg(arr, size);
            break;
        case 5:
            arr_reverse(arr, size);
            break;
        case 6:
            sort(arr, size);
            break;
        case 7:
            arr_merge(arr, &size);
            break;
        case 8:
            printf("Bye!\n");
            break;
        default:
            printf("Bad entry. Try again.\n");
        }
    } while (choice != 8);
    
    return 0;
}


void display_menu() {
    printf("\n=== Array Laboratory #1 ===\n");
    printf("1. Duplicate Search\n");
    printf("2. Finding the value\n");
    printf("3. Minimum/Maximum\n");
    printf("4. Statistics (sum/average)\n");
    printf("5. Flipping the array\n");
    printf("6. Sorting (bubble/selection, up/down)\n");
    printf("7. Combining arrays\n");
    printf("8. Exit\n");
    printf("Select an operation: ");
};

void input_arr(int arr[], int *size, int max_size) {
    int valid_input = 0;
    while (!valid_input) {
        printf("Enter array size: ");
        if (scanf("%d", size) != 1)
        {
            printf("Invalid input. Numbers only.\n");
            while(getchar() != '\n');
            continue;
        }
        while(getchar() != '\n');
        
        if (*size >= 1 && *size <= max_size) {
            valid_input = 1;
        } else {
            printf("Size must be 1-100. Try again.\n");
        }
    }
    
    printf("Enter %d numbers: ", *size);
    for (int i = 0; i < *size; i++) {
        while (scanf("%d", &arr[i]) != 1) {
            printf("Invalid number. Enter again: ");
            while(getchar() != '\n');
        }
    }
    while(getchar() != '\n');
}

void print_arr(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");    
};

int has_duplicates(int arr[], int size){
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                return 1;
            }
        }
    }
    return 0;
};

int linear_search(int arr[], int size){
    int target;
    printf("Enter the target (digit): ");
    scanf("%d", &target);
    while(getchar() != '\n');
    for (int i = 0; i < size; i++)
    {
        if (target == arr[i])
        {
            return i;
        }
    }
    return -1;
};

void find_min_max(int arr[], int size){
    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[0] > arr[i])
        {
            min = arr[i];
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (arr[0] < arr[i])
        {
            max = arr[i];
        }
    }
    printf("Min: %d, Max: %d", min, max);    
};

void arr_sum_avrg(int arr[], int size){
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    double avrg = sum / size;
    printf("The sum of the elements is %d, average: %.1lf", sum, avrg);
};

void arr_reverse(int arr[], int size){
    for (int i = 0, j = size - 1; i < j; i++, j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    print_arr(arr, size);    
};

void sort(int arr[], int size){
    printf("Before sorting: ");
    print_arr(arr, size);
    int choice = 0;
    do
    {
        printf("Choose one:\n1. Bubble sort ASC\t\t2. Bubble sort DESC\n3. Selection sort ASC\t\t4. Selection sort DESC\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            bubble_sort_asc(arr, size);
            break;
        case 2:
            bubble_sort_desc(arr, size);
            break;
        case 3:
            selection_sort_asc(arr, size);
            break;
        case 4:
            selection_sort_desc(arr, size);
            break;
        default:
            printf("Bad entry. Try again.\n\n");
        }
    } while (choice != 5);
}; 

void bubble_sort_asc(int arr[], int size) {
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            { 
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Ascending: ");
    print_arr(arr, size);
};

void bubble_sort_desc(int arr[], int size) {
    for (int i = 0; i < size-1; i++)    
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if (arr[j] < arr[j+1])
            { 
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Descending: ");
    print_arr(arr, size);
};    

void selection_sort_asc(int arr[], int size) {
    for (int i = 0; i < size - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr [i] = arr[min_idx];
        arr[min_idx] = temp;
    }    
    printf("Ascending: ");
    print_arr(arr, size);
};

void selection_sort_desc(int arr[], int size){
    for (int i = 0; i < size - 1; i++)
    {
        int max_idx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] > arr[max_idx])
            {
                max_idx = j;
            }
        }
        int temp = arr[i];
        arr [i] = arr[max_idx];
        arr[max_idx] = temp;
    }    
    printf("Descending: ");
    print_arr(arr, size);
};

void arr_merge(int *arr1, int *size){   
    int available_space = MAX_ARR_SIZE - *size;
    if (available_space <= 0)
    {
        printf("No space for second array!\n");
        return;
    }

    int size2;
    int arr2[available_space];
    printf("Array #2 (max %d elements): ", available_space);
    input_arr(arr2, &size2, available_space);

    if (size2 > available_space)
    {
        size2 = available_space;
    }

    for (int i = 0; i < size2; i++)
    {
        arr1[*size + i] = arr2[i];
    }
    *size += size2;
    print_arr(arr1, *size);    
};

