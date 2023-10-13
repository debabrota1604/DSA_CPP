/*
n the context of Linux, fork() and exec() are two system calls used to create a new process and replace the current process image, respectively. Together, they are commonly used to create a new process and execute a different program in that new process.

Here's an example of how fork() and exec() are used together:
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int status;

    // Fork a new process
    pid = fork();

    if (pid < 0) {
        // Error occurred during fork
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process (PID %d) executing ls...\n", getpid());

        // Execute the 'ls' command using exec
        execl("/bin/ls", "ls", "-l", NULL);

        // This line will only execute if execl fails
        perror("Exec failed");
        return 1;
    } else {
        // Parent process
        printf("Parent process (PID %d) waiting for the child to complete...\n", getpid());

        // Wait for the child process to complete
        wait(&status);

        printf("Child process (PID %d) completed.\n", pid);
    }

    return 0;
}

/*
In this example, the fork() system call is used to create a new child process. The child process then uses the exec() family of functions (in this case, execl()) to execute the "ls" command and replace its own process image with the "ls" program. The parent process waits for the child to complete using the wait() system call.

When you run this program, you will see the output of the "ls" command executed by the child process, and then the parent process will print a message after the child process completes.
*/