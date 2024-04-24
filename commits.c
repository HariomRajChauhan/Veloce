#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include "vcs.h"

struct repos
{
    char uid[17];
    char name[50];
    int rid;
    char id[17];
    int initialized;
    char fpath[250];
};

struct commits
{
    int rid;
    char cid[17];
    char msg[100];
    char content[1000];
};

struct repos *rp;
int opflag = 0;
char filepath[250], filename[50];

void create_commit();
void view_commits();
void revert_commit();
void init();

void init(struct repos *r)
{
    FILE *fptr;
    int ch;
    struct commits c;
    struct repos k;
    printf("Initialize repository first to create commits\n");
    printf("1) Init existing file\n2) Create new file\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("Enter filepath of your existing .txt file: ");
        scanf("%s", filepath);
        fptr = fopen(filepath, "r");
        if (fptr == NULL)
        {
            perror("Error opening file");
            exit(0);
        }
        fgets(c.content, sizeof(c.content), fptr);
        fclose(fptr);
        break;
    case 2:
        printf("Enter the name of your file: ");
        scanf("%s", filename);
        if (_mkdir(filename) != 0)
        {
            perror("Error creating directory");
        }
        strcpy(c.content, "");
        strcpy(filepath, filename);
        strcat(filepath, "/");
        strcat(filepath, filename);
        strcat(filepath, ".txt");
        FILE *newfile;
        newfile = fopen(filepath, "w");
        if (newfile == NULL)
        {
            perror("Error creating file");
            exit(0);
        }
        fprintf(newfile, "");
        fclose(newfile);
        break;
    }
    strcpy(c.msg, "Initial commit");
    fptr = fopen("commits.dat", "ab");
    if (fptr == NULL)
    {
        perror("Error opening file");
        exit(0);
    }
    c.rid = r->rid;
    random(c.cid);
    if (fwrite(&c, sizeof(c), 1, fptr) == 1)
    {
        printf("\nCommit successfully created!");
        r->initialized = 1;
        strcpy(r->fpath, filepath); // Set initialized flag to true
    }
    else
    {
        printf("\nFailed to create commit!");
    }
    fclose(fptr);
    fptr = fopen("repos.dat", "rb+");
    if (fptr == NULL)
    {
        printf("An error occured");
        exit(0);
    }
    while (fread(&k, sizeof(k), 1, fptr) == 1)
    {
        if (k.rid == r->rid)
        {
            strcpy(k.fpath, filepath);
            k.initialized = 1;
            fseek(fptr, -sizeof(k), SEEK_CUR);
            fwrite(&k, sizeof(k), 1, fptr);
            break;
        }
    }
    comm_home();
}

void create_commit()
{
    FILE *fptr;
    struct commits c;
    fptr = fopen(filepath, "r");
    if (fptr == NULL)
    {
        printf("Failed to open the text file!");
        printf("%s", filepath);
        exit(0);
    }
    fgets(c.content, sizeof(c.content), fptr);
    fclose(fptr);
    printf("Enter commit message: ");
    scanf("%s", c.msg);
    c.rid = rp->rid;
    random(c.cid);
    fptr = fopen("commits.dat", "ab");
    if (fptr == NULL)
    {
        perror("Error opening file");
        exit(0);
    }
    if (fwrite(&c, sizeof(c), 1, fptr) == 1)
    {
        printf("\nCommit successfully created!");
    }
    else
    {
        printf("\nFailed to create commit!");
    }
    fclose(fptr);
}

void view_commits()
{
    int i = 1;
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
        if (c.rid == rp->rid)
        {
            printf("Commit %d\n", i++);
            printf("Message: %s\n", c.msg);
            printf("Content: %s\n", c.content);
            printf("\n");
        }
    }
    fclose(fptr);
}

void revert_commit()
{
}

void comm_home()
{
    int ch;

    while (1)
    {
        system("cls");
        printf("Repository: %s\n", rp->name);
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
            opflag = 1;
            break;
        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
        if (opflag)
        {
            break;
        }
        printf("Press any key to continue...");
        getch();
    }
}

void comm(struct repos *r)
{
    rp = r;
    strcpy(filename, r->fpath);
    if (r->initialized)
    {
        comm_home();
    }
    else
    {
        init(r);
    }
}