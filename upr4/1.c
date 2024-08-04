#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// 1.Напишете програма на Си, която отваря файл за четене, дублира дескритора,
// последователно чете от двата дескриптора и извежда прочетеното на екрана.
// Затваря оригиналния дексриптор и продължава за чете от дублирания.

/*int main(int argc, char **argv)
{
    int fd = open("f1.txt", O_RDWR, 0777);
    if (fd < 0)
    {
        printf("Error opening file\n");
        exit(1);
    }
    int fd2 = dup(fd);

    size_t bytesRead1 = 0, bytesRead2 = 0;
    char buff1[1000], buff2[1000];

    printf("Reading and writing fd 1:\n");
    while ((bytesRead1 = read(fd, buff1, 1)))
    {
        if (bytesRead1 > 0)
        {
            write(1, buff1, bytesRead1);
        }
    }
    printf("Closing fd 1:\n");
    close(fd);
    printf("Reading and writing fd 2:\n");

    while ((bytesRead2 = read(fd2, buff2, 1)))
    {
        if (bytesRead2 > 0)
        {
            write(1, buff2, bytesRead2);
        }
    }
    close(fd2);
    return 0;
}*/

// 2.Напишете програма на Си, която печата символния низ
// „EXAMPLE“ 10 пъти на стандартния изход.В задача 2 се създава файл с име f1
//  и се пранасочва стандартния изход в него :
// •	чрез open
// •	чрез системен примитив dup
// Името на файла се подава като параметър на програмата

// int main(int argc, char **argv)
// {
//     if (argc != 2)
//     {
//         printf("Usage: command <file>\n");
//         exit(1);
//     }
//     int fd = open(argv[1], O_RDWR | O_CREAT, 0777);
//     if (fd < 0)
//     {
//         printf("Error opening file\n");
//         exit(1);
//     }

//     // destination (old fd), source (new fd)
//     dup2(fd, 1);

//     for (int i = 1; i < 11; i++)
//     {
//         write(1, "EXAMPLE\n", 8);
//     }

//     return 0;
// }

// 5.Напишете програма на Си, която печата симолния низ „EXAMPLE“  и
//  символния низ  „HELLO“ 10 пъти на стандартния изход,
//   като между тях се извеждат числата от 1 до 10.
// 6.	В зад 5 след EXAMPLE се пранасочва стандартния изход в
// подадения като параметър файл и числата от 1 до 10 излизат във файла.
// След това се възстановява стандартния изход и HELLO  отново е на екрана.

// int main(int argc, char **argv)
// {
//     if (argc != 2)
//     {
//         printf("Usage: command <file>\n");
//         exit(1);
//     }
//     int fd = open(argv[1], O_RDWR | O_CREAT, 0777);
//     if (fd < 0)
//     {
//         printf("Error opening file\n");
//         exit(1);
//     }

//     // // destination (old fd), source (new fd)
//     // dup2(fd, 1);
//     int stdout_copy = dup(1);
//     if (stdout_copy < 0)
//     {
//         perror("Error duplicating stdout");
//         close(fd);
//         exit(1);
//     }

//     for (int i = 1; i < 11; i++)
//     {
//         write(1, "EXAMPLE\n", 8);
//     }

//     dup2(fd, 1);

//     for (int i = 1; i <= 10; i++)
//     {
//         char num[6];
//         sprintf(num, "%d", i);
//         write(1, &num, strlen(num));
//         write(1, "\n", 1);
//     }

//     dup2(stdout_copy, 1);

//     for (int i = 1; i < 11; i++)
//     {
//         write(1, "HELLO\n", 6);
//     }

//     close(fd);
//     close(stdout_copy);

//     return 0;
// }

// 7.	Напишете програма на Си, която получава като аргумент  два файла.
// Чете от първия файл и извежда
//  във втория чрез механизма на пренасочване на стандартния вход и изход.
// 8.	Примери за пренасочване на стандартния вход и стандартния изход за грешки.

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Usage: command <f1> <f2>\n");
        exit(1);
    }

    int fd1 = open(argv[1], O_RDONLY, 0777);
    int fd2 = open(argv[2], O_RDWR | O_CREAT, 0777);
    if (fd1 < 0 || fd2 < 0)
    {
        printf("Error reading files\n");
        exit(1);
    }

    size_t bytesRead = 0;
    char buff[256];
    dup2(fd1, 0);
    dup2(fd2, 1);

    while ((bytesRead = read(fd1, buff, 1)))
    {
        if (bytesRead > 0)
        {
            write(fd2, buff, bytesRead);
        }
    }

    close(fd1);
    close(fd2);

    return 0;
}
