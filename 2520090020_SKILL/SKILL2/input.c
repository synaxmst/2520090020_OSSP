#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>

int main()
{
    struct termios oldt, newt;
    char buffer[100];
    int index = 0;
    char ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    while (1)
    {
        printf("ossh> ");
        fflush(stdout);

        index = 0;

        while (1)
        {
            ch = getchar();

            if (ch == '\n' || ch == '\r')
            {
                buffer[index] = '\0';
                printf("\n");
                break;
            }
            else if (ch == 127 || ch == 8)
            {
                if (index > 0)
                {
                    index--;
                    printf("\b \b");
                    fflush(stdout);
                }
            }
            else if (index < 99)
            {
                buffer[index++] = ch;
                putchar(ch);
                fflush(stdout);
            }
        }

        if (strcmp(buffer, "exit") == 0)
        {
            printf("Exiting shell...\n");
            break;
        }

        if (index > 0)
        {
            printf("You entered: %s\n", buffer);
        }
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return 0;
}
