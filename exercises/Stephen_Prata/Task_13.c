/*Написать программу, которая использует массив char и цикл для чтения по одному слову за раз до тех пор,
пока не будет написано "done". Затем программа должна вывести эти слова и сообщить их количество, исключая "done". */

#include <stdio.h>
#include <string.h>

int main(){

char word[100];
int count = 0;

printf("Enter your word (done - to stop the program): \n");

while (scanf("%99s", word) == 1)
{
    if(strcmp(word, "done") == 0)
    {
        break;
    }

    count++;
}

printf("You have entered %d words\n", count);

return 0;

}