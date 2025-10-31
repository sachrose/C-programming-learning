/*Написать функцию, которая принимает ссылку на строку и преобразует её символы в символы верхнего регистра.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void up(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) 
    {
        str[i] = toupper(str[i]);
    }
}

int main(){

    char string[50];

    printf("Enter a string (q to quit): ");
    while(1)
    {
        fgets(string, 50, stdin);
        string[strcspn(string, "\n")] = '\0';
        
        if (strcmp(string, "q") == 0)
        {
            printf("Goodbye!\n");
            break;
        }
        
        up(string);
        printf("%s\n\n", string);
        printf("Next string: ");
        }

    return 0;
}