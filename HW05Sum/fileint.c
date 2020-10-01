// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>

#ifdef TEST_ADDFILE
bool addFile(char * filename, int * sum)
{
    *sum = 0; //sum is not guaranteed to be 0.

    FILE *myFile = fopen(filename, "r"); //try to open filename for reading
    if(!myFile)
        return false; //return false if the file could not be opened.

    int number = 0;
    while(fscanf(myFile, "%d", &number) == 1) //keep reading numbers until end of file.
        *sum += number; //keep a running total of the read integers.

    fclose(myFile); //close the file
  return true;
}
#endif


#ifdef TEST_WRITESUM
bool writeSum(char * filename, int sum)
{
    FILE *myFile = fopen(filename, "w"); //try to open filename for writing
    if(!myFile)
        return false; //return false if the file could not be opened.

    fprintf(myFile, "%d\n", sum); //write the sum and a newline to the file
    fclose(myFile); //close the file
  return true;
}
#endif
