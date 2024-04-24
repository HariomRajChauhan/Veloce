#include <stdio.h>
#include <string.h>


typedef struct User {
  char username[50];
  char password[50];
} User;


typedef struct Commit {
  char message[100];
  char content[1024];
} Commit;


User users[10];
int user_count = 0;


char current_file[100];


int login(char username[], char password[]);
int register_user(char username[], char password[]);
void make_commit(char message[]);
void view_commit(int commit_id);
void delete_commit(int commit_id);

int main() {
  strcpy(current_file, "");

  int choice;
  while (1) {
    printf("\nSimple Version Control System\n");
    printf("1. Login\n");
    printf("2. Register\n");
    printf("3. Make Commit\n");
    printf("4. View Commit\n");
    printf("5. Delete Commit\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        if (login("", "")) {
          printf("Login successful!\n");
        } else {
          printf("Invalid username or password.\n");
        }
        break;
      case 2:
        register_user("", "");
        break;
      case 3: {
        char message[100];
        printf("Enter commit message: ");
        scanf(" %[^\n]", message);
        make_commit(message);
        break;
      }
      case 4: {
        int commit_id;
        printf("Enter commit ID: ");
        scanf("%d", &commit_id);
        view_commit(commit_id);
        break;
      }
      case 5: {
        int commit_id;
        printf("Enter commit ID to delete: ");
        scanf("%d", &commit_id);
        delete_commit(commit_id);
        break;
      }
      case 6:
        printf("Exiting...\n");
        return 0;
      default:
        printf("Invalid choice.\n");
    }
  }

  return 0;
}


int login(char username[], char password[]) {
  for (int i = 0; i < user_count; i++) {
    if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
      return 1;
    }
  }
  return 0;
}

int register_user(char username[], char password[]) {
  if (user_count == 10) {
    printf("Maximum number of users reached.\n");
    return 0;
  }

  strcpy(users[user_count].username, username);
  strcpy(users[user_count].password, password);
  user_count++;
  return 1;
}

void make_commit(char message[]) {
  Commit commit;
  strcpy(commit.message, message);
  strcpy(commit.content, current_file);
  printf("Commit made successfully.\n");
}

void view_commit(int commit_id) {
  printf("Commit ID: %d\n", commit_id);
  printf("Message: ");
  printf("Content: ");
}

void delete_commit(int commit_id) {
  printf("Commit deleted successfully.\n");
}


