#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define MAX_FILENAME_LENGTH 100


struct Login_Register
{
    char username[MAX_FILENAME_LENGTH];
    char password[MAX_FILENAME_LENGTH];
} l;

void Register()
{
    FILE *fptr;
    fptr = fopen("login_register.txt", "a");
    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    printf("Enter the username: ");
    scanf("%s", l.username);
    printf("Enter the password: ");
    scanf("%s", l.password);
    fprintf(fptr, "%s %s\n", l.username, l.password);
    fclose(fptr);
}

void login(){
    FILE *fptr;
    fptr = fopen("login_register.txt", "r");
    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    char username[MAX_FILENAME_LENGTH], password[MAX_FILENAME_LENGTH];
    printf("Enter the username: ");
    scanf("%s", username);
    printf("Enter the password: ");
    scanf("%s", password);
    char temp[MAX_FILENAME_LENGTH];


    while (fgets(temp, MAX_FILENAME_LENGTH, fptr) != NULL)
    {
        if (strcmp(temp, username) == 0)
        {
            fgets(temp, MAX_FILENAME_LENGTH, fptr);
            if (strcmp(temp, password) == 0)
            {
                printf("Login successful\n");
                break;
            }
        }
    }
    fclose(fptr);

}



int main(){
    int chice;
    printf("Welcome to the Version Control System\n");
    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &chice);
    switch (chice)
    {
    case 1:
        Register();
        break;

    case 2:
        login();
        break;

    case 3:
        exit(0);

    default:
        printf("Invalid choice. Please try again.\n");
    }



    return 0;
}