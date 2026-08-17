#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid;

    printf("Parent process started\n");
    printf("Parent PID  : %d\n", getpid());
    printf("Parent PPID : %d\n", getppid());

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process
        printf("\n--- CHILD PROCESS ---\n");
        printf("Child PID  : %d\n", getpid());
        printf("Child PPID : %d\n", getppid());

        printf("Child is now Running...\n");

        // Keep child alive for monitoring
        sleep(20);

        printf("Child is Terminating...\n");
        exit(0);
    }
    else {
        // Parent process
        printf("\n--- PARENT PROCESS ---\n");
        printf("Parent PID : %d\n", getpid());
        printf("Child PID  : %d\n", pid);

        printf("Parent is Waiting for child...\n");

        // Parent waits for child
        wait(NULL);

        printf("Child terminated.\n");
        printf("Parent is now Terminating...\n");
    }

    return 0;
}
