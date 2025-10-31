/*Структура CandyBar содержит 3 члена. Первый хранит название коробки конфет, второй - вес (с дробной частью) , третий - количество калорий (целое значение).
Написать программу, использующую функцию, которая принимает в качестве аргументов ссылку на CandyBar, указатель на char, значение double  и int.
Функция использует 3 последних аргумента для установки соответствующих ленов структуры.
Три последних аргумента должны использовать значение по умолчанию: "The millennium Munch", 2.85 и 350.
Кроме того, программа должна использовать функцию, которая принимает в качестве аргумента ссылку на CandyBar и отображает содержимое этой структуры.
Где необходимо, используйте const.

Оно как-то рабоатет. Но эти значения по умолчанию - это ... кхм */

#include <stdio.h>
#include <string.h>

#define MAX_COUNT 20

struct CandyBar
{
    char name[30];
    float weight;
    int calories;
};

void init_candybar(struct CandyBar *cb, const char *name, float w, int c)
{
    strncpy(cb->name, name, 29);
    cb->name[29] = '\0';
    cb->weight = w;
    cb->calories = c;
}

void display_candybar(const struct CandyBar *cb)
{
    printf("%s, %.2f g. %d calories\n", cb->name, cb->weight, cb->calories);
}

int main(){

    int count = 0;  
    struct CandyBar candy[MAX_COUNT];
    char choice = 'y';

     while (count < MAX_COUNT && (choice == 'y' || choice == 'Y'))
     {
        printf("\nCandyBar #%d:\n", count + 1);
        
        char name[30];
        double weight;
        int calories;
        
        printf("Name: ");
        fgets(name, 30, stdin);
        name[strcspn(name, "\n")] = '\0';

        if (strlen(name) == 0)
        {        
        strcpy(name, "The millennium Munch");
        }        
        
        printf("Weight: ");
        if (scanf("%lf", &weight) != 1) weight = 2.85;
        while(getchar() != '\n');

        printf("Calories: ");
        if (scanf("%d", &calories) != 1) calories = 350;
        while(getchar() != '\n');

        init_candybar(&candy[count], name, weight, calories);
        count++;
        
        if (count >= MAX_COUNT)
        {
            printf("Maximum capacity reached!\n");
            break;
        }
        else
        {
        printf("Add another? You can enter %d more (y/n): ", MAX_COUNT - count);
        scanf(" %c", &choice);
        while(getchar() != '\n');
        }
    }

    printf("\n=== All CandyBars ===\n");
    for(int i = 0; i < count; i++)
    {
        display_candybar(&candy[i]);
    }
    
    return 0;
}




/*
Name: Alpine Chocolate
Weight: 2.50
Calories: 280

Name: Cherry Explosion
Weight: 1.20  
Calories: 180

Name: Rainbow Gummies
Weight: 3.75
Calories: 320

Name: Royal Truffle
Weight: 0.85
Calories: 95

Name: Honey Nougat
Weight: 4.20
Calories: 450
*/
