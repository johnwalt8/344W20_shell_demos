/*--CheckingTheExitStatus.c--*/

int childExitMethod;
pid_t childPID = wait(&childExitMethod);

if (childPID == -1)
{
    perror("wait failed");
    exit(1);
}

if (WIFEXITED (childExitMethod))
{
    printf("The process exited normally\n");
    int exitStatus = WEXITSTATUS(childExitMethod);
    prinf("Exit status was %d\n:, exitStatus");
}
else
{
    printf("Child terminated by a signal\n");
}
