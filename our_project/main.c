#include <stdio.h>
#include <stdlib.h>
#include "signin.c"
#include "signup.c"
#include "forgot.c"
#include "login.h"


int main()
{
    
    int ch;
    printf("------- Welcome to the login system -------\n");
    printf("1. Login\n2. Register\n3. Forgot Password\n4. Exit\n\n");

    printf("Enter your choice: ");
    scanf("%d", &ch);

    do
    {
        system("clear");
        switch (ch)
        {
        case 1:
            if (login() == 1)
            {
                printf("Login successful!\n");
            }
            else
            {
                printf("Login failed!\n");
            }
            break;
        case 2:
            if (register_user() == 1)
            {
                printf("Registration successful!\n");
            }
            else
            {
                printf("Registration failed!\n");
            }
            break;
        case 3:
            if (forgot() == 1)
            {
                printf("Password changed successfully!\n");
            }
            else
            {
                printf("Password change failed!\n");
            }
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (ch != 4);

    return 0;
}
