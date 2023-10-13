#include <iostream>
#include <cuda_runtime.h>

// CUDA kernel to add two arrays on the GPU
__global__ void addArrays(int *a, int *b, int *c, int size) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (idx < size) {
        c[idx] = a[idx] + b[idx];
    }
}

int main() {
    int size = 10000;  // Size of the arrays
    int *a, *b, *c;    // Host arrays
    int *d_a, *d_b, *d_c;  // Device arrays

    // Allocate memory for host arrays
    a = new int[size];
    b = new int[size];
    c = new int[size];

    // Initialize host arrays
    for (int i = 0; i < size; i++) {
        a[i] = i;
        b[i] = i * 2;
    }

    // Allocate memory for device arrays
    cudaMalloc((void**)&d_a, size * sizeof(int));
    cudaMalloc((void**)&d_b, size * sizeof(int));
    cudaMalloc((void**)&d_c, size * sizeof(int));

    // Copy host data to device
    cudaMemcpy(d_a, a, size * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, b, size * sizeof(int), cudaMemcpyHostToDevice);

    // Launch the CUDA kernel
    int threadsPerBlock = 256;
    int blocksPerGrid = (size + threadsPerBlock - 1) / threadsPerBlock;
    addArrays<<<blocksPerGrid, threadsPerBlock>>>(d_a, d_b, d_c, size);

    // Copy device result back to host
    cudaMemcpy(c, d_c, size * sizeof(int), cudaMemcpyDeviceToHost);

    // Free device memory
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

    // Print the first 10 elements of the result
    for (int i = 0; i < 10; i++) {
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;

    // Free host memory
    delete[] a;
    delete[] b;
    delete[] c;

    return 0;
}


/*
In this program:

We allocate memory for host and device arrays.
Initialize host arrays.
Allocate memory for device arrays and copy data from the host to the device.
Launch a CUDA kernel (the addArrays function) to add the arrays on the GPU.
Copy the device result back to the host.
Free device and host memory.
Print the first 10 elements of the result.
This program provides a basic example of using CUDA for parallel computing on a GPU. Make sure you have the CUDA Toolkit installed and configured on your system to compile and run this code.




Thread vs block vs grid:
Threads:
    Threads are the smallest units of execution in CUDA. Each thread represents an individual instance of a program running on the GPU.
    Threads execute the same code, but they can differentiate their behavior based on their unique thread ID.
    Thread IDs are often represented as threadIdx.x, threadIdx.y, and threadIdx.z in CUDA, where x, y, and z refer to the thread's position within a block.
Blocks:
    Blocks are groups of threads that can execute concurrently on a streaming multiprocessor (SM) within the GPU.
    Threads within the same block can communicate with each other via shared memory.
    Blocks are identified by their block ID, which is accessible as blockIdx.x, blockIdx.y, and blockIdx.z.
    The number of threads per block is limited by the GPU architecture and is typically a multiple of 32 (warp size), but you can configure it when launching a kernel.
Grids:
    Grids are the top-level organization of threads in CUDA and consist of multiple blocks.
    Blocks within a grid can execute independently and in parallel on different SMs within the GPU.
    Grids are identified by their grid ID, which is accessible as gridDim.x, gridDim.y, and gridDim.z.
    The total number of threads in a grid is the product of the number of threads per block and the number of blocks in the grid.

Grid 0               Grid 1               Grid 2
+---------+         +---------+         +---------+
| Block 0 |         | Block 0 |         | Block 0 |
| +---+   |         | +---+   |         | +---+   |
| | T |   |         | | T |   |         | | T |   |
| | 0 |   |         | | 0 |   |         | | 0 |   |
| +---+   |         | +---+   |         | +---+   |
+---------+         +---------+         +---------+
| Block 1 |         | Block 1 |         | Block 1 |
| +---+   |         | +---+   |         | +---+   |
| | T |   |         | | T |   |         | | T |   |
| | 1 |   |         | | 1 |   |         | | 1 |   |
| +---+   |         | +---+   |         | +---+   |
+---------+         +---------+         +---------+
    ...                 ...                 ...
In the diagram, there are three grids, each containing multiple blocks. Each block contains several threads. Threads within the same block can share data through shared memory and synchronize their execution when needed.

CUDA enables the efficient use of GPU resources and parallelism by allowing you to configure and launch kernels with specific thread and block configurations to best suit your computational tasks.
*/