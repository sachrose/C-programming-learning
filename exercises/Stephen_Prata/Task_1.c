#include <stdio.h>

int main() {
    char name[20];
    char last_name[20];
    int age;

    printf("What is your name? ");
    scanf("%19s", name);  // Простой %s

    printf("What is your last name? ");
    scanf("%19s", last_name);

    printf("What is your age? ");
    scanf("%d", &age);

    printf("Name: %s, %s\nAge: %d\n", last_name, name, age);
    return 0;
}