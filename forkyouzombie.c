/*--forkyouzombie.c--*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
    pid_t spawnPid = -5;
    int childExitStatus = -5;

    spawnPid = fork();

    switch (spawnPid)
    {
        case -1:
        {
            perror("Hull Breach!\n");
            exit(1);
            break;
        }
        case 0:
        {
            printf("CHILD: Terminating!\n");
            break;
        }
        default:
        {
            printf("PARENT: making child a zombie for ten seconds;\n");
            printf("PARENT: Type \"ps -elf | grep \'username\'\" to see the defunct child\n");
            printf("PARENT: Sleeping...\n");
            fflush(stdout); // make sure all text is outputted before sleeping
            sleep(10);
            waitpid(spawnPid, &childExitStatus, 0);
            break;
        }
    }

    printf("This will be executed by both of us!\n");
    exit(0);
}