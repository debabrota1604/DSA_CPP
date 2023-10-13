#include <iostream>
#include <cuda_runtime.h>

// CUDA kernel to print a message
__global__ void helloCUDA() {
    printf("Hello, CUDA from thread %d\n", threadIdx.x);
}

int main() {
    int numThreads = 16;  // Number of threads in the thread block
    int numBlocks = 1;   // Number of thread blocks in the grid

    // Launch the CUDA kernel
    helloCUDA<<<numBlocks, numThreads>>>();

    // Wait for the kernel to finish
    cudaDeviceSynchronize();

    std::cout << "Kernel execution is complete.\n";

    return 0;
}
/

/*
In this simplified example:

We define a CUDA kernel helloCUDA that uses printf to print a message including the thread index.
In the main function, we specify the number of threads per block (numThreads) and the number of blocks (numBlocks) in the grid.
We launch the helloCUDA kernel with the specified configuration.
We use cudaDeviceSynchronize() to wait for the kernel to finish execution.
Finally, we print a message to indicate that the kernel execution is complete.
This program is a minimal CUDA example that demonstrates how to launch a basic kernel on the GPU. Make sure you have the CUDA Toolkit properly configured on your system to compile and run this code.
*/