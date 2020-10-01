// ***
// *** You must modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hw07.h"

#ifdef TEST_MAIN
int main(int argc, char * * argv)
{
    if(argc != 3)  // if argc is not 3, return EXIT_FAILURE
        return EXIT_FAILURE;

               // count the number of integers in the file
    int numElem = 0;
    numElem = countInt(argv[1]);

    if (numElem == -1) // fopen fails
    {
        return EXIT_FAILURE;
    }

    // allocate memory for the integers in the file
    int * intArr = (int *)malloc(sizeof(int) * numElem);// 1. create a pointer variable 2. allocate memory
    if(!intArr)// 3. check whether allocation succeed
        return EXIT_FAILURE;//    if allocation fails, return EXIT_FAILURE

    bool rtv = readInt(argv[1], intArr, numElem);
    if (rtv == false) //if read fails, return EXIT_FAILURE
    {
        return EXIT_FAILURE;
    }

    qsort (intArr, numElem, sizeof(int), compareInt);//call qsort using the comparison function you write

    // write the sorted array to a file whose name is argv[2]
    rtv = writeInt(argv[2], intArr, numElem);
    if (rtv == false) // read fail
    {
        free(intArr);// release memory
        return EXIT_FAILURE;
    }

    // everything is ok, release memory, return EXIT_SUCCESS
    free(intArr);
    return EXIT_SUCCESS;
}
#endif

