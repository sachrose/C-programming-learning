/*Написать программу, которая приглашает пользователя вводить числа. После каждого ввода програма выводит сообщение, содержащее сумму введенных чисел.
Программа должна завершиться при вводе 0. */

#include <stdio.h>

int main(){

    int num = 0, sum = 0;

#if 0
    do{
        printf("Enter your number: ");
        scanf("%d", &num);
        sum += num;
        printf("The sum of the numbers is %d\n", sum);
    } while(num != 0);
#else
    while (1)
    {
        printf("Enter your number: ");
        scanf("%d", &num);
        sum += num;
        printf("The sum of the numbers is %d\n", sum);
        if (num == 0){
            break;
        }            
    }

#endif 
    return 0;
}