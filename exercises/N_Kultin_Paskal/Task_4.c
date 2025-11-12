/*Написать программу проверки умения складывать и вычитать числа в пределах 100. Программа должна вывести 10 примеров, причем в каждом примере
уменьшаемое должно быть больше или равно вычитаемому. Т.е примеры с отрицательным результатом не допускаются. Затем программа  должна выставить оценку:
10 правильных ответов - "отлично", 9 и 8 - "хорошо", 7 и 6 - "удовлетворительно", 6 и менее - "плохо".
В примере выполнения программы после ошибки следует сообщение "Вы ошиблись: *пример и правильный ответ*. Затем следующий пример.
В конце количество правильных ответов и оценка. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned char uint8;

uint8 get_answer() {
    uint8 number = 0;
    while (scanf("%hhd", &number) != 1)
    {
        printf("Error! Try again.\n");
        while(getchar() != '\n');
    }
    while(getchar() != '\n');
    return number;
}

int main(){

    srand(time(NULL));
    uint8 correct_answers = 0;

    for (int i = 0; i < 10 ; i++)
    {
        uint8 operation = rand() % 2;
        uint8 a, b, correct;
        char operation_ch;

        if (operation == 0)
        {
            a = rand() % 101;
            b = rand() % (101 - a);
            correct = a + b;
            operation_ch = '+';
        }
        else
        {
            a = rand() % 101;
            b = rand() % (a + 1);
            correct = a - b;
            operation_ch = '-';
        }
        
        printf("%d %c %d = ", a, operation_ch, b);
        uint8 answer = get_answer();
        
        if (correct != answer)
        {
            printf("Wrong answer! %d %c %d = %d\n", a, operation_ch, b, correct);
        }
        else
        {
            correct_answers++;
        }   
    }

    printf("Correct answers: %d\nThe grade is: ", correct_answers);
    switch (correct_answers)
    {
    case 10:
        printf("Excellent!\n");
        break;
    case 9:
    case 8:
        printf("Good\n");
        break;
    case 7:
    case 6:
        printf("Satisfactory\n");
        break;
    
    default:
        printf("Poor\n");
        break;
    }
    
    return 0;
}
