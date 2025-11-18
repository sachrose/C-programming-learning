/*Создаем телефонный справочник.
1. дописать данные в файл Task_10_phones.txt: фамилию, имя и номер телефона. Если файла не сществует - создать его.
Каждый элемент данных в файле должен находиться на отдельной строке. 
2. опционально: возможность добавить за один сеанс данные нескольких человек
3. поиск данных из файла. Программа запрашивает ключевое слово и предоставляет найденную информацию в одной строке: фамилия, имя, телефон.
Если результатов поиска несколько - предоставляет все. 

Данные для теста:
Ivanov Ivan 123-45-67
Petrova Maria 987-65-43  
Sidorov Alex 555-44-33
Kuznetsova Anna 111-22-33
Ivanova Olga 444-55-66
Smirnov Dmitry 777-88-99*/

#include <stdio.h>
#include <string.h>

typedef struct 
{
    char last_name[21];
    char name[21];
    char phone[11];
} Contact;

void menu();
void add_contact();
void search_contact();

int main(){
    int choice = 0;
    do
    {
        menu();
        scanf("%d", &choice);
        while(getchar() != '\n');

        switch (choice)
        {
        case 1:
            add_contact();
            break;
        
        case 2:
            search_contact();
            break;

        case 3:
            printf("Bye!\n");
            break;

        default:
            printf("Bad entry! Try again.\n");
            break;
        }

    } while (choice != 3);

    return 0;
};


void menu(){
    printf("=== Telephone book ===\n");
    printf("1. Add contact\n");
    printf("2. Search\n");
    printf("3. Exit\n");
};

void add_contact(){
    FILE *file = fopen("Task_10_phones.txt", "a");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    
    Contact contact;
    char choice;
    do
    {
        printf("*** New contact ***\n");
        printf("Last name (max 20 symbols): ");
        scanf("%20s",contact.last_name);
        printf("First name (max 20 symbols): ");
        scanf("%20s",contact.name);
        printf("Phone number XXX-XX-XX: ");
        scanf("%9s",contact.phone);

        fprintf(file, "%s\n%s\n%s\n", contact.last_name, contact.name, contact.phone);
        fflush(file);
        printf("Contact added successfully!\n");

        printf("Add another one? (y/n): ");
        scanf(" %c", &choice);
        while(getchar() != '\n');
    } while (choice == 'y' || choice =='Y');
    fclose(file);
};

void search_contact(){
    FILE *file = fopen("Task_10_phones.txt", "r");
    if (file == NULL)
    {
        printf("Phonebook is empty! Add contacts first.\n");
        return;
    }
    char search_term[21];
    printf("Enter search term: ");
    fgets(search_term, sizeof(search_term), stdin);
    search_term[strcspn(search_term, "\n")] = 0;

    Contact contact;
    int found = 0;
    while (fgets(contact.last_name, sizeof(contact.last_name), file) != NULL)
    {
        fgets(contact.name, sizeof(contact.name), file);
        fgets(contact.phone, sizeof(contact.phone), file);
#if 0
        printf("DEBUG: Read: last_name\n");
        printf("'%s'\n", contact.last_name);
        
        printf("DEBUG: Read: name\n");
        printf("'%s'\n", contact.name);
        
        printf("DEBUG: Read: phone\n");
        printf("'%s'\n", contact.phone);
#endif
        contact.last_name[strcspn(contact.last_name, "\n")] = 0;
        contact.name[strcspn(contact.name, "\n")] = 0;
        contact.phone[strcspn(contact.phone, "\n")] = 0;

        if (strstr(contact.last_name, search_term) != NULL ||
            strstr(contact.name, search_term) != NULL ||
            strstr(contact.phone, search_term) != NULL)
        {
            printf("%s %s %s\n", contact.last_name, contact.name, contact.phone);
            found = 1;
        }
    }

    if (!found)
    {
        printf("No contacts found.\n");
    }
    fclose(file);
};