/*Написать программу, которая читает клавиатурный ввод до символа @ и повторяет его, за исключением десятичных цифр,
преобразуя каждую букву верхнего регистра в букву нижнего регистра и наоборот. */

#include <stdio.h>
#include <ctype.h>

int main(){

    char ch;
    printf("Enter something (or @ to stop): ");

    while((ch = getchar()) != '@'){
        if (isdigit(ch)){
            continue;
        }

        else if(islower(ch)){
            printf("%c", toupper(ch));
        }

        else if(isupper(ch)){
            printf("%c", tolower(ch));
        }

        else{
            printf("%c", ch);
        }
    }
    printf("\n");

    return 0;
}