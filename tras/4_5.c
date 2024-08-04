#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int fdi, fdio, nb1, nb2;
    char buf[15];

    // Отваряме файла "abc" само за четене
    fdi = open("ABC.txt", O_RDONLY);
    if (fdi < 0)
    {
        perror("Error opening abc for reading");
        return 1;
    }

    // Отваряме файла "abc" за четене и запис
    fdio = open("ABC.txt", O_RDWR);
    if (fdio < 0)
    {
        perror("Error opening abc for reading and writing");
        close(fdi);
        return 1;
    }

    // Четем първите 6 байта от "abc"
    nb1 = read(fdi, buf, 6);
    if (nb1 > 0)
    {
        write(1, buf, nb1);
    }

    // Преместваме указателя с 3 байта напред от текущата позиция
    lseek(fdi, 3, SEEK_CUR);
    nb1 = read(fdi, buf, 6);
    if (nb1 > 0)
    {
        write(1, buf, nb1);
    }

    // Преместваме указателя 18 байта назад от края на файла и записваме "tra"
    lseek(fdio, -18, SEEK_END);
    write(fdio, "tra", 3);

    // Записваме "vel" на текущата позиция
    write(fdio, "vel", 3);

    // Четем 5 байта от текущата позиция и ги записваме на стандартния изход
    nb2 = read(fdio, buf, 5);
    if (nb2 > 0)
    {
        write(1, buf, nb2);
    }

    // Пишем "time" на стандартния изход
    write(1, "time", 4);

    // Преместваме указателя 2 байта назад от края на файла и четем 2 байта
    lseek(fdi, -2, SEEK_END);
    nb2 = read(fdi, buf, 2);
    if (nb2 > 0)
    {
        write(1, buf, nb2);
    }

    // Затваряме файловите дескриптори
    close(fdi);
    close(fdio);

    return 0;
}
