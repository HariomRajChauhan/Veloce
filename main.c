#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "vcs.h"

int main()
{
    printf("\033[0;35m");
    load();
    verify_auth();
    printf("\033[0m");
    return 0;
}
