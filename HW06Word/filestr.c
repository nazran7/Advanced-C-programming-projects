// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef TEST_COUNTWORD
int countWord(char * filename, char * word, char * line, int size)
{
    FILE *myFile = fopen(filename, "r"); //try to open filename for reading
    if(!myFile)
        return -1; //if the file fails to open, return -1

    int wordLen = strlen(word); //saves calling strlen multiple times in a loop.
    int sum = 0; //running total
    while(!feof(myFile) && fgets(line, size, myFile)) //Get chunks of the file, split by either '\n' or size.
    {
        char *tmpLine = line; //preserve the pointer to line
        while((tmpLine = strstr(tmpLine, word)) != NULL) //keep checking word is inside tmpLine and increment tmpLine by the word size each time it's matched.
        {
            sum++;
            tmpLine += wordLen;
        }
    }

    fclose(myFile); //close the file

  return sum;
}
#endif
