// To use from console:
// ./factorial <factorial to calculate> <number of repetitions>

// Each implementation of the factorial algorithm will calculate the
// <factorial to calculate>, <number of repetitions> times, measuring
// total and average run time. Results will be prited to console.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "timeutils.h"

// =========================================================================
//                               Functions
// =========================================================================

// Using for loop
long iterative_for_factorial(long n) {
    long acc = 1;
    for (n = n; n > 0; n--) acc *= n;
    return acc;
}

// Using while loop
long iterative_while_factorial(long n) {
    long acc = 1;
    while (n > 0) {
        acc *= n;
        n--;
    }
    return acc;
}

// Using recursion
long recursive_factorial(long n) {
    if (n < 1) return 1;
    return n * recursive_factorial(n-1);
}

// Using recursion and ternary operator
long recursive_ternary_factorial(long n) {
    return n < 1 ? 1 : n * recursive_ternary_factorial(n - 1);
}

// =========================================================================
//                               Main()
// =========================================================================

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("\nusage: factorial <factorial to calculate> <repetitions>\n\n");
        return 1;
    }

    long number = atol(argv[1]);
    long times  = atol(argv[2]);

    double iterative_for_time     = time_it(number, times, iterative_for_factorial);
    double iterative_while_time   = time_it(number, times, iterative_while_factorial);
    double recursive_time         = time_it(number, times, recursive_factorial);
    double recursive_ternary_time = time_it(number, times, recursive_ternary_factorial);

    double iterative_for_average     = iterative_for_time     / times;
    double iterative_while_average   = iterative_while_time   / times;
    double recursive_average         = recursive_time         / times;
    double recursive_ternary_average = recursive_ternary_time / times;
    
    printf("\n");
    printf("==============================================\n");
    printf("==============================================\n\n");
    printf("Factorial Algorithm\n");
    printf("Factorial calculated: %ld\n", number);
    printf("Number of times: %ld\n", times);
    printf("(all results are in seconds) \n");
    printf("----------------------------------------------\n");
    printf("\n");

    printf("Total time:\n");
    printf("iterative_for_factorial:     %f\n", iterative_for_time);
    printf("iterative_while_factorial:   %f\n", iterative_while_time);
    printf("recursive_factorial:         %f\n", recursive_time);
    printf("recursive_ternary_factorial: %f\n", recursive_ternary_time);

    printf("\n");

    printf("Average time:\n");
    printf("iterative_for_factorial:     %f\n", iterative_for_average);
    printf("iterative_while_factorial:   %f\n", iterative_while_average);
    printf("recursive_factorial:         %f\n", recursive_average);
    printf("recursive_ternary_factorial: %f\n", recursive_ternary_average);

    printf("\n");
    printf("==============================================\n");
    printf("==============================================\n\n");

    return 0;

}
