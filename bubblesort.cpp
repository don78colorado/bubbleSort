#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
  int c = a;
  a = b;
  b = c;
}

void printIntArray(const int intArray[], const size_t &length)
{
    cout << "sizeof(intArray): " << sizeof(intArray) << " sizeof(*intArray): " << sizeof(*intArray) << endl;
    for(size_t i = 0; i < length; i++)
	cout << intArray[i] << ", ";
    cout << endl;
}

void bubbleSort(int intArray[], const size_t &length)
{
    for(size_t j = 0; j < length-1; j++) 
    {
      for(size_t i = 0; i < length-1; i++)
      {
	  if(intArray[i]>intArray[i+1])
	      swap(intArray[i], intArray[i+1]);
      }
    }
}


int main(int argc, char *argv[])
{
    int testarray[] = { 5, 10, 60, 2, 1243, 2343, 12, 2354, 6654, 23, 1 } ;//c-style array
    const size_t testArrayLength = sizeof(testarray)/sizeof(*testarray);
    cout << "sizeof(testarray): " << sizeof(testarray) << " sizeof(*testarray): " << sizeof(*testarray) << endl;
    cout << "Original array:\n";
    printIntArray(testarray, testArrayLength);
    bubbleSort(testarray, testArrayLength);
    cout << "Bubblesorted array:\n";
    printIntArray(testarray, testArrayLength);
    return 0;
}

