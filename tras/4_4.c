#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int fd, i, status;

    if (argc != 2)
    {
        printf("Usage: command <file>\n");
        exit(1);
    }

    if (fork()) // Родителски процес
    {
        wait(&status); // Изчаква детския процес
        for (i = 0; i <= 4; i++)
        {
            write(1, "cat\n", 4);
            execlp("cat", "cat", "ABC.txt", NULL);
            write(1, "test1\n", 6); // Това ще се изпълни само ако execlp не успее
        }
    }
    else // Детски процес
    {
        close(1);                   // Затваря стандартния изход
        fd = open(argv[1], O_RDWR); // Отваря файла за четене и запис
        if (fd < 0)
        {
            perror("Error opening file");
            exit(1);
        }
        write(1, "test2\n", 6); // Пише в новия файл
    }

    write(1, "test3\n", 6); // Това ще се изпълни и в двата процеса
    return 0;
}
