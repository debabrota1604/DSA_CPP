/*
The POSIX Real-Time Extensions (also known as POSIX.1b or POSIX 1003.1b) provide additional functionality 
for real-time programming in POSIX-compliant operating systems. This example demonstrates how to use the 
POSIX Real-Time Extensions to create two threads with different scheduling policies (SCHED_FIFO and SCHED_RR) to illustrate real-time scheduling.
*/

#include <iostream>
#include <pthread.h>
#include <unistd.h>

// Function executed by Thread 1 (SCHED_FIFO)
void* threadFunctionFIFO(void* arg) {
    int threadId = *(reinterpret_cast<int*>(arg));

    struct timespec startTime;
    clock_gettime(CLOCK_MONOTONIC, &startTime);

    for (int i = 0; i < 5; ++i) {
        std::cout << "Thread " << threadId << " (SCHED_FIFO) - Iteration: " << i << std::endl;
        usleep(500000); // Sleep for 500 ms (simulate work)
    }

    struct timespec endTime;
    clock_gettime(CLOCK_MONOTONIC, &endTime);

    double executionTime = (endTime.tv_sec - startTime.tv_sec) +
                           (endTime.tv_nsec - startTime.tv_nsec) * 1e-9;
    std::cout << "Thread " << threadId << " (SCHED_FIFO) - Execution Time: " << executionTime << " seconds" << std::endl;

    return nullptr;
}

// Function executed by Thread 2 (SCHED_RR)
void* threadFunctionRR(void* arg) {
    int threadId = *(reinterpret_cast<int*>(arg));

    struct timespec startTime;
    clock_gettime(CLOCK_MONOTONIC, &startTime);

    for (int i = 0; i < 5; ++i) {
        std::cout << "Thread " << threadId << " (SCHED_RR) - Iteration: " << i << std::endl;
        usleep(700000); // Sleep for 700 ms (simulate work)
    }

    struct timespec endTime;
    clock_gettime(CLOCK_MONOTONIC, &endTime);

    double executionTime = (endTime.tv_sec - startTime.tv_sec) +
                           (endTime.tv_nsec - startTime.tv_nsec) * 1e-9;
    std::cout << "Thread " << threadId << " (SCHED_RR) - Execution Time: " << executionTime << " seconds" << std::endl;

    return nullptr;
}

int main() {
    pthread_t threadFIFO, threadRR;
    int threadId1 = 1, threadId2 = 2;

    // Create Thread 1 with SCHED_FIFO scheduling policy
    pthread_attr_t attrFIFO;
    pthread_attr_init(&attrFIFO);
    struct sched_param paramFIFO;
    paramFIFO.sched_priority = 90; // Highest priority for SCHED_FIFO
    pthread_attr_setschedparam(&attrFIFO, &paramFIFO);
    pthread_attr_setschedpolicy(&attrFIFO, SCHED_FIFO);
    pthread_create(&threadFIFO, &attrFIFO, threadFunctionFIFO, &threadId1);

    // Create Thread 2 with SCHED_RR scheduling policy
    pthread_attr_t attrRR;
    pthread_attr_init(&attrRR);
    struct sched_param paramRR;
    paramRR.sched_priority = 80; // Medium priority for SCHED_RR
    pthread_attr_setschedparam(&attrRR, &paramRR);
    pthread_attr_setschedpolicy(&attrRR, SCHED_RR);
    pthread_create(&threadRR, &attrRR, threadFunctionRR, &threadId2);

    // Wait for threads to finish
    pthread_join(threadFIFO, nullptr);
    pthread_join(threadRR, nullptr);

    return 0;
}

/*
In this example, we have two threads: Thread 1 (SCHED_FIFO) and Thread 2 (SCHED_RR). 
Both threads run for five iterations, with different sleep durations to simulate varying amounts of work. 
The threads are given different scheduling policies and priorities using the POSIX Real-Time Extensions.



Please note that the usage of SCHED_FIFO and SCHED_RR should be done with caution, as changing the 
scheduling priorities can impact the system's overall performance and responsiveness. It's essential to 
understand the real-time requirements and constraints of your application and system before using real-time scheduling policies.
*/