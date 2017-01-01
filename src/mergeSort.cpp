#include "mergeSort.h"
#include <algorithm>
//#include <iostream>

void merge(std::vector<int>::iterator start, std::vector<int>::iterator end1,
           std::vector<int>::iterator end2)
{
    std::vector<int>::iterator x;
    std::vector<int>::const_iterator i, j;
    std::vector<int> tempVector;
    for (x = tempVector.begin(), i = start, j = end1+1; i <= end1 && j != end2 ; ) {
        //std::cout << "*i:" << *i << " *j:" << *j << " end1:" << *end1 << " end2:" << *end2 << std::endl;
        if ((j==end2 || i <= end1) && (*i < *j)) {
            tempVector.push_back(*i);
            i++;
        }
        else {
            tempVector.push_back(*j);
            j++;
        }
    }
    // copy remaining
    while (i <= end1) {
        tempVector.push_back(*i);
        i++;
    }
    while (j != end2) {
        tempVector.push_back(*j);
        j++;
    }
    std::copy(tempVector.begin(), tempVector.end(), start);
}

void mergeSort(int intArray[], const size_t &length)
{
    //std::cout << "mergeSort()\n";
    int i = 0;
    while (i < length && intArray[i] <= intArray[i+1]) {
        //std::cout << intArray[i] << std::endl;
        i++;
    }
    //std::cout << intArray[i] << std::endl;
    if (i == length)
        return; // array is sorted
    // otherwise i is index of last sorted element
    // sort the rest of the array, then merge
    mergeSort(intArray+i+1, length-i-1);
    merge(intArray, i, length-1);
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

/*
void mergeSort(std::vector<int> &v)
{
    //mergeSort(v.begin(),v.end());
    //std::cout << "mergeSort()\n";
    typename std::vector<int>::iterator i = v.begin();
    while (i != v.end() && *i < *(i+1)) {
        ++i;
    }
    if (i == v.end())
        return;
    mergeSort(i+1, v.end());
    merge(v, i);
}
*/

/*
void mergeSort(typename std::vector<int>::iterator start, typename std::vector<int>::iterator finish)
{
    typename std::vector<int>::iterator i = start;
    while (i != finish && *i < *(i+1)) {
        ++i;
    }
    if (i == finish)
        return;
    mergeSort(i+1, finish);
    merge(start, i, finish);
}
*/
