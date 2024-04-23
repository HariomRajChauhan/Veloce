#include <stdio.h>
#define MAX 50
#include "login.h"


int register_user() {
    struct login l;
    FILE *fptr;

    printf("Enter the username: ");
    scanf("%s", l.username);
    printf("Enter the password: ");
    scanf("%s", l.password);

    fptr = fopen("login_user.txt", "a");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return -1;
    }

    fprintf(fptr, "%s %s\n", l.username, l.password);
    fclose(fptr);

    return 1; // Successful registration
}