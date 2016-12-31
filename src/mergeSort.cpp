#include "mergeSort.h"
#include <algorithm>

void mergeSort(int intArray[], const size_t &length)
{
    return;
    for(size_t j = 0; j < length-1; j++)
    {
        for(size_t i = 0; i < length-1; i++)
        {
            //intArray[i]>intArray[i+1] ? cout << "higher\n" : cout << "lower\n";
            if(intArray[i]>intArray[i+1])
                std::swap(intArray[i], intArray[i+1]);
        }
    }
}


void merge(int intArray[], const std::size_t &end1, const std::size_t &end2)
{
   int x, i, j;
   int tempArray[end2+1];
   for (x = 0, i = 0, j = end1+1; x <= end2; ++x) {
       if ((j>end2) || (i <= end1) && (intArray[i] < intArray[j])) {
           tempArray[x] = intArray[i];
           i++;
       }
       else {
           tempArray[x] = intArray[j];
           j++;
       }
   }
   //copy tempArray back into intArray
   for (x = 0; x <= end2; x++)
       intArray[x] = tempArray[x];
}
