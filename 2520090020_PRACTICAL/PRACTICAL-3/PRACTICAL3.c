#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid=fork();

    if(pid==0)
    {
        printf("Child Process\n");
        printf("PID : %d\n",getpid());
        printf("PPID: %d\n",getppid());

        sleep(5);
    }
    else
    {
        printf("Parent Process\n");
        printf("PID : %d\n",getpid());

        sleep(5);
    }

    return 0;
}
