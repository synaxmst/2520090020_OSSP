#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        printf("Child Process\n");
        printf("Child PID : %d\n", getpid());
    }
    else
    {
        wait(NULL);
        printf("Parent Process\n");
        printf("Parent PID : %d\n", getpid());
    }

    return 0;
}
