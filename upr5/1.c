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
    int fd2 = open(argv[2], O_RDWR | O_TRUNC | O_CREAT, 0777);

    char input[1024];
    size_t bytesRead = 0;
    while ((bytesRead = read(1, input, 1)))
    {
        //tova gore ne e cikul, toest mojem da prochetem faila i bez while, 
        //no tova dolu iterira veche zapisanoto
        for (ssize_t i = 0; i < bytesRead; i++)
        {
            if (input[i] == '\t')
            {
                write(fd2, "|->", 3);
            }
            else
            {
                write(fd2, &input[i], 1);
            }
            write(fd1, &input[i], 1);
        }
    }

    close(fd1);
    close(fd2);

    return 0;
}