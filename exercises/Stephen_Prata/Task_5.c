/*Написать короткую программу по расчету массы тела. Программа запрашивает рост в футах и дюймах, вес в фунтах.
Хранить эти данные следует в 3 переменных. Затем необходимо преобразовать рост в дюймы (футы умножить на 12),
а затем в метры (дюймы умножить на 0.0254). Вес преобразовать в килограммы (футы разделить на 2.2).
Затем рассчитать BMI (индекс массы тела): разделить массу в килограммах на квадрат роста в метрах.
Для коэффициентов использовать символические константы. */

#include <stdio.h>

const int INCHES_PER_FOOT = 12;
const float METERS_PER_INCH = 0.0254;
const float KG_PER_POUND = 2.2;

int main(){

    float height_feet, height_inches, weight_lb;

    printf("Enter height in feet: ");
    scanf("%f", &height_feet);

    printf("Enter height in inches: ");  
    scanf("%f", &height_inches);

    printf("Enter weight in pounds: ");
    scanf("%f", &weight_lb);

    float height_m, weight_kg, bmi;

    height_m = (height_feet * INCHES_PER_FOOT + height_inches) * METERS_PER_INCH;
    weight_kg = weight_lb / KG_PER_POUND;
    bmi = weight_kg / (height_m * height_m);

    printf("Your BMI is %.1f\n", bmi);

    return 0;
}