/*
In C, variable arguments can be taken using the concept of the "variable argument list" provided by the standard library. This feature allows a function to accept a variable number of arguments of different types.

The stdarg.h header provides the necessary macros and types to work with variable arguments. The main macros used are va_list, va_start, va_arg, and va_end.

Here's a simple example of how to use variable arguments in C:
*/

#include <stdio.h>
#include <stdarg.h>

// A function that takes variable arguments and calculates their sum
int sum(int num, ...) {
    va_list args;
    va_start(args, num);

    int total = 0;

    for (int i = 0; i < num; i++) {
        int arg = va_arg(args, int);
        total += arg;
    }

    va_end(args);

    return total;
}

int main() {
    int result1 = sum(3, 10, 20, 30);
    int result2 = sum(5, 1, 2, 3, 4, 5);

    printf("Result 1: %d\n", result1);
    printf("Result 2: %d\n", result2);

    return 0;
}

/*
In this example, the sum function takes an integer num as the first argument, which represents the number of variable arguments that will follow. Inside the function, we declare a va_list type variable args and initialize it using va_start. Then, we can use the va_arg macro to access each argument one by one and calculate their sum. Finally, we use va_end to clean up the argument list.

Please note that variable arguments should be used with caution, as they do not provide type safety, and it is the responsibility of the programmer to handle the arguments correctly inside the function.
*/