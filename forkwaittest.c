/*--forkwaittest.c--*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
    pid_t spawnPid = -5;
    int childExitMethod = -5;

    pid_t getPid = getpid();
    printf("1st getPid: %d\n", getPid);

    spawnPid = fork();

    getPid = getpid();
    printf("2nd getPid: %d, spawnPid: %d\n", getPid, spawnPid);

    if (spawnPid == -1)
    {
        perror("Hull Breach!\n");
        exit(1);
    }
    else if (spawnPid == 0) // Terminate the child process immediately
    {
        printf("CHILD: PID: %d, running! gonna sleep for a sec.\n", spawnPid);
        sleep(1);
        printf("CHILD: PID: %d, exiting!\n", spawnPid);
        exit(0);
    }

    printf("PARENT: PID: %d, waiting...\n", spawnPid);
    waitpid(spawnPid, &childExitMethod, 0); // Blocks the parent until the child process with specified PID terminates
    printf("PARENT: Child process terminated, exiting!\n");
    exit(0);
}