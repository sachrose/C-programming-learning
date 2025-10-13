/*Написать программу, которая использует 3 определяемых пользователем функции (включая main()),
и генерирует следующий вывод:
Three blind mice
Three blind mice
See how they run
See how they run
Одна функция, вызванная 2 раза дает первые 2 строки, другая функция, вызванная 2 раза дает 2 следующие строки */

#include <stdio.h>

void print_str1(int num){
    for(int i=0; i < num; i++){
        printf("Three blind mice\n");
    }    
}

void print_str2(int num){
    for(int i=0; i < num; i++){
        printf("See how they run\n");
    }    
}

int main(){
    
    print_str1(2);
    print_str2(2);
    return 0;
}