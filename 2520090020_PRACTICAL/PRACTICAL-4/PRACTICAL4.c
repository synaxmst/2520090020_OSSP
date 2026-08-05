#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        printf("Child Process\n");
        sleep(3);
        printf("Child Finished\n");
    }
    else
    {
        printf("Parent Waiting...\n");
        wait(NULL);
        printf("Parent Continues\n");
    }

    return 0;
}
