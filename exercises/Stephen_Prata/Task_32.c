/*Написать функцию, которая обычно принимает один аргумент - адрес строки и выводит эту строку один раз. Однако, если задан второй аргумент типа int,
не равный нулю, то эта функция выводит строку столько раз, сколько было осуществлено вызовов этой функции к моменту ее данного вызова.
Количество выводимых строк не равно значению второго аргумента, оно равно числу вызовов функции к моменту последнего вызова. 
Написать простую программу для демонстрации этой функции. */

#include <stdio.h>

void print_string(char *string, int a)
{
    static int repeat = 0;
    repeat++;

    if (a == 0)
    {
        printf("%s\n", string);
    }
    else
    {
        for( int i = 0; i < repeat; i++)
        {
            printf("%s\n", string);
        }
    }
}

int main() {
    printf("=== Normal mode ===\n");
    print_string("First call", 0);
    print_string("Second call", 0);
    print_string("Third call", 0);
    
    printf("\n=== Special mode ===\n");
    print_string("Special!", 1);
    print_string("Again!", 1);
    
    printf("\n=== Mixed mode ===\n");
    print_string("Normal", 0);
    print_string("Special", 42);
    
    return 0;
}