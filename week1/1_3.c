#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Add 'cat >> file' command
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: cat >> <file>\n");
        exit(1);
    }

    int fdWrite = open(argv[1], O_RDWR | O_CREAT, 0777);
    if (fdWrite < 0)
    {
        printf("Error opening file %s\n", argv[1]);
        exit(1);
    }
    char buff[1024];
    ssize_t bytesRead;
    while ((bytesRead = read(0, buff, sizeof(buff))) > 0)
    {
        ssize_t bytesWritten = write(fdWrite, buff, bytesRead);
        if (bytesWritten != bytesRead)
        {
            perror("Error writing to file");
            close(fdWrite);
            exit(1);
        }
    }

    if (bytesRead < 0)
    {
        perror("Error reading from stdin");
    }

    close(fdWrite);

    return 0;
}