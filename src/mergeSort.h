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

void merge(std::vector<int>::iterator start, std::vector<int>::iterator end1,
           std::vector<int>::iterator end2);

template <typename Container>
void merge(Container &v, typename Container::const_iterator end1)
{
    typename Container::const_iterator end2 = v.end();
    typename Container::iterator x;
    typename Container::const_iterator i, j;
    Container tempContainer;
    for (x = tempContainer.begin(), i = v.begin(), j = end1+1; i <= end1 && j != end2 ; ) {
        //std::cout << "*i:" << *i << " *j:" << *j << " end1:" << *end1 << " end2:" << *end2 << std::endl;
        if ((j==end2 || i <= end1) && (*i < *j)) {
            tempContainer.push_back(*i);
            i++;
        }
        else {
            tempContainer.push_back(*j);
            j++;
        }
    }
    // copy remaining
    while (i <= end1) {
        tempContainer.push_back(*i);
        i++;
    }
    while (j != end2) {
        tempContainer.push_back(*j);
        j++;
    }
    std::copy(tempContainer.begin(), tempContainer.end(), v.begin());
}

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
    const InputIterator stop = end-1;
    while (i != stop && *i < *(i+1)) {
        ++i;
    }
    if (i == stop)
        return;
    mergeSort(i+1, end);
    merge(begin, i, end);
}

template <typename Container>
void mergeSort(Container &c)
{
    typename Container::iterator i = c.begin();
    while (i != c.end() && *i < *(i+1)) {
        ++i;
    }
    if (i == c.end())
        return;
    mergeSort(i+1, c.end());
    merge(c, i);
}

#endif // MERGESORT_H
