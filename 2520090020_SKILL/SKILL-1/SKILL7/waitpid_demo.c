#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        printf("Child Process\n");
        sleep(2);
        printf("Child Finished\n");
    }
    else
    {
        waitpid(pid, NULL, 0);
        printf("Parent Continues\n");
    }

    return 0;
}
