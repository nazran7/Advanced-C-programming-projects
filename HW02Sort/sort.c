// ***
// *** You MUST modify this file, only the ssort function
// ***

#include "sort.h"
#include <stdio.h>

// DO NOT MODIFY THIS FUNCTION
bool checkOrder(int * arr, int size)
// This function returns true if the array elements are
// in the ascending order.
// false, otherwise
{
  int ind;
  for (ind = 0; ind < (size - 1); ind ++)
    {
      if (arr[ind] > arr[ind + 1])
	{
	  return false;
	}
    }
  return true;
}


// YOU MUST MODIFY THIS FUNCTION
#ifdef TEST_SORT
void ssort(int * arr, int size)
{
    for(int arrIt = 0; arrIt < size-1; arrIt++) //for each element in arr
    {
        int swapIndex = arrIt;
        for(int unsortedIt = arrIt + 1; unsortedIt < size; unsortedIt++) //Only get the unsorted elements of arr
            if(arr[unsortedIt] < arr[swapIndex]) //if the element is smaller than the element at the stored swap index then store the new swap index.
                swapIndex = unsortedIt;

        int tmp = arr[arrIt]; //swap the element with the stored swap index
        arr[arrIt] = arr[swapIndex];
        arr[swapIndex] = tmp;
    }
}
#endif
