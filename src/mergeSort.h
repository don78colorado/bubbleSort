#ifndef MERGESORT_H
#define MERGESORT_H

#include <cstddef>
#include <vector>
//#include <iostream>

/* merges two parts of an array
 * elements [0,end1] must be sorted
 * elements (end1,end2] must be sorted
 * after function call, intArray will be sorted
 */
void merge(int intArray[], const std::size_t &end1, const std::size_t &end2);
void mergeSort(int intArray[], const size_t &length);
//void mergeSort(std::vector<int> &v);
//void mergeSort(typename std::vector<int>::iterator start, typename std::vector<int>::iterator finish);

void merge(std::vector<int>::iterator start, std::vector<int>::iterator end1,
           std::vector<int>::iterator end2);

/*
template <typename T>
void merge(T &v, typename T::const_iterator end1)
{
    typename T::const_iterator end2 = v.end();
    typename T::iterator x;
    typename T::const_iterator i, j;
    T tempVector;
    for (x = tempVector.begin(), i = v.begin(), j = end1+1; i <= end1 && j != end2 ; ) {
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
    std::copy(tempVector.begin(), tempVector.end(), v.begin());
}
*/

/*
template <class InputIterator>
void merge(InputIterator begin, InputIterator end1, InputIterator end2) {
    return;
}
*/

template <class InputIterator>
void mergeSort(InputIterator begin, InputIterator end)
{
    InputIterator i = begin;
    while (i != end && *i < *(i+1)) {
        ++i;
    }
    if (i == end)
        return;
    mergeSort(i+1, end);
    merge(begin, i, end);
}

template <typename T>
void mergeSort(std::vector<T> &v)
{
    mergeSort(v.begin(),v.end());
}

#endif // MERGESORT_H
