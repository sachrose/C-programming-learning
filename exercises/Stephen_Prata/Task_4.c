/*Написать программу, которая запрашивает рост в дюймах и преобразует их в футы и дюймы.
Программа должна использовать символ подчеркивания для обозначения позиции, где будет ввод.
Для представления коэффициента преобразования используйте символьную константу const. */

#include <stdio.h>

const int INCHES_PER_FEET = 12;

int main(){
    
    float inches;
    int feet;
    float remainder;

    printf("Enter your height in inches: ____\b\b\b\b");
    scanf("%f", &inches);

    feet = inches / INCHES_PER_FEET;
    remainder = inches - feet * INCHES_PER_FEET;

    if (remainder == 0) {
        printf("Your height is %d feet.\n", feet);
    } else {
        printf("Your height is %d feet and %.1f inches.\n", feet, remainder);
    }

    return 0;
}