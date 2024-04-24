#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h.>
#include "vcs.h"

struct user
{
    char name[30];
    char username[15];
    char password[50];
    char sec_qstn[100];
    char ans[30];
    char uid[17];
};

struct repos
{
    char uid[17];
    char name[50];
    char rid[17];
    char id[17];
};

struct user usr;

void repo(struct user, int *);
void create_repo();
void view_repos();
void open_repo();

void create_repo()
{
    system("cls");
    FILE *fptr;
    struct repos r;
    fptr = fopen("repos.dat", "ab+");
    if (fptr == NULL)
    {
        printf("An unexpected error occured");
        exit(0);
    }
    printf("Enter repository name: ");
    scanf(" %s", r.name);
    printf("Enter an id for your repository. Don't use same id on two repositories to avoid conflicts.");
    scanf(" %s", r.rid);
    strcpy(r.uid, usr.uid);
    random(r.id);
    if (fwrite(&r, sizeof(r), 1, fptr) == 1)
    {
        printf("\nRepository succesfully created!");
        fclose(fptr);
    }
    else
    {
        fclose(fptr);
        printf("\nFailed to create repository!");
    }
}

void view_repos()
{
    system("cls");

    FILE *fptr;
    struct repos r;
    fptr = fopen("repos.dat", "ab+");
    if (fptr == NULL)
    {
        printf("An unexpected error occured");
        exit(0);
    }
    printf("List of all your repositories:\n");
    while (fread(&r, sizeof(r), 1, fptr) == 1)
    {
        printf("%d\t%s\n", r.rid, r.name);
    }
}
void open_repo(int *rid)
{
    system("cls");
    FILE *fptr;
    struct repos r;
    int flag = 1;
    char temp_id[17];
    fptr = fopen("repos.dat", "ab+");
    if (fptr == NULL)
    {
        printf("An unexpected error occured");
        exit(0);
    }
    printf("Enter the id of the repository you want to open: ");
    scanf(" %s", temp_id);
    while (fread(&r, sizeof(r), 1, fptr) == 1)
    {
        if (strcmp(temp_id, r.rid) == 0)
        {
            printf("Opening repository %s", r.name);
            *rid = r.rid;
            break;
        }
    }
    if (flag)
    {
        printf("Repository not found!");
    }
}

void repo(struct user u, int *rid)
{
    int ch;
    usr = u;
    while (1)
    {
        system("cls");
        printf("--------------------------------------------------------------\n");
        printf("____    ____  _______  __        ______     ______  _______\n");
        printf("\\   \\  /   / |   ____||  |      /  __  \\   /      ||   ____|\n");
        printf(" \\   \\/   /  |  |__   |  |     |  |  |  | |  ,----'|  |__\n");
        printf("  \\      /   |   __|  |  |     |  |  |  | |  |     |   __|\n");
        printf("   \\    /    |  |____ |  `----.|  `--'  | |  `----.|  |____\n");
        printf("    \\__/     |_______||_______| \\______/   \\______||_______|\n");
        printf("--------------------------------------------------------------\n");
        printf("Welcome %s, how's it going?\n", u.name);
        printf("1) Create a repository\n2) View Repositories\n3) Open Repository\n4) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create_repo();
            break;
        case 2:
            view_repos();
            break;
        case 3:
            open_repo(rid);
            break;
        case 4:
            exit(0);
        default:
            printf("Please enter a valid choice!");
            getch();
        }
        printf("\nPress any key to continue: ");
        getch();
    }
}