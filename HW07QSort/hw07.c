// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef TEST_COUNTINT
int countInt(char * filename)
{
    FILE *myFile = fopen(filename, "r"); //try to open the file for reading
    if(!myFile)
        return -1; //return -1 if the file fails to open

    int sum = 0;
    int dummy;
    while(fscanf(myFile, "%d", &dummy) == 1) //read integers until end of file
        sum++;

    fclose(myFile); //close the file
    return sum; //return the sum of all the integers in the file
}
#endif

#ifdef TEST_READINT
bool readInt(char* filename, int * intArr, int size)
{
    FILE *myFile = fopen(filename, "r");//try to open the file for reading
    if(!myFile)
        return false; //return false if the file fails to open

    int count = 0;
    for(count = 0; fscanf(myFile, "%d", (intArr + count)) == 1; count++); //read integers into the array and count them

    fclose(myFile); //close the file

    if(count != size) //if the counted integers don't match the expected size, return false
        return false;
  return true;
}
#endif

#ifdef TEST_COMPAREINT
int compareInt(const void *p1, const void *p2)
{
  // needed by qsort
  //
  // return an integer less than, equal to, or greater than zero if
  // the first argument is considered to be respectively less than,
  // equal to, or greater than the second.

  return *((int *)p1) - *((int *)p2);
}
#endif

#ifdef TEST_WRITEINT
bool writeInt(char* filename, int * intArr, int size)
{
    FILE *myFile = fopen(filename, "w"); //try to open the file for writing
    if(!myFile)
        return false; //if the file fails to open, return false.

    for(int arrIt = 0; arrIt < size; arrIt++)
        fprintf(myFile, "%d\n", intArr[arrIt]); //for-each int in intArr, write it to the file with a newline

    fclose(myFile); //close the file
    return true;
}
#endif
