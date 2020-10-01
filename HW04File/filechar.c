// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#ifdef TEST_COUNTCHAR
bool countChar(char * filename, int * counts, int size)
{
    FILE *myFile = fopen(filename, "r"); //open filename for reading
    if(!myFile)
        return false; //if it fails, return false

    int onechar = EOF;
    while((onechar = fgetc(myFile)) != EOF) //read characters until end of file is reached.
        if(onechar < size) //check that the ascii value for the character is a valid index for counts.
            counts[onechar]++;
    fclose(myFile); //close the file
  return true;
}
#endif

#ifdef TEST_PRINTCOUNTS
void printCounts(int * counts, int size)
{
    for(int charIt = 0; charIt < size; charIt++) //for-each element in counts
        if(counts[charIt] > 0) //don't print if the total for this ascii character is 0.
            printf("%d, %c, %d\n", charIt, (isalpha(charIt) ? charIt : ' '), counts[charIt]); //if the character isn't a-z or A-Z then only print a space.
}
#endif
