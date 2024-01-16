#include <stdio.h>

int main() {
    #pragma message("Compiling with Intel C++ Compiler (icx)")
    
    printf("Hello, Intel C++ Compiler!\n");
    
    // Check for Intel Compiler specific macros
    #if defined(__INTEL_COMPILER) || defined(__ICC) || defined(__INTEL_LLVM_COMPILER)
        printf("This code is compiled with Intel C++ Compiler (icx)\n");
    #else
        printf("This code is NOT compiled with Intel C++ Compiler (icx)\n");
    #endif

    return 0;
}

