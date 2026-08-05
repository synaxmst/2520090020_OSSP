#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int src,dst,n;
    char buffer[1024];

    src=open("input.txt",O_RDONLY);

    dst=open("output.txt",
             O_WRONLY|O_CREAT|O_TRUNC,
             0644);

    while((n=read(src,buffer,sizeof(buffer)))>0)
        write(dst,buffer,n);

    close(src);
    close(dst);

    printf("File Copied Successfully\n");

    return 0;
}
