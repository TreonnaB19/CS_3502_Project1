#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>


int main() {
    int parentToChild[2], childToParent[2]; // Two pipes
    char parentMsg[] = "Hello from Parent!";
    char childMsg[] = "Hello from Child!";
    char buffer[50];

    // Create pipes
    if (pipe(parentToChild) == -1 || pipe(childToParent) == -1) {
        perror("Pipe failed");
        exit(1);
    }

    pid_t pid = fork(); // Create child process

    if (pid < 0) {  // Fork failed
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {  // Child process
        close(parentToChild[1]);  // Close write end of parent->child
        close(childToParent[0]);  // Close read end of child->parent

        // Read message from parent
        read(parentToChild[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);

        // Send message back to parent
        write(childToParent[1], childMsg, strlen(childMsg) + 1);

        close(parentToChild[0]);  // Close read end of parent->child
        close(childToParent[1]);  // Close write end of child->parent
    } else {  // Parent process
        close(parentToChild[0]);  // Close read end of parent->child
        close(childToParent[1]);  // Close write end of child->parent

        // Send message to child
        write(parentToChild[1], parentMsg, strlen(parentMsg) + 1);

        // Read response from child
        read(childToParent[0], buffer, sizeof(buffer));
        printf("Parent received: %s\n", buffer);

        close(parentToChild[1]);  // Close write end of parent->child
        close(childToParent[0]);  // Close read end of child->parent
    }

    return 0;
}
