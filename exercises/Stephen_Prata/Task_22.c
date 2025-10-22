/*Написать программу, которая открывает файл, читает его символ за символом до самого конца и сообщает количество символов в файле. */

#include <stdio.h>

int main(){

    FILE *file = fopen("Task_22.txt", "r");
    if (file == NULL)
    {
        printf("Cannot open file!\n");
        return 1;
    }
    
    int ch = 0;
    int count = 0;

    while ((ch = fgetc(file)) != EOF)
    {
        count++;
        printf("Char %d: '%c' (ASCII %d)\n", count, ch, ch);
    }

    fclose(file);
    printf("The file contains %d symbols\n", count);

    return 0;
}