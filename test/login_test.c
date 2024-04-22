#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct login {
    
    char username[50];
    char password[50];
};

int register_user() {
    struct login l;
    FILE *fptr;

    printf("Enter the username: ");
    scanf("%s", l.username);
    printf("Enter the password: ");
    scanf("%s", l.password);

    fptr = fopen("login_register.txt", "a");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return -1;
    }

    fprintf(fptr, "%s %s\n", l.username, l.password);
    fclose(fptr);

    return 2; // Successful registration
}



int login() {
    struct login l;
    struct login l_file;
    FILE *fptr;

    printf("Enter the username: ");
    scanf("%s", l.username);
    printf("Enter the password: ");
    scanf("%s", l.password);

    fptr = fopen("login_register.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return -1;
    }

    while (fscanf(fptr, "%s %s\n", l_file.username, l_file.password) != EOF) {
        if (strcmp(l.username, l_file.username) == 0 && strcmp(l.password, l_file.password) == 0) {
            fclose(fptr);
            return 1; // Successful login
        }
    }

    fclose(fptr);
    return 0; // Failed login
}

int main() {
    int choice;
    int login_status;

    printf("1. Register\n2. Login\n3. View Password\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        if (register_user() == 2) {
            printf("Registration successful!\n");
        } else {
            printf("Registration failed!\n");
        }
    } else if (choice == 2) {
        login_status = login();
        if (login_status == 1) {
            printf("Login successful!\n");
        } else if (login_status == 0) {
            printf("Login failed!\n");
        } else {
            printf("Error logging in!\n");
        }
    }
    else if(choice==3){
        system("clear");
        FILE *fptr;
        char c;
        fptr = fopen("login_register.txt", "r");
        if (fptr == NULL) {
            printf("Error opening file!\n");
            return -1;
        }
        c = fgetc(fptr);
        printf("\t\tThe Username & Password of this file are:\n");
        while (c != EOF)
        {
            printf ("%c", c);
            c = fgetc(fptr);
        }
        fclose(fptr);
    }
    
    
     else {
        printf("Invalid choice!\n");
    }
    getch();
    return 0;
}