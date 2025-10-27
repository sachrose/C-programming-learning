/*Дан каркас программы. Дополнить его функциями: 
getinfo() - принимает 2 аргумента: указатель на массив структур student и значение int, представляющее количество элементов массива.
Функция запрашивает и сохраняет данные о студентах. Ввод прекращается после наполнения массива или при вводе пустой строки в поле Имя студента.
Возвращает действительное количество элементов

display1() - принимает в качестве аргумента структуру student и отображает её содержимое

display2() - принимает адрес структуры и отображает содержимое

display3() - принимает указатель на первый элемент массива структур и количество элементов, отображает содержимое всех структур массива */


#include <stdio.h>

#define MAX_SIZE 50
#define SLEN 20

struct student
{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

int getinfo(struct student *group, int size)
{
    int i = 0;
    while (i < size)
    {
        printf("Enter fullname (Enter to quit): ");
        
        char first_char = getchar();
        if (first_char == '\n')
        {
            break; 
        } 
        else 
        {
            ungetc(first_char, stdin);
            scanf("%19s", group[i].fullname);
            printf("Enter hobby: ");
            scanf("%19s", group[i].hobby);
            printf("Enter ooplevel: ");
            scanf("%d", &group[i].ooplevel);
            i++;
        }
        while(getchar() != '\n');
    }
    return i;    
}

void display1(struct student user)
{
    printf("Student's information: %s, hobby is %s, ooplevel %d\n", user.fullname, user.hobby, user.ooplevel);
}

void display2(struct student *user)
{
    printf("Student's information: %s, hobby is %s, ooplevel %d\n", (*user).fullname, (*user).hobby, (*user).ooplevel);
}

void display3(struct student *group, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("Student's information: %s, hobby is %s, ooplevel %d\n", group[i].fullname, group[i].hobby, group[i].ooplevel);
    }
}


int main(){

    struct student class[MAX_SIZE];
    int entered = getinfo(class, MAX_SIZE);

    for(int i = 0; i < entered; i++)
    {
        display1(class[i]);
        display2(&class[i]);
    }
    display3(class, entered);
    
    printf("Done!\n");

    return 0;
}