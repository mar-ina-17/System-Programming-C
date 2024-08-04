#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int fdi, fdio, nb1, nb2;
    char buf[15];

    // Отваряме файла "ABC" само за четене
    fdi = open("ABC.txt", O_RDONLY);
    if (fdi < 0)
    {
        perror("Error opening ABC for reading");
        return 1;
    }

    // Отваряме файла "ABC" за четене и запис
    fdio = open("ABC.txt", O_RDWR);
    if (fdio < 0)
    {
        perror("Error opening ABC for reading and writing");
        close(fdi);
        return 1;
    }

    // Четем първите 6 байта от "ABC"
    nb1 = read(fdi, buf, 6);
    write(1, buf, nb1);

    // Преместваме указателя с 3 байта напред от текущата позиция
    lseek(fdi, 3, SEEK_CUR);
    nb1 = read(fdi, buf, 6);
    write(1, buf, nb1);

    // Преместваме указателя 20 байта назад от края на файла и записваме "disc"
    lseek(fdio, -20, SEEK_END);
    write(fdio, "disc", 4);

    // Записваме "over" на текущата позиция
    write(fdio, "over", 4);

    // Четем 5 байта от текущата позиция и ги записваме на стандартния изход
    nb2 = read(fdio, buf, 5);
    write(1, buf, nb2);
    write(1, "sky", 3);

    // Преместваме указателя 2 байта назад от края на файла и четем 2 байта
    lseek(fdi, -2, SEEK_END);
    nb2 = read(fdi, buf, 2);
    write(1, buf, nb2);

    // Затваряме файловите дескриптори
    close(fdi);
    close(fdio);

    return 0;
}
