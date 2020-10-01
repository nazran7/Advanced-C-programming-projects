// ***
// *** You must modify this file
// ***
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hw08.h"


#ifdef TEST_COUNTVECTOR
int countVector(char * filename)
{
    FILE *myFile = fopen(filename, "r"); //try to open filename for reading
    if(!myFile)
        return -1;// If fopen fails, return -1

    fseek(myFile, 0, SEEK_END);
    int vecCount = ftell(myFile) / sizeof(Vector);
    
    fclose(myFile);
    return vecCount;

}
#endif

#ifdef TEST_READVECTOR
bool readVector(char* filename, Vector * vecArr, int size)
{
    FILE *myFile = fopen(filename, "rb"); //try to open filename for reading
    if(!myFile)
        return false;// If fopen fails, return false


    if(fread(vecArr, sizeof(Vector), size, myFile) != size || feof(myFile))
    {
        fclose(myFile);
        return false;
    }
    fclose(myFile);
    return true;
}
#endif

#ifdef TEST_COMPAREVECTOR
int compareVector(const void *p1, const void *p2)
{
    Vector *a = (Vector *)p1;
    Vector *b = (Vector *)p2;

    if(a->x < b->x)
        return -1;
    if(a->x > b->x)
        return 1;

    if(a->y < b->y)
        return -1;
    if(a->y > b->y)
        return 1;

    if(a->z < b->z)
        return -1;
    if(a->z > b->z)
        return 1;

    return 0;
    // compare the x attribute first
    // If the first vector's x is less than the second vector's x
    // return -1
    // If the first vector's x is greater than the second vector's x
    // return 1
    // If the two vectors' x is the same, compare the y attribute
    //
    // If the first vector's y is less than the second vector's y
    // return -1
    // If the first vector's y is greater than the second vector's y
    // return 1
    // If the two vectors' y is the same, compare the z attribute
    //
    // If the first vector's z is less than the second vector's z
    // return -1
    // If the first vector's z is greater than the second vector's z
    // return 1
    // If the two vectors' x, y, z are the same (pairwise), return 0
}
#endif

#ifdef TEST_WRITEVECTOR
bool writeVector(char* filename, Vector * vecArr, int size)
{
    FILE *myFile = fopen(filename, "wb"); //try to open filename for writing
    if(!myFile)
        return false;// If fopen fails, return false


    if(fwrite(vecArr, sizeof(Vector), size, myFile) != size)// write the array to file using fwrite
    {
        // need to check how many have been written
        fclose(myFile);
        return false;// if not all are written, fclose and return false
    }
    fclose(myFile);
    return true;
}
#endif

// This function is provided to you. No need to change
void printVector(Vector * vecArr, int size)
{
    int ind = 0;
    for (ind = 0; ind < size; ind ++)
    {
        printf("%6d %6d %6d\n",
               vecArr[ind].x, vecArr[ind].y, vecArr[ind].z);
    }
}
