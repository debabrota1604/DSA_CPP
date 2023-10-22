#include <stdio.h>
#include <stdint.h>

extern uint64_t read_tsc();

void print_unsigned(uint64_t value) {
    if (value > 9) {
        print_unsigned(value / 10);
    }
    putchar('0' + value % 10);
}

int main() {
    uint64_t start_time, end_time;

    start_time = read_tsc();

    // Your code to measure here
    // For example, a loop:
    uint64_t i;
    for (i = 0; i < 1000000000; i++) {
        // Your code here
    }

    end_time = read_tsc();

    uint64_t elapsed_time = end_time - start_time;

    // Your code to print or store the result
    // For example, printing to the console:
    print_unsigned(elapsed_time);

    return 0;
}


/*
gcc -o a.out CPUspeed_part1.c CPUspeed_part2.asm
*/