/*Необходимо реализовать следующие функции (задачи)
1. создать файл Task_9_numbers.txt и записать 5 целых чисел, введенные пользователем. Каждое число должно быть на отдельной строке. 
2. дописать в файл еще 5 целых чисел, введенных пользователем. Убедиться, что в файле 10 чисел.
3. вывести содержимое файла на экран
4. вычислить среднее арифметческое чисел в файле */

#include <stdio.h>

void menu();
void create_file(FILE *file);
void append_file(FILE *file);
int count_num_in_file(FILE *file);
void read_file(FILE *file);
void avrg_num_in_file(FILE *file);


int main(){
    
    FILE *file = fopen("Task_9_numbers.txt", "w+");
    if (file == NULL) {
        printf("Error creating file!\n");
        return 1;
    }
    else
    {
        int choice = 0;
        do
        {
            menu();
            scanf("%d", &choice);
            while(getchar() != '\n');

            switch (choice)
            {
            case 1:
                create_file(file);
                break;
        
            case 2:
                append_file(file);
                break;

            case 3:
                read_file(file);
                break;

            case 4:
                avrg_num_in_file(file);
                break;

            case 5:
                printf("Bye!\n");
                break;
            default:
                printf("Bad entry! Try again.\n");
                break;
            }
        } while (choice != 5);
        fclose(file);
    }
    return 0; 
};

void menu(){
    printf("=== Working with files ===\n");
    printf("1. Create file\n");
    printf("2. Add numbers\n");
    printf("3. Display content\n");
    printf("4. Count average of numbers\n");
    printf("5. Exit\n");
};

void create_file(FILE *file){
    printf("Enter 5 numbers\n");
    for (int i = 0; i < 5; i++)
    {
        int num = 0;
        scanf("%d", &num);
        fprintf(file, "%d\n", num);
    }
        printf("File created successfully!\n");
};

void append_file(FILE *file){
    printf("Enter 5 numbers\n");
    for (int i = 0; i < 5; i++)
    {
        int num = 0;
        scanf("%d", &num);
        fprintf(file, "%d\n", num);
    }
        printf("Numbers appended successfully!\n");
        printf("The file contains %d numbers\n", count_num_in_file(file));
};

int count_num_in_file(FILE *file){
    rewind(file);
    int num = 0;
    int count = 0;
    while (fscanf(file, "%d", &num) == 1)
    {
        count++;
    }
    return count;
 };

void read_file(FILE *file){
    rewind(file);
    int num;
    printf("File contents:\n");
    while (fscanf(file, "%d", &num) == 1)
    {
        printf("%d\n", num);
    }
};

void avrg_num_in_file(FILE *file) {
    rewind(file);    
    int sum = 0;
    int count = 0;
    int num = 0;
    
    while (fscanf(file, "%d", &num) == 1)
    {
        sum += num;
        count++;
    }
    
    if (count > 0) {
        float average = (float) sum / count;
        printf("Average: %.2f (from %d numbers)\n", average, count);
    } else {
        printf("File is empty!\n");
    }
}