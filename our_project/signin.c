#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "login.h"


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

