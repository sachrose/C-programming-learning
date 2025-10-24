/*Многие лотереи в США организованы подобно той, что была смоделирована в листинге 7.4. Во всех их вариациях вы должны выбрать несколько чисел из одного набора,
называемого полем номеров. (выбрать 5 чисел из поля 1-47). Вы также указываете один номер (меганомер) из второго диапазона, такого как 1-27.
Чтобы выиграть главный приз, вы должны правильно угадать все номера. Шанс выиграть вычисляется как вероятность угадывания всех номеров в поле,
умноженная на вероятность угадывания меганомера. Например, вероятность выигрыша в описанном здесь примере вычисляется как вероятность угадывания 5 номеров из 47,
умноженная на вероятность угадывания 1 номера из 27. Модифицируйте листинг 7.4 для вычисления вероятности выигрыша в такой лотерее */

#include <stdio.h>

long double probability(unsigned numbers, unsigned picks)
{
    long double result = 1.0;
    long double n;
    unsigned p;
    for(n = numbers, p = picks; p > 0; n--, p--)
    {
        result = result * n / p;
    }
    return result;
}

int main(){

    unsigned total, choices, mega;
    printf("Enter the total number of choices on the game card, the number of picks allowed and a meganumber:\n");

    while(scanf("%u %u %u", &total, &choices, &mega) && choices <= total)
    {
        printf("You have one chance in ");
        printf("%.2Lf", probability(total, choices) * probability(mega, 1));
        printf(" of winning\n");
        printf("Next two numbers (q to quit)\n");
    }

    return 0;
}