/*Когда вы вступите в благотворительный орден программистов (БОП) к Вам могут обращаться по настоящему имени, по должности или по нику.
Необходимо написать программу, которая модет выводить списки членов БОП, сортируя по имени, должности, нику или по предпочтению самого члена.
В основе должна быть структура:
struct bop{
char name[strsize];
char title[strsize]:
char bopname[strsize]:
int preference; //0 = name, 1 = title, 2 - bopname
};
В этой программе необходимо создать массив таких структур и инициализировать их значениями. Пусть программа запустит цикл,
который даст возможность пользователю выбрать, в каком порядке вывести список членов, меню. 
a. display by name            b. display by title
c. display by bopname         d. display by preference
q. quit

"display by preference" отображает член структуры, который соответствует значению preference.
Например, если preference = 1, то выбор пункта d должен вызвать отображение title члена БОП. Пример запуска:
Benevolent Order of Programmers Report
a. display by name            b. display by title
c. display by bopname      d. display by preference
q. quit
Enter your choice: a
Wimp Macho
Raki Rhodes
Celia Laiter
Hoppy Hipman
Pat Hand
Next choice: d
Wimp Macho
Junior programmer
MIPS
Analyst Trainee
LOOPY
Next choice: q
Bye!*/

#include <stdio.h>

#define STRSIZE 40

struct bop {
    char name[STRSIZE];
    char title[STRSIZE];
    char bopname[STRSIZE];
    int preference;  // 0=name, 1=title, 2=bopname
};

int main(){
      
    char choice;
    
    struct bop members[5] = {
        {"Wimp Macho", "CEO", "BOSS", 2},
        {"Raki Rhodes", "Junior Programmer", "X-RAY", 2},
        {"Celia Laiter", "Senior Developer", "MIPS", 0},
        {"Hoppy Hipman", "Analyst Trainee", "HOPPER", 1},
        {"Pat Hand", "System Admin", "LOPPY", 0}
    };

    printf("Benevolent Order of Programmers Report\n"
        "a. display by name\t b. display by title\nc. display by bopname\t d. display by preference\nq. quit\n"
        "Enter your choice: ");

    do
    {
        scanf(" %c", &choice);
        switch (choice)
        {
        case 'a':
            for(int i = 0; i < 5; i++){
                printf("%s\n", members[i].name);
            };
            printf("Next choice: ");
            continue;
        
        case 'b':
            for(int i = 0; i < 5; i++){
                printf("%s\n", members[i].title);
            };
            printf("Next choice: ");
            continue;

        case 'c':
            for(int i = 0; i < 5; i++){
                printf("%s\n", members[i].bopname);
            };
            printf("Next choice: ");
            continue;

        case 'd':
            for(int i = 0; i < 5; i++){
                switch (members[i].preference)
                {
                case 1:
                    printf("%s\n", members[i].title);
                    break;
                
                case 2:
                    printf("%s\n", members[i].bopname);
                    break;

                default:
                    printf("%s\n", members[i].name);
                    break;
                }
            }
            printf("Next choice: ");
            continue;

        case 'q':
            printf("Bye!\n");
            break;

        default:
            printf("Please enter a a, b, c, d or q: ");
            continue;
        }
        break;
    } while (1);    
    
    return 0;
}




