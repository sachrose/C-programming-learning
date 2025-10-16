/*Дафна инвестировала $100 под простые 10%. Ежегодно инвестиция должна приносить 10% от инвестированной суммы - т.е. $10 каждый год.
Прибыль = 0,1 * исходный баланс.
В то же время Клео инвестировала $100 под сложные 5%. Это значит, что прибыль составит 5% от текущего баланса, включая предыдующую накопленную прибыль:
прибыль = 0,05 * текущий баланс. 
Клео зарабатывает 5% от $100 в первый год, что дает ей $105. На следующий год она зарабатывает 5% от $105, что составляет $5.25 и т.д.
Напишите программу, которая вычислит сколько лет понадобится для того, чтобы сумма баланса Клео превысила сумму баланса Дафны,
с отображением значений обоих банасов за каждый год. */

#include <stdio.h>

int main(){

    float balance_1 = 100.00;
    float balance_2 = 100.00;
    int years = 0;

#if 0

    while(balance_2 <= balance_1){
        balance_1 += 10.00;
        balance_2 += 0.05 * balance_2;
        years++;
        printf("Daphne's balance is %.2f, Cleo's balance is %.2f after %d year\n", balance_1, balance_2, years);
    }

#else

    do{
        balance_1 += 10.00;
        balance_2 += 0.05 * balance_2;
        years++;
        printf("Daphne's balance is %.2f, Cleo's balance is %.2f after %d year\n", balance_1, balance_2, years);
    } while (balance_2 <= balance_1);

#endif

    printf("Cleo's balance exceeded Daphne's balance after %d years\n", years);

    return 0;
}