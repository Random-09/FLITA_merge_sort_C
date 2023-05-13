#include <stdio.h>
#include <stdlib.h>
#include "merge_sort.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        puts("Wrong number of arguments.");
        exit(EXIT_FAILURE);
    }
    char *filePath = argv[1];
    FILE *filePtr = fopen(filePath, "r");
    if (filePtr == NULL) {
        puts("Error opening file.");
        exit(EXIT_FAILURE);
    }
    parseFile(filePtr);
    fclose(filePtr);


    return EXIT_SUCCESS;
}
