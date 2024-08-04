#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Usage: command <file1> <file2>\n");
        exit(1);
    }

    int fd1 = open(argv[1], O_RDWR | O_CREAT | O_APPEND, 0777);
    if (fd1 < 0)
    {
        perror("Error opening file1");
        exit(1);
    }

    int fd2 = open(argv[2], O_RDWR | O_TRUNC | O_CREAT, 0777);
    if (fd2 < 0)
    {
        perror("Error opening file2");
        close(fd1);
        exit(1);
    }

    char input[1024];
    ssize_t bytesRead;

    while ((bytesRead = read(fd1, input, sizeof(input))) > 0)
    {
        for (ssize_t j = 0; j < bytesRead; j++)
        {
            // Check if the character is not a digit
            if (!(input[j] >= '0' && input[j] <= '9'))
            {
                write(fd2, &input[j], 1);
            }
        }
    }

    if (bytesRead < 0)
    {
        perror("Error reading file1");
    }

    close(fd1);
    close(fd2);

    return 0;
}
