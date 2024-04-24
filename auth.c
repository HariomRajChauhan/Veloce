#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct user
{
    char name[30];
    char username[15];
    char password[50];
    char sec_qstn[100];
    char ans[30];
};

void enter_password(char[]);
void login();
void signup();
void verify_auth();
void reset_pwd();

void enter_password(char pwd[])
{
    char ch;
    int i = 0;

    while ((ch = getch()) != 13 && i < 50)
    {
        if (ch == '\b')
        {
            printf("\b \b");
            continue;
        }
        pwd[i++] = ch;
        printf("*");
    }

    pwd[i] = '\0';
}

void reset_pwd()
{
    printf("Reset Password?");
}

void login()
{
    int flag = 1, choice;
    FILE *fptr;
    struct user u;
    char uname[50];
    fptr = fopen("user.dat", "rb+");
    if (fptr == NULL)
    {
        printf("An internal error occured");
        exit(0);
    }
    char password[50];
    printf("Enter your username: ");
    scanf("%s", uname);
    printf("Password: ");
    enter_password(password);
    printf("\n");
    while (fread(&u, sizeof(u), 1, fptr) == 1)
    {
        if (strcmp(password, u.password) == 0 && strcmp(uname, u.username) == 0)
        {
            printf("Login Succesful");
            flag = 0;
            break;
        }
    }
    fclose(fptr);
    if (flag)
    {
        printf("Your credentials don't match any data in our database. Would you like to:\n1)Re-enter password\n2) Reset Password\n3) Back to main menu\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            login();
            break;
        case 2:
            reset_pwd();
            break;
        case 3:
            verify_auth();
            break;
        default:
            login();
            break;
        }
    }
}

void signup()
{
    FILE *fptr;
    fptr = fopen("user.dat", "wb");
    struct user u;
    printf("Welcome to Kithub\n");
    printf("Create an accout to get started\n");
    printf("Enter your username: ");
    scanf("%s", u.username);
    printf("Enter your password: ");
    enter_password(u.password);
    printf("\n");
    printf("Enter your name: ");
    scanf(" %[^\n]", u.name);
    printf("Enter a security question: ");
    scanf(" %[^\n]", u.sec_qstn);
    printf("Enter the answer(Make sure you don't forget it, it is the only way to reset your password): ");
    scanf(" %[^\n]", u.ans);
    if (fwrite(&u, sizeof(u), 1, fptr) == 1)
    {
        fclose(fptr);
        printf("Creating user succesful");
    }
    else
    {
        fclose(fptr);
        printf("Failed to create user");
    }
}

void verify_auth()
{
    int ch;
    system("cls");
    printf("1) Login\n2) Signup\n3) Exit\n");
    printf("Please enter your choice: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        login();
        break;
    case 2:
        signup();
        break;
    case 3:
        exit(0);
    default:
        printf("Enter a valid choice");
        verify_auth();
        break;
    }
}