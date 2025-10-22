/*Написать программу, которая читает слова по одному за раз. пока не будет введена отдельная буква q.
После этого программа должна сообщить количество введенных слов, начинающихся с гласных, количество слов, начинающихся с согласных,
а также количество слов, не попадающих ни в одну категорию. Одним из возможных подходов может быть применение isalpha()
для различения слов, начинающихся с букв, и остальных, с последующим применение if или switch для идентификации тех слов,
прошедших проверку isalpha(), которые начинаются с гласных. Пример запуска может выглядеть так:
Enter words (q to quit):
The 12 awesome oxen ambled quietly across 15 meters of lawn. q
5 words beginning with vowels
4 words beginning with consonants
2 others*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(){

    char word[50];
    int vowels = 0; int consonants = 0; int others = 0;
    char vowels_str[] = "aeiouAEIOU";

    printf("Eneter your words (q to quit):\n");
    while(scanf(" %99s", word) == 1 && strcmp(word, "q"))
        {
            if (isalpha(word[0]))
            {
               if (strchr(vowels_str, word[0]))
               {
                vowels++;
               }
               else
               {
                consonants++;
               }           
            }
            else
            {
                others++;
            }          
        }

    printf("%d words beginning with vowels\n", vowels);
    printf("%d words beginning with consonants\n", consonants);
    printf("%d others\n", others);

    return 0;
}