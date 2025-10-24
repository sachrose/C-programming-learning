/*Написать программу, которая многократно запрашивает у пользователя пару чисел до тех пор, пока хотя бы одно из этой пары не будет равно 0.
С каждой парой программа должна использовать функцию для вычисления среднего гармонического этих чисел.
Функция должна возвращать ответ в main() для отображения результата. Среднее гармоническое чисел - это инверсия среднего значения их инверсий.
среднее гармоническое = 2.0 * х * у / (х + у)*/

#include <stdio.h>

float harmonic_mean(float *x, float *y){
    float z = 2.0 * (*x) * (*y) / ((*x) + (*y));
    return z;
}


int main(){

    float a = 0; float b = 0;

    do
    {
        printf("Enter two numbers (0 to quit): ");
        scanf("%f %f", &a, &b);
        
        if (a == 0 || b == 0)
        {
            break;
        }
        
        if (a + b == 0) 
        {
            printf("Cannot calculate!\n");
            continue;;
        }
        printf("Harmonic mean is %.2f\n", harmonic_mean(&a, &b));
        
    } while (1);
    
    return 0;
}