#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILENAME_LENGTH 100
void Welcome();
void Register();
int Login();
void CreateRepository(const char *repositoryName);
void MakeCommit(const char *repositoryName, const char *commitMessage);
void CompareCommits(const char *repositoryName, int commit1, int commit2);
void RevertToCommit(const char *repositoryName, int commit);
struct Login
{
    char username[100];
    char password[100];
}l;

int main()
{
    Welcome();
    return 0;
}

void Welcome()
{
    int choice;
    while(1)
    {
    printf("Welcome to the Version Control System\n");
    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        Register();
        break;
    case 2:
        if (Login())
        {
            // Successful login, proceed to repository creation
            CreateRepository("example_repository");
        }
        else
        {
            printf("Login failed. Exiting...\n");
            exit(0);
        }
        break;
    case 3:
        exit(0);
    default:
        printf("Invalid choice. Please try again.\n");
        Welcome();
    }
    }

}

void Register()
{
    FILE *fptr;
    fptr = fopen("login.txt", "a+");
    if (fptr == NULL)
    {
        printf("Error opening file!");
        exit(1);
    }
    printf("Enter the username: ");
    scanf("%s", l.username);
    printf("Enter the password: ");
    scanf("%s", l.password);
    fprintf(fptr, "%s %s\n", l.username, l.password);
    fclose(fptr);
}

int Login()
{
    char username[100], password[100];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter Password: ");
    scanf("%s", password);

    FILE *fptr;
    fptr = fopen("login.txt", "r");
    if (fptr == NULL)
    {
        printf("Error opening file!");
        exit(1);
    }
    while (fscanf(fptr, "%s %s", l.username, l.password) == 2)
    {
        if (strcmp(l.username, username) == 0 && strcmp(l.password, password) == 0)
        {
            fclose(fptr);
            printf("Login successful.\n");
            return 1;
        } 
    }

    fclose(fptr);
    printf("Login failed.\n");
    return 0; 
}

void CreateRepository(const char *repositoryName)
{
    int choice;
    printf("Repository created: %s\n", repositoryName);
    while (1)
    {
        printf("\nVersion Control System Menu\n");
        printf("1. Make Commit\n");
        printf("2. Compare Commits\n");
        printf("3. Revert to Commit\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Prompt the user for a commit message and call MakeCommit()
            break;
        case 2:
            // Prompt the user for two commit numbers and call CompareCommits()
            break;
        case 3:
            // Prompt the user for a commit number and call RevertToCommit()
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}

void MakeCommit(const char *repositoryName, const char *commitMessage)
{
    // Create a new commit file in the repository directory
    // You can use the fopen() function to create a new file
    // Write the commit message to the file using fprintf()
}

void CompareCommits(const char *repositoryName, int commit1, int commit2)
{
    // Read the contents of the commit files for commit1 and commit2
    // Compare the contents and display the differences
}

void RevertToCommit(const char *repositoryName, int commit)
{
    // Read the contents of the commit file for the given commit
    // Overwrite the current working directory with the contents of the commit file
}
