#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b)
{
    cout << "my swap(" << a << ", " << b << ")\n" ;
    int c = a;
    a = b;
    b = c;
}


    template <typename T>
void printVector(vector<T> v)
{
    cout << "printVector(vector<T> v):\n";
    cout << "array method:\n";
    for(int i=0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    cout << "iterator method:\n";
    for(typename vector<T>::iterator itr = v.begin(); itr!= v.end(); ++itr)
	cout << *itr << " ";
    cout << endl;
    cout << "for( : ) method\n";
    for(it: v)
	cout << it << " ";
    cout << endl;
}

    template <typename T>
void print(T t)
{
    cout << "print(T t):\n";
    cout << "array method:\n";
    for(int i=0; i < t.size(); i++)
        cout << t[i] << " ";
    cout << endl;
    cout << "iterator method:\n";
    for(typename T::iterator itr = t.begin(); itr!= t.end(); ++itr)
	cout << *itr << " ";
    cout << endl;
    cout << "for( : ) method\n";
    for (it: t)
	cout << it << " ";
    cout << endl;
}

void printIntVector(vector<int> v)
{
    printVector(v);
}

void printIntArray(const int intArray[], const size_t &length)
{
    cout << "sizeof(intArray): " << sizeof(intArray) << " sizeof(*intArray): " << sizeof(*intArray) << endl;
    for(size_t i = 0; i < length-1; i++)
	cout << intArray[i] << ", ";
    cout << intArray[length-1] << endl;
}

void bubbleSort(int intArray[], const size_t &length)
{
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


int main(int argc, char *argv[])
{
    int testarray[] = { 5, 10, 60, 2, 1243, 2343, 12, 2354, 6654, 23, 1 } ;//c-style array
    const size_t testArrayLength = sizeof(testarray)/sizeof(*testarray);
    vector<int> intVector(testarray, testarray+sizeof(testarray)/sizeof(testarray[0]));
    cout << "sizeof(testarray): " << sizeof(testarray) << " sizeof(*testarray): " << sizeof(*testarray) << endl;
    cout << endl;
    print(intVector);
    cout << endl;
    printVector(intVector);
    cout << endl;
    printIntVector(intVector);
    cout << endl;
    cout << "Original array:\n";
    printIntArray(testarray, testArrayLength);
    bubbleSort(testarray, testArrayLength);
    cout << "Bubblesorted array:\n";
    printIntArray(testarray, testArrayLength);
    return 0;
}

