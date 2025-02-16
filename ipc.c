#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main() {
    int fd[2];
    pid_t pid;
    char buffer[50];
    
    if (pipe(fd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid > 0) { // Parent Process
        close(fd[0]); // Close unused read end
        char message[] = "Hello from parent!";
        write(fd[1], message, strlen(message) + 1);
        close(fd[1]); // Close write end after writing
    } else { // Child Process
        close(fd[1]); // Close unused write end
        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(fd[0]); // Close read end after reading
    }

    return 0;
}
