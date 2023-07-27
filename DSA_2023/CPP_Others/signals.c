/*
In C, signals are a way for the operating system to notify a process about events or interruptions that occur during its execution. Signal handlers are functions that are executed when a specific signal is received by a process.

Here's an example of how to use signals and signal handlers in C:
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Signal handler function
void sig_handler(int signum) {
    printf("Signal %d received. Exiting...\n", signum);
    // Clean up and exit the program
    exit(signum);
}

int main() {
    // Register signal handler for SIGINT (Ctrl+C)
    signal(SIGINT, sig_handler);

    // Infinite loop to keep the program running
    while (1) {
        printf("Running...\n");
        sleep(1); // Wait for 1 second
    }

    return 0;
}

/*
In this example, we register a signal handler for the SIGINT signal (which is generated when the user presses Ctrl+C). When the program is running, it will keep printing "Running..." every second. If the user presses Ctrl+C, the SIGINT signal will be sent to the process, and the signal handler sig_handler will be executed.

When the signal handler is called, it prints a message indicating which signal was received and then calls the exit function to terminate the program gracefully.

You can try running this program and observe how it responds to the SIGINT signal when you press Ctrl+C.
*/