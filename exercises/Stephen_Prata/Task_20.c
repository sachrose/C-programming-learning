/*Написать программу, которая отслеживает пожертвования в Общество Защиты Влиятельных Лиц.
Она должна запрашивать у пользователя количество меценатов, а затем приглашать вводить их имена и суммы пожертвований от каждого.
Информация должна сохраняться в динамически выделяемом массиве структур.
Каждая структура должна иметь два поля: char и float для хранения имени и суммы пожертвования соответственно.
После чтения всех данных программа должна отображать имена и суммы пожертвования тех, кто не пожалел более 10000 и более.
Этот список должен быть озаглавлен меткой "Grand Patrons". После этого программа должна выдать список остальных жертвователей с заголовком "Patrons".
Если в одной из двух категорий не окажется никого, программа должна отобразить "none". */

#include <stdio.h>
#include <stdlib.h>

struct donaters{
    char name[20];
    float sum;
};

int main(){

    #if 1
    FILE *file = fopen("Task_20.txt", "r");
    if (file == NULL)
    {
        printf("Cannot open file!\n");
        return 1;
    }
    
    
    int count;
    fscanf(file, "%d", &count);

    struct donaters *list = (struct donaters*)malloc(count * sizeof(struct donaters));
    if (list == NULL)
    {
        printf("Memory allocation failed!\n");
        fclose(file);
        return 1;
    }

    for(int i = 0; i < count; i++)
    {
        fscanf(file, "%s", list[i].name);
        fscanf(file, "%f", &list[i].sum);
    };

    fclose(file);
    
    #else
    int count;
    printf("Enter the number of donaters: ");
    scanf(" %d", &count);

    struct donaters *list = (struct donaters*)malloc(count * sizeof(struct donaters));
    if (list == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the information with format: name donate\n");
    for(int i = 0; i < count; i++)
    {
        scanf("%s %f", list[i].name, &list[i].sum);
    };
    
    #endif
    printf("===[Grand Patrons]===\n");
    int grand_found = 0;
    for(int i = 0; i < count; i++)
    {
        if (list[i].sum >= 10000)
            {
                printf("%s %.2f\n", list[i].name, list[i].sum);
                grand_found = 1;
            }
    }
        
    if(!grand_found)
        {
            printf("none\n");
        }  

    printf("===[Patrons]===\n");
    int ordinary_found = 0;
    for(int i = 0; i < count; i++)
    {
        if (list[i].sum < 10000)
            {
                printf("%s %.2f\n", list[i].name, list[i].sum);
                ordinary_found = 1;
            }
    }
        
    if(!ordinary_found)
        {
            printf("none\n");
        }  

    free(list);
    
    return 0;
}