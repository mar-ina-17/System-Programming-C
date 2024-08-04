#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// int main(int argc, char **argv)
// {
//     int fd1 = open("fff.txt", O_RDONLY | O_CREAT, 0777);
//     int fd2 = open("fff.txt", O_WRONLY, 0777);
//     int fd3 = open("fff.txt", O_RDWR, 0777);

//     if (fd1 < 0 || fd2 < 0 || fd3 < 0)
//     {
//         perror("Error opening file");
//         exit(EXIT_FAILURE);
//     }

//     // Записване в файла чрез fd2
//     if (write(fd2, "Hello World", 11) < 0)
//     {
//         perror("write fd2");
//         exit(EXIT_FAILURE);
//     }

//     // Четене от fd3
//     char buffer[20]; // Буфер за четене
//     ssize_t bytesRead = read(fd3, buffer, 6);
//     if (bytesRead < 0)
//     {
//         perror("read fd3");
//         exit(EXIT_FAILURE);
//     }
//     buffer[bytesRead] = '\0'; // Нулев терминиращ символ за правилен низ
//     printf("Read from fd3: %s\n", buffer);

//     // Четене от fd1
//     bytesRead = read(fd1, buffer, 5);
//     if (bytesRead < 0)
//     {
//         perror("read fd1");
//         exit(EXIT_FAILURE);
//     }
//     buffer[bytesRead] = '\0';
//     printf("Read from fd1: %s\n", buffer);

//     // Записване в fd3
//     if (write(fd3, "chil", 4) < 0)
//     {
//         perror("write fd3");
//         exit(EXIT_FAILURE);
//     }

//     // Записване в fd2
//     if (write(fd2, "!!!", 3) < 0)
//     {
//         perror("write fd2");
//         exit(EXIT_FAILURE);
//     }

//     // Четене от fd1 отново
//     bytesRead = read(fd1, buffer, 9);
//     if (bytesRead < 0)
//     {
//         perror("read fd1 again");
//         exit(EXIT_FAILURE);
//     }
//     buffer[bytesRead] = '\0';
//     printf("Read again from fd1: %s\n", buffer);

//     // Затваряне на файловете
//     close(fd1);
//     close(fd2);
//     close(fd3);

//     return 0;
// }

// int main(int argc, char **argv)
// {
//     int fd1 = open("f1.txt", O_RDONLY | O_CREAT, 0777);
//     int fd2 = open("f1.txt", O_RDWR, 0777);
//     if (fd1 < 0 | fd2 < 0)
//     {
//         printf("Error opening file\n");
//         exit(1);
//     }
//     lseek(fd2, -2, SEEK_END);
//     write(fd2, "wxyz", 4);
//     lseek(fd2, 5, SEEK_SET);
//     write(fd2, "12", 2);

//     size_t byteRead = 0;
//     char buff[25];
//     while ((byteRead = read(fd1, buff, 1)))
//     {
//         write(1, buff, byteRead);
//     }

//     close(fd1);
//     close(fd2);

//     return 0;
// }

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Usage: command <file> <line>\n");
        exit(1);
    }

    int fd2 = open("f1.txt", O_RDWR, 0777);
    if (fd2 < 0)
    {
        printf("Error opening file\n");
        exit(1);
    }

    size_t bytesRead = 0, line = 1;
    int num = atoi(argv[2]);
    char buff[1024];
    read(fd2, buff, 1);
    
    char ar[10];
    sprintf(ar, "NR==%d", num);
    char *arg[] = {"awk", ar, argv[1], NULL};

    execvp("awk", arg);
    close(fd2);

    return 0;
}
