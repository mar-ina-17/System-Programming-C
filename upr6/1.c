#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

// 1.	Напишете програма на Си, която изпълнява команда извеждаща редовете,
// в които се среща символния низ int в подадения като параметър файл.
//  int main(int argc, char *argv[])
//  {
//      if (argc != 2)
//      {
//          printf("Usage: command <file>\n");
//          exit(1);
//      }

//     char *args[] = {"grep", "int", argv[1], NULL};
//     execvp("grep", args);

//     return 0;
// }

// 3.	Да се напише програма на С, която получава като параметър команда (без параметри) и
// при успешното ѝ изпълнение, извежда на стандартния изход името на командата.

// int main(int argc, char *argv[])
// {
//     if (argc != 2)
//     {
//         printf("Usage: <command>\n");
//         exit(1);
//     }

//     char *args[] = {argv[1], NULL};
//     int status = 0;
//     pid_t pid = fork();
//     if (pid == 0)
//     {
//         execvp(argv[1], args);
//     }
//     else
//     {
//         waitpid(pid, &status, 0);
//         printf("Status of command: %d\n", status);
//     }

//     return 0;
// }

// 5.	Да се напише програма на С, която получава като параметри три команди (без параметри), изпълнява ги последователно,
// като изчаква края на всяка и извежда на
// стандартния изход номера на завършилия процес, както и неговия код на завършване

// int main(int argc, char *argv[])
// {
//     if (argc != 4)
//     {
//         printf("Usage: <command1> <command2> <command3>\n");
//         exit(1);
//     }
//     int i = 1, status = 0;
//     for (int i = 1; i < 4; i++)
//     {
//         pid_t pid = fork();
//         if (pid == 0)
//         {
//             char *args[] = {argv[i], NULL};
//             execvp(argv[i], args);
//         }
//         else
//         {
//             waitpid(pid, &status, 0);
//             printf("Status of %s is %d\n", argv[i], status);
//         }
//         i++;
//     }
//     return 0;
// }