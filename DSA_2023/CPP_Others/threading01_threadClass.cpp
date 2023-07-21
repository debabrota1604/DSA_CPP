#include <iostream>
#include <thread>

/*
C++11 introduced the <thread> header, which provides a native multithreading API. 
It allows you to create and manage threads using the std::thread class. 
You can launch new threads and join them later to synchronize their execution.
*/

void threadFunction() {
    std::cout << "This is a thread." << std::endl;
}

int main() {
    std::thread myThread(threadFunction);
    myThread.join(); // Wait for the thread to finish

    return 0;
}
