#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100

struct login
{
    char username[100];
    char password[100];
} l;

void Register()
{
    FILE *fptr;
    fptr = fopen("login.txt", "a+");
    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    printf("Enter the username: ");
    scanf("%s", l.username);
    printf("Enter the password: ");
    scanf("%s", l.password);
    fprintf(fptr, "%s\n%s", l.username, l.password);
    fclose(fptr);
}

void Welcome(){
    int choice ;
    printf("Welcome to the Version Control System\n");
    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice)
    {
    case 1:
        //Register();
        break;
    case 2:
        // Login();
        break;

    case 3:
        exit(0);

    default:
        printf("Invalid choice. Please try again.\n");
    } 

}

void createRepository(const char *repositoryName)
{
    // Create a directory with the given repository name
    // You can use the mkdir() function from <sys/stat.h> to create the directory
}

void makeCommit(const char *repositoryName, const char *commitMessage)
{
    // Create a new commit file in the repository directory
    // You can use the fopen() function to create a new file
    // Write the commit message to the file using fprintf()
}

void compareCommits(const char *repositoryName, int commit1, int commit2)
{
    // Read the contents of the commit files for commit1 and commit2
    // Compare the contents and display the differences
}

void revertToCommit(const char *repositoryName, int commit)
{
    // Read the contents of the commit file for the given commit
    // Overwrite the current working directory with the contents of the commit file
}

int main()
{
    char repositoryName[MAX_FILENAME_LENGTH];
    int choice;

    Welcome();

    Register();
    printf("Enter the repository name: ");
    scanf("%s", repositoryName);

    createRepository(repositoryName);

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
            // Prompt the user for a commit message and call makeCommit()
            break;
        case 2:
            // Prompt the user for two commit numbers and call compareCommits()
            break;
        case 3:
            // Prompt the user for a commit number and call revertToCommit()
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}