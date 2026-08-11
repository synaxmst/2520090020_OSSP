#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    char command[100];

    while (1)
    {
        printf("MiniShell> ");
        scanf("%s", command);

        if (strcmp(command, "exit") == 0)
            break;

        pid_t pid = fork();

        if (pid == 0)
        {
            printf("Child PID : %d\n", getpid());
            execlp(command, command, NULL);

            printf("Command not found!\n");
            exit(1);
        }
        else
        {
            printf("Parent PID : %d\n", getpid());
            wait(NULL);
        }
    }

    return 0;
}
