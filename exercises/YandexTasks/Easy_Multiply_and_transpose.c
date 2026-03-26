/*Школьники из объединения КРОШ (Клуб Решателей Олимпиад Школьников) готовятся к участию в треке ML.
Начать подготовку они решили с изучения линейной алгебры.
Выяснилось, что существует две интересные операции над матрицами — умножение и траспонирование.
Они составили много примеров и решают их на листике, однако им нужна помощь в проверке результатов.
Напишите программу, которая по заданным матрицам A A и  B B вычисляет:( A × B )^T ,

где A — матрица размером n × m, а B — матрица размером m × k.

В первой стоке вводятся 3 числа n , m , k ( 1 ≤ n , m , k ≤ 100 ).

Далее следуют n строк по m чисел в каждой — элементы матрицы A ( 0 ≤ A i , j ≤ 10 ).

Затем вводятся m строк по k чисел в каждой — элементы матрицы B  ( 0 ≤ B i , j ≤ 10 ).

Элементы строк разделены ровно одним пробелом, каждая строка может оканчиваться произвольным количеством пробелов.*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define INIT_TYPE_ZEROS 0
#define INIT_TYPE_RAND  1

void print_matrix(int **matrix, int rows, int cols);
int** generate_matrix(int rows, int cols, int init);
int** multiply_matrix(int **a_matrix, int **b_matrix, int n, int m, int k);
void transpose_matrix(int **matrix, int n, int k);
void delete_matrix(int **matrix, int rows);


int main()
{
    srand(time(NULL));
    int n, m, k;
    printf("Enter 3 numbers separated by spaces:\n");

    while (1)
    {
        if (scanf("%d %d %d", &n, &m, &k) == 3)
        {
            if ((1 <= n && n <= 100) && (1 <= m && m <= 100) && (1 <= k && k <= 100))
            {
                break;
            }
            else
            {
                printf("Numbers must be between 1 and 100. Try again: ");
                while (getchar() != '\n');
            }           
        }
        else
        {
            while (getchar() != '\n');
            printf("Invalid input. Enter 3 numbers: ");
        }
    }
       
    printf("The 1st matrix:\n");
    int **a_matrix = generate_matrix(n, m, INIT_TYPE_RAND);
    printf("The 2nd matrix:\n");
    int **b_matrix = generate_matrix(m, k, INIT_TYPE_RAND);
    printf("Multiply:\n");
    int **m_matrix = multiply_matrix(a_matrix, b_matrix, n, m, k);
    printf("Transpose:\n");
    transpose_matrix(m_matrix, n, k);

    delete_matrix(a_matrix, n);
    delete_matrix(b_matrix, m);
    delete_matrix(m_matrix, n);
    
    return 0;
}

void print_matrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }   
}

int** generate_matrix(int rows, int cols, int init)
{
    int **matrix = (int**)malloc(sizeof(int*)*rows);
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int*)malloc(sizeof(int)*cols);
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = (init == INIT_TYPE_ZEROS) ? 0 : rand() % 10;
        }
    }

    if (init != INIT_TYPE_ZEROS)
    {
      print_matrix(matrix, rows, cols);
    }

    return matrix;
}

int** multiply_matrix(int **a_matrix, int **b_matrix, int n, int m, int k)
{
    int **m_matrix = generate_matrix(n, k, INIT_TYPE_ZEROS);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            for (int t = 0; t < m; t++)
            {
                m_matrix[i][j] += a_matrix[i][t] * b_matrix[t][j];
            }
        }
    }
    print_matrix(m_matrix, n, k);

    return m_matrix;
}

void transpose_matrix(int **matrix, int n, int k)
{
    int **t_matrix = generate_matrix(k, n, INIT_TYPE_ZEROS);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            t_matrix[j][i] = matrix[i][j];
        }
    }
    print_matrix(t_matrix, k, n);
    delete_matrix(t_matrix, k);
}

void delete_matrix(int **matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}