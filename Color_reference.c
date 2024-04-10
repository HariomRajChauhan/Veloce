#include <stdio.h>
#include <stdlib.h>

#define Black "\033[0;30m"
#define Red "\033[0;31m"
#define Green "\033[0;32m"
#define Yellow "\033[0;33m"
#define Blue "\033[0;34m"
#define Purple "\033[0;35m"
#define Cyan "\033[0;36m"
#define White "\033[0;37m"
#define CLOSE "\033[0m"

int main()
{
    system("color 20");
    printf("I am the great");
    // printf("%s", Red);   // Set the text to the color red
    // printf("Hello\n");   // Display Hello in red
    // printf("%s", CLOSE); // Resets the text to default color
    // printf("I am the great");
    return 0;
}