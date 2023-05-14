#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "merge_sort.h"

#define BILLION 1000000000.0

int main(int argc, char **argv) {
    if (argc != 2) {
        puts("Wrong number of arguments");
        exit(EXIT_FAILURE);
    }
    char *filePath = argv[1];
    FILE *filePtr;
    filePtr = fopen(filePath, "r");
    if (filePtr == NULL) {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }
    int len = getLen(filePtr);
    double *array = parse(filePtr, len);
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);
    mergeSort(array, 0, len - 1);
    clock_gettime(CLOCK_REALTIME, &end);
    long double time_spent = (long double) (end.tv_sec - start.tv_sec) +
                             (end.tv_nsec - start.tv_nsec) / BILLION;
    printf("\nTime taken to sort %d numbers: %Lf seconds\n", len, time_spent);
    free(array);
    fclose(filePtr);
    return EXIT_SUCCESS;
}
