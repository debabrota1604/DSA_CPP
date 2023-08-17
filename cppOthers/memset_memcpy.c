/*
The memset function is used to fill a block of memory with a specified value. It's commonly used to initialize arrays to a specific value.
*/

#include <stdio.h>
#include <string.h>

int main() {
    char str[20];
    
    memset(str, 'A', sizeof(str)); // Fill the array with 'A'
    printf("Initialized string: %s\n", str);
    
    return 0;
}

/*
memcpy: The memcpy function is used to copy a block of memory from one location to another.
*/

#include <stdio.h>
#include <string.h>

int main() {
    char source[] = "Hello, memcpy!";
    char destination[20];
    
    memcpy(destination, source, strlen(source) + 1); // Copy source to destination
    printf("Copied string: %s\n", destination);
    
    return 0;
}

/*
In the memcpy example, the source string is copied to the destination array. The strlen(source) + 1 is used to copy the null-terminated string, including the null terminator itself.

Keep in mind that memcpy should be used with caution, especially when working with overlapping memory regions, as it may not produce the expected results. In such cases, you might want to consider using memmove instead.
*/

