#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "merge_sort.h"

#define BILLION 1000000000.0

int main(int argc, char **argv) {
    if (argc != 3) {
        puts("Wrong number of arguments");
        exit(EXIT_FAILURE);
    }
    char *inputfilePath = argv[1];
    char *outputfilePath = argv[2];
    FILE *inputFilePtr;
    FILE *outputFilePtr;
    inputFilePtr = fopen(inputfilePath, "r");
    if (inputFilePtr == NULL) {
        puts("Error opening file");
        exit(EXIT_FAILURE);
    }
    int len = getLen(inputFilePtr);
    double *array = parse(inputFilePtr, len);
    fclose(inputFilePtr);
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);
    mergeSort(array, 0, len - 1);
    clock_gettime(CLOCK_REALTIME, &end);
    double time_spent = (double) (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
    printf("\nTime taken to sort %d numbers: %F seconds\n", len, time_spent);
    outputFilePtr = fopen(outputfilePath, "w");
    writeToFile(array, len, outputFilePtr);
    free(array);
    fclose(outputFilePtr);
    return EXIT_SUCCESS;
}
