// ***
// *** You must modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hw08.h"

#ifdef TEST_MAIN
int main(int argc, char * * argv)
{
    // argv[1]: name of input file (binary)
    // argv[2]: name of output file (binary)

    if(argc != 3)// check whether there are three arguments.
        return EXIT_FAILURE; // If not, return EXIT_FAILURE. DO NOT print anything

    int vecCount = countVector(argv[1]); // use argv[1] as the input to countVector, save the result
    if(vecCount <= 0)
        return EXIT_FAILURE; // if the number of vector is 0 or negative, return EXIT_FAILURE

    Vector *vecArr = (Vector *)malloc(sizeof(Vector) * vecCount); // otherwise, allocate memory for an array of vectors
    if(!readVector(argv[1], vecArr, vecCount))// read the vectors from the file whose name is argv[1]. save the results in the allocated array
    {
        free(vecArr);
        return EXIT_FAILURE;// if reading fails, release memory and return EXIT_FAILURE
    }


#ifdef DEBUG
    printVector(vecArr, vecCount);
#endif

    qsort(vecArr, vecCount, sizeof(Vector), compareVector);

#ifdef DEBUG
    printf("\n");
    printVector(vecArr, vecCount);
#endif

    if(!writeVector(argv[2], vecArr, vecCount))
    {
        free(vecArr);
        return EXIT_FAILURE;
    }
    // write the sorted array to the file whose name is argv[2]
    // if writing fails, release memory and return EXIT_FAILURE
    free(vecArr);
    return EXIT_SUCCESS;

    // release memory, return EXIT_SUCCESS
}
#endif
