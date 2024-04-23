#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "login.h"


int forgot(){
    struct login l;
    struct login l_file;
    FILE *fptr;
    char new_pass[MAX];
    int found = 0;

    printf("Enter the username: ");
    scanf("%s", l.username);

    fptr = fopen("login_user.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return -1;
    }

    while (fscanf(fptr, "%s %s\n", l_file.username, l_file.password) != EOF) {
        if (strcmp(l.username, l_file.username) == 0) {
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Username not found!\n");
        fclose(fptr);
        return 0;
    }

    printf("Enter the new password: ");
    scanf("%s", new_pass);

    fclose(fptr);

    fptr = fopen("login_user.txt", "r");
    FILE *fptr_temp = fopen("login_user_temp.txt", "w");

    while (fscanf(fptr, "%s %s\n", l_file.username, l_file.password) != EOF) {
        if (strcmp(l.username, l_file.username) == 0) {
            fprintf(fptr_temp, "%s %s\n", l_file.username, new_pass);
        } else {
            fprintf(fptr_temp, "%s %s\n", l_file.username, l_file.password);
        }
    }

    fclose(fptr);
    fclose(fptr_temp);

    remove("login_user.txt");
    rename("login_user_temp.txt", "login_user.txt");

    return 1; // Password changed successfully
}