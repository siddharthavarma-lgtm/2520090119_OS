#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char buffer[100];

    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid > 0) {
        // Parent - Producer
        close(pipefd[0]);

        strcpy(buffer, "Hello from Producer! Data sent to Consumer.");

        clock_t start = clock();

        write(pipefd[1], buffer, strlen(buffer) + 1);

        clock_t end = clock();

        close(pipefd[1]);

        double time_taken =
            (double)(end - start) / CLOCKS_PER_SEC;

        printf("Producer: Data sent successfully.\n");
        printf("Communication time: %f seconds\n", time_taken);

        wait(NULL);
    }
    else {
        // Child - Consumer
        close(pipefd[1]);

        read(pipefd[0], buffer, sizeof(buffer));

        printf("Consumer: Data received: %s\n", buffer);

        close(pipefd[0]);
    }

    return 0;
}
