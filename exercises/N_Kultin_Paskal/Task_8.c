/*Задача 1: Вычислить сумму элементов двумерного массива по строкам и столбцам, среднее арифметическое всех элементов
Задача 2: Вычислить сумму диагональных элементов квадратной матрицы
Задача 3: определить, является ли квадратная матрица магическим квадратом? (суммы элементов каждой строки, столбца, диагонали - равны)*/

#include <stdio.h>

#define MAX_SIZE 100

void menu();
void input_matrix(int matrix[][MAX_SIZE], int *rows, int *cols);
int get_row_sum(int matrix[][MAX_SIZE], int cols, int num);
int get_col_sum(int matrix[][MAX_SIZE], int rows, int num);
int get_diag1_sum(int matrix[][MAX_SIZE], int rows);
int get_diag2_sum(int matrix[][MAX_SIZE], int rows);
void sum_matrix(int matrix[][MAX_SIZE], int rows, int cols);
void sum_sq_matrix(int matrix[][MAX_SIZE], int rows, int cols);
void is_magic_matrix(int matrix[][MAX_SIZE], int rows, int cols);


int main(){
    int matrix[MAX_SIZE][MAX_SIZE];
    int rows = 0;
    int cols = 0;
    int choice = 0;

    input_matrix(matrix, &rows, &cols);

    do
    {
        menu();
        scanf("%d", &choice);
        while(getchar() != '\n');

        switch (choice)
        {
        case 1:
            input_matrix(matrix, &rows, &cols);
            break;
        case 2:
            sum_matrix(matrix, rows, cols);
            break;
        case 3:
            sum_sq_matrix(matrix, rows, cols);
            break;
        case 4:
            is_magic_matrix(matrix, rows, cols);
            break;
        case 5:
            printf("Bye!\n");
            break;
        default:
            printf("Bad entry! Try again.\n");
            break;
        }
    } while (choice != 5);

    return 0;
}

void menu(){
    printf("\n=== Array Laboratory #2 ===\n");
    printf("1. Add matrix\n");
    printf("2. Sum the elements and average all of them\n");
    printf("3. Sum the diagonal elements (square matrix)\n");
    printf("4. Is this matrix a magic square?\n");
    printf("5. Exit\n\n");
};

void input_matrix(int matrix[][MAX_SIZE], int *rows, int *cols){
    int valid_input = 0;
    while (!valid_input)
    {
        printf("Enter matrix size: rows and cols\n");
        if (scanf("%d %d", rows, cols) != 2)
        {
            printf("Invalid input. Numbers only.\n");
            while(getchar() != '\n');
            continue;
        }
        while(getchar() != '\n');

        if ((*rows >= 1 && *rows <= MAX_SIZE && *cols >= 1 && *cols <= MAX_SIZE))
        {
            valid_input = 1;
        }
        else
        {
            printf("Size must be 1-%d. Try again.\n", MAX_SIZE);
        }
    }

    for (int i = 0; i < *rows; i++)
    {
        printf("Enter %d elements of %d row: ", *cols, i+1);
        for (int j = 0; j < *cols; j++)
        {
            while (scanf("%d", &matrix[i][j]) != 1)
            {
            printf("Invalid number. Enter again: ");
            while(getchar() != '\n');
            }
        }
        while(getchar() != '\n');
    }
};

int get_row_sum(int matrix[][MAX_SIZE], int cols, int num){
    int sum = 0;
    for (int i = 0; i < cols; i++)
    {
        sum += matrix[num][i];
    }
    return sum;
};

int get_col_sum(int matrix[][MAX_SIZE], int rows, int num){
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        sum += matrix[i][num];
    }
    return sum;
};

int get_diag1_sum(int matrix[][MAX_SIZE], int rows){
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        sum += matrix[i][i];
    }
    return sum;
};

int get_diag2_sum(int matrix[][MAX_SIZE], int rows){
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        sum += matrix[i][rows-i-1];
    }
    return sum;
};

void sum_matrix(int matrix[][MAX_SIZE], int rows, int cols){
    int sum_all = 0;

    for (int i = 0; i < rows; i++)
    {
        int sum_rows = get_row_sum(matrix, rows, i);
        printf("Sum of row %d: %d\n", i + 1, sum_rows);
        sum_all += sum_rows;
    }

    for (int j = 0; j < cols; j++)
    {
        int sum_cols = get_col_sum(matrix, cols, j);
        printf("Sum of col %d: %d\n", j + 1, sum_cols);
    }

    float avrg = sum_all / ( rows * cols);
    printf("Average of all elements: %.1f\n", avrg);
};

void sum_sq_matrix(int matrix[][MAX_SIZE], int rows, int cols){
    if (rows != cols)
    {
        printf("Error: the number of columns and rows must be the same\n");
        return;
    }

    int sum1 = get_diag1_sum(matrix, rows);
    int sum2 = get_diag2_sum(matrix, rows);
    printf("Sum of diagonal-1 is %d, diagonal-2 is %d\n", sum1, sum2);
};

void is_magic_matrix(int matrix[][MAX_SIZE], int rows, int cols){
    if (rows != cols)
    {
        printf("Matrix must be square!\n");
        return;
    }
    
    int magic_sum = get_diag1_sum(matrix, rows);
    int diag2_sum = get_diag2_sum(matrix, rows);

    if (diag2_sum != magic_sum)
    {
        printf("Not magic square!\n");
        return;    
    }

    for (int i = 0; i < rows; i++)
    {
        int row_sum = get_row_sum(matrix, rows, i);
        int col_sum = get_col_sum(matrix, rows, i);
        if (row_sum != magic_sum || col_sum != magic_sum) 
        {
            printf("Not magic square: rows or cols has different sum: %d и %d\n", row_sum, col_sum);
            return;
        }
    }
    printf("This matrix is magic square! Magic sum: %d\n", magic_sum);
};