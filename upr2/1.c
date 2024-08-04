#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// 1 & 2
// int main(int argc, char **argv)
// {
//     int fd = open("aa.txt", O_RDONLY, 0777);
//     if (fd < 0)
//     {
//         printf("Error opening file\n");
//         exit(1);
//     }

//     char buff[16];
//     ssize_t bytesRead = 0;
//     for (int i = 5; i > 1; i--)
//     {
//         bytesRead = read(fd, buff, sizeof(buff));
//         if (bytesRead > 0)
//         {
//             printf("iteration %d\n", i);
//             write(1, buff, bytesRead);
//             printf("\n");
//         }
//     }

//     close(fd);
//     return 0;
// }

// 3 & 6
// int main(int argc, char **argv)
// {
//     if (argc != 2)
//     {
//         printf("Command format: comm <file>\n");
//         exit(1);
//     }

//     int fd = open(argv[1], O_RDONLY, 0777);
//     if (fd < 0)
//     {
//         printf("Error opening file\n");
//         exit(1);
//     }

//     char buff[16];
//     ssize_t bytesRead = 0;
//     for (int i = 5; i > 1; i--)
//     {
//         lseek(fd, -3, SEEK_END);
//         bytesRead = read(fd, buff, sizeof(buff));
//         if (bytesRead > 0)
//         {
//             printf("iteration %d\n", i);
//             write(1, buff, bytesRead);
//             printf("\n");
//         }
//     }

//     close(fd);
//     return 0;
// }
// -----------
// a) iteration 5
// ABCDEFGHIJKLMNOP
// iteration 4
// ABCDEFGHIJKLMNOP
// iteration 3
// ABCDEFGHIJKLMNOP
// iteration 2
// ABCDEFGHIJKLMNOP
//-----------
// b)iteration 5
// DEFGHIJKLMNOPQRS
// iteration 4
// DEFGHIJKLMNOPQRS
// iteration 3
// DEFGHIJKLMNOPQRS
// iteration 2
// DEFGHIJKLMNOPQRS
//-----------
// v) Moves three chars of current position
// iteration 5
// DEFGHIJKLMNOPQRS
// iteration 4
// WXYZ
//----------
// g) iteration 5
// XYZ
// iteration 4
// XYZ
// iteration 3
// XYZ
// iteration 2
// XYZ

// 7
// int main(int argc, char **argv)
// {
//     if (argc != 2)
//     {
//         printf("Command format: comm <file>\n");
//         exit(1);
//     }

//     int fd = open(argv[1], O_RDONLY, 0777);
//     if (fd < 0)
//     {
//         printf("Error opening file\n");
//         exit(1);
//     }

//     char buff[16];
//     ssize_t bytesRead = 0;
//     int forkRes = -1;
//     for (int i = 5; i > 1; i--)
//     {
//         forkRes = fork();
//         if (forkRes > 0)
//         {
//             bytesRead = read(fd, buff, sizeof(buff));
//             if (bytesRead > 0)
//             {
//                 printf("iteration %d\n", i);
//                 write(1, buff, bytesRead);
//                 printf("\n");
//             }
//         }
//         else if (forkRes == 0)
//         {
//             char *args[] = {"wc", "-c", argv[1], NULL};
//             execvp("wc", args);
//         }
//         else
//         {
//             printf("Fork unsuccessful\n");
//             exit(1);
//         }
//     }

//     close(fd);
//     return 0;
// }

// 8
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Command format: comm <file>\n");
        exit(1);
    }

    int fd = open(argv[1], O_RDONLY, 0777);
    int fd1 = open("aa1.txt", O_RDWR | O_CREAT, 0777);
    if (fd < 0 || fd1 < 0)
    {
        printf("Error opening file \n");
        exit(1);
    }

    char buff[16];
    ssize_t bytesRead = 0;
    while ((bytesRead = read(fd, buff, 10)))
    {
        write(1, buff, strlen(buff));
    }
    close(fd);
    return 0;
}