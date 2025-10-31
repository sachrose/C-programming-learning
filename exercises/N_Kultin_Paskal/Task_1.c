/*Написать программу, которая выводит двоичное представление заданного числа от 0 до 255.  */

#include <stdio.h>

int main(){
   
    printf("Enter a number from 0 to 255: ");
    int num = 0;
    if(num < 0 || num > 255)
    {
        printf("Wrong number!");
        return 1;
    }  
   
    #if 0
    while(scanf("%d", &num))
    {
        printf("%d in binary looks like ", num);
        int bit[8];
        for (int i = 0; i < 8; i++)
        {
            bit[i] = num % 2;
            num = num / 2;
        }     
        for (int i = 7; i >= 0; i--)
        {
            printf("%d", bit[i]);
        }
        printf("\nNext number: ");
    }
    
    #else
    while(scanf("%d", &num))
    {
        printf("%d in binary looks like ", num);
        for (int i = 7; i >= 0; i--)
        {
            printf("%d", num >> i & 1);
            if (i == 4)
            {
                printf(" ");
            }
        }
        printf("\nNext number: ");
    }

    #endif

    return 0;
}
