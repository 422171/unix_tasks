#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t child1, child2;
    child1 = fork();

    if (child1 < 0) {
        perror("Fork 1 failed");
        return 1;
    } else if (child1 == 0) {
        printf("Child 1 (PID %d) created\n", getpid());
    } else {
        child2 = fork();

        if (child2 < 0) {
            perror("Fork 2 failed");
            return 1;
        } else if (child2 == 0) {
            printf("Child 2 (PID %d) created\n", getpid());
        } else {
            printf("Parent process (PID %d) waiting\n", getpid());
            printf("Both child processes have finished\n");
        }
    }

    return 0;
}