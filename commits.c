#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct repos
{
    char uid[17];
    char name[50];
    char rid[17];
    char id[17];
};

struct commits
{
    char rid[17];
    char cid[17];
    char msg[100];
    char content[1000];
};

struct repos rp;

void create_commit();
void view_commits();
void revert_commit();

void create_commit()
{
    system("cls");
    FILE *fptr;
    struct commits c;
    fptr = fopen("commits.dat", "ab+");
    if (fptr == NULL)
    {
        printf("An unexpected error occured");
        exit(0);
    }
    strcpy(c.rid, rp.rid);
    random(c.cid);
    printf("Enter commit message: ");
    scanf(" %[^\n]", c.msg);
    printf("Enter commit content: ");
    scanf(" %[^\n]", c.content);
    if (fwrite(&c, sizeof(c), 1, fptr) == 1)
    {
        printf("\nCommit succesfully created!");
        fclose(fptr);
    }
    else
    {
        fclose(fptr);
        printf("\nFailed to create commit!");
    }
}

void view_commits()
{
    system("cls");
    FILE *fptr;
    struct commits c;
    fptr = fopen("commits.dat", "rb");
    if (fptr == NULL)
    {
        printf("An unexpected error occured");
        exit(0);
    }
    while (fread(&c, sizeof(c), 1, fptr) == 1)
    {
        if (strcmp(c.rid, rp.rid) == 0)
        {
            printf("Commit ID: %s\n", c.cid);
            printf("Message: %s\n", c.msg);
            printf("Content: %s\n", c.content);
            printf("\n");
        }
    }
    fclose(fptr);
}

void comm_home(struct repos r)
{
    int ch;
    rp = r;
    while (1)
    {
        system("cls");
        printf("Repository: %s\n", r.name);
        printf("1. Create commit\n");
        printf("2. View commits\n");
        printf("3. Revert to commit\n");
        printf("4. Go back\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create_commit();
            break;
        case 2:
            view_commits();
            break;
        case 3:
            revert_commit();
            break;
        case 4:
            return;
        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
        printf("Press any key to continue...");
        getch();
    }
}