/*
In Unix, message passing is a form of inter-process communication (IPC) that allows different processes to exchange data or synchronize their actions. There are various mechanisms for message passing in Unix, including pipes, message queues, and sockets. Here, we'll focus on two commonly used methods: pipes and message queues.
*/

//Pipes: Pipes are a simple form of message passing used for communication between two related processes, where one process writes data to the pipe, and the other reads it. There are two types of pipes in Unix: anonymous pipes and named pipes (also known as FIFOs).

// 1. Anonymous Pipes: These are unidirectional and allow communication between parent and child processes or between two processes created by the same parent process. The data written to the pipe by the writer process can be read by the reader process.
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd[2];
    char buffer[50];
    pipe(fd);

    if (fork() == 0) { // Child process
        close(fd[0]); // Close reading end of the pipe
        write(fd[1], "Hello, parent!", 14);
        close(fd[1]);
    } else { // Parent process
        close(fd[1]); // Close writing end of the pipe
        read(fd[0], buffer, sizeof(buffer));
        printf("Received message: %s\n", buffer);
        close(fd[0]);
    }

    return 0;
}


//2. Named Pipes (FIFOs): Named pipes are similar to anonymous pipes but provide a way for unrelated processes to communicate. They have a name associated with them and can be created using the mkfifo system call.

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    char buffer[50];
    mkfifo("myfifo", 0666);

    int fd = open("myfifo", O_RDONLY);
    read(fd, buffer, sizeof(buffer));
    printf("Received message: %s\n", buffer);
    close(fd);

    return 0;
}


//Message Queues: Message queues are a more sophisticated form of message passing that allow multiple processes to communicate asynchronously. Each message in the queue has a type and a size, and processes can send and receive messages based on their type.
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

struct message {
    long mtype;
    char mtext[50];
};

int main() {
    key_t key;
    int msgid;
    struct message msg;

    key = ftok("msgfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);

    msgrcv(msgid, &msg, sizeof(msg.mtext), 1, 0);
    printf("Received message: %s\n", msg.mtext);

    return 0;
}

//These are the basic mechanisms for message passing in Unix. Each mechanism has its use cases and advantages, and the choice of the appropriate IPC method depends on the requirements of the specific application.