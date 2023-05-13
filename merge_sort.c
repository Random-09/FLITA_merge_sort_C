#include <string.h>
#include "merge_sort.h"


void parseFile(FILE *inputFilePtr) {
    fseek(inputFilePtr, 0, SEEK_END);
    int inputFileLen = ftell(inputFilePtr);
    fseek(inputFilePtr, 0, SEEK_SET);
    char *data;
    data = (char *) malloc(sizeof(char) * inputFileLen);
    fread(data, sizeof(char), inputFileLen, inputFilePtr);
    data[inputFileLen] = '\0';
    printf("%s", data);
}
