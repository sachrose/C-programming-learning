/*Написать программу, которая запрашивает у пользователя 2 числа (предполагается что первое будет меньшим).
Затем программа должна вычислить сумму всех целых чисел, лежащих между этими двумя целыми. 
Например, если пользователь ввел 2 и 9, программа должна сообщить, что сумма всех целых чисел от 2 до 9 равна 44.*/

#include <stdio.h>

int main(){

    int num1, num2, sum = 0;

    printf("Enter two numbers, the smaller one first: ");
    scanf("%d %d", &num1, &num2);

    if(num1 > num2){
        printf("First number must be smaller! Swapping...\n");
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    for(int i = num1; i <= num2; i++){
        sum += i;
    }

    printf("The sum of the numbers between %d and %d is %d\n", num1, num2, sum);

    return 0;
}