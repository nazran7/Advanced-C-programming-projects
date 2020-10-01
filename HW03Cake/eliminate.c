// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#ifdef TEST_ELIMINATE
// 100% of the score
void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails, stop
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }
  // initialize all elements


    for(int arrIndex = 0; arrIndex < n; arrIndex++)
        arr[arrIndex] = 1; //alive = 1, dead = -1

    int lastAliveIndex = 0;
    for(int aliveCount = n, arrIt = 0; aliveCount > 0; aliveCount--) //We know that each iteration will kill a cell
    {
        for(int counter = 0; counter < k; arrIt = (arrIt >= n-1 ? 0 : arrIt+1)) //increment arrIt only if it is within the range of the array, otherwise set it to 0.
        {
            if(arr[arrIt] != -1)
            {
                counter++; //count alive cells
                lastAliveIndex = arrIt; //keep track of the cell we land on.
            }
        }
        printf("%d\n", lastAliveIndex); //print cell index that we landed on and kill it.
        arr[lastAliveIndex] = -1;
    }



  // release the memory of the array
  free (arr);
}
#endif
