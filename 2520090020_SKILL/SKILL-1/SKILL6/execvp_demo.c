#include <stdio.h>
#include <unistd.h>

int main()
{
    char *args[] = {"ls", "-l", NULL};

    printf("Before execvp()\n");

    execvp("ls", args);

    printf("This line will not execute.\n");

    return 0;
}
