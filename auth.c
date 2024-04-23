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
void login(struct user);
void signup();
void verify_auth();

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

void login(struct user u)
{
    char password[50];
    printf("Welcome back %s\n", u.name);
    printf("Please enter your password to continue: ");
    enter_password(password);
    printf("\n");
    if (strcmp(password, u.password) == 0)
    {
        printf("Login Succesful");
    }
    else
    {
        printf("Wrong password entered, press any key to continue");
        getch();
        verify_auth();
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
    scanf("%s", u.sec_qstn);
    printf("Enter the answer(Make sure you don't forget it, it is the only way to reset your password): ");
    scanf("%s", u.ans);
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
    system("cls");
    FILE *fptr;
    struct user u;
    fptr = fopen("user.dat", "rb+");
    if (fptr == NULL)
    {
        signup();
    }
    else
    {
        fread(&u, sizeof(u), 1, fptr) == 1;
        login(u);
    }
}