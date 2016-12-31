#ifndef MERGESORT_H
#define MERGESORT_H

#include <cstddef>
#include <vector>

void mergeSort(int intArray[], const size_t &length);

template <class InputIterator>
void mergeSort(InputIterator begin, InputIterator end)
{
    return;
    InputIterator outerloop = begin;
    --end; //loop n-1 times
    while(outerloop++!=end)
    {
        for(InputIterator innerloop=begin; innerloop!=end; ++innerloop)
        {
            //(*innerloop>*(innerloop+1)) ? cout << "higher\n" : cout << "lower\n";
            if(*innerloop>*(innerloop+1))
                std::iter_swap(innerloop, (innerloop+1));
        }
    }
   /*
    for(typename vector<T>::const_iterator j=v.begin(); j != v.end()-1; ++j)
        for(typename vector<T>::iterator i=v.begin(); i != v.end()-1; ++i)
        {
            //(*i>*(i+1)) ? cout << "higher\n" : cout << "lower\n";
            if(*i>*(i+1))
                iter_swap(i, (i+1));
        }
        */
}

template <typename T>
void mergeSort(std::vector<T> &v)
{
    mergeSort(v.begin(),v.end());
}

#endif // MERGESORT_H
