#include <iostream>
#include <omp.h>

/*
OpenMP is a set of compiler directives and library routines that support parallel programming in C++. It simplifies the process of parallelizing loops and tasks using pragmas.
*/

int main() {
    #pragma omp parallel
    {
        int threadId = omp_get_thread_num();
        std::cout << "This is thread " << threadId << std::endl;
    }

    return 0;
}
