/*
To print using system calls, you can use the write system call in C. The write system call allows you to write data to a file descriptor, and the file descriptor for standard output is 1.

Here's an example of how to use the write system call to implement printf:
*/

#include <unistd.h>
#include <stdarg.h>

// Custom printf function using write system call
int my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    char buffer[1024];
    int len = vsnprintf(buffer, sizeof(buffer), format, args);

    va_end(args);

    return write(1, buffer, len);
}

int main() {
    int num = 42;
    char str[] = "Hello, world!";

    // Using custom printf function
    my_printf("This is a number: %d\n", num);
    my_printf("This is a string: %s\n", str);

    return 0;
}

/*
In this example, the my_printf function takes the same arguments as printf using the ... syntax. It uses the vsprintf function to format the string and store it in the buffer. Then, it calls the write system call to write the formatted string to the standard output (file descriptor 1).

Please note that this is a basic example of implementing printf using the write system call. The actual printf function in the standard library is much more sophisticated, handling various formatting options, conversions, and edge cases.
*/