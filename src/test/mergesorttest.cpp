#include "mergeSort.h"
#include <QtTest/QtTest>
#include "util.h"

class TestMergeSort: public QObject
{
    Q_OBJECT
private slots:
    void initTestCase()
    { qDebug("called before everything else"); }
    void arrayTest();
    void mergeTest();
    void stdArrayTest();
    void vectorTest();
    void mergeVectorTest();
    void cleanupTestCase()
    { qDebug("called after all tests"); }
};



void TestMergeSort::arrayTest()
{
    int testarray[] = {5, 10, 60, 2, 1243, 2343, 12, 2354, 6654, 23, 1};
    int sortedArray[] = {1, 2, 5, 10, 12, 23, 60, 1243, 2343, 2354, 6654};
    const std::size_t testArrayLength = sizeof(testarray)/sizeof(*testarray);
    mergeSort(testarray, testArrayLength);
    QVERIFY(std::equal(testarray, testarray+testArrayLength, sortedArray));
}

void TestMergeSort::mergeTest()
{
    int testarray[] = {0,3,11,50,3,6,7,49,81};
    int sortedArray[] = {0,3,3,6,7,11,49,50,81};
    const std::size_t testArrayLength = sizeof(testarray)/sizeof(*testarray);
    merge(testarray, 3, testArrayLength-1);
    QVERIFY(std::equal(testarray, testarray+testArrayLength, sortedArray));

    for (int i = 0; i < 5; ++i) {  // repeat 5 times
    // creat two sorted std::vectors of length 10, combine them into an array and test merge on it
    const std::size_t randomVectorLength = 10;
    const int maxRandomNumber = 100;
    std::vector<int> randomVector1;
    std::generate_n(std::back_insert_iterator<std::vector<int>>(randomVector1),
               randomVectorLength, []() { return rand()%(maxRandomNumber+1); });
    std::vector<int> randomVector2;
    std::generate_n(std::back_insert_iterator<std::vector<int>>(randomVector2),
               randomVectorLength, []() { return rand()%(maxRandomNumber+1); });
    std::sort(randomVector1.begin(), randomVector1.end());
    std::sort(randomVector2.begin(), randomVector2.end());
    randomVector1.insert(randomVector1.end(), randomVector2.begin(), randomVector2.end());
    int testarray2[randomVectorLength*2];
    std::copy(randomVector1.begin(), randomVector1.end(), testarray2);
    printIntArray(testarray2, randomVectorLength*2);
    QVERIFY(!std::is_sorted(testarray2, testarray2+randomVectorLength*2));
    merge(testarray2, randomVectorLength-1, randomVectorLength*2-1);
    QVERIFY(std::is_sorted(testarray2, testarray2+randomVectorLength*2));
    }
}

void TestMergeSort::stdArrayTest()
{
    std::array<int, 11> testarray {5, 10, 60, 2, 1243, 2343, 12, 2354, 6654, 23, 1};
    std::array<int, 11> sortedarray {1, 2, 5, 10, 12, 23, 60, 1243, 2343, 2354, 6654};
    mergeSort(testarray.begin(), testarray.end());
    QCOMPARE(testarray, sortedarray);
}

void TestMergeSort::vectorTest()
{
    int testarray[] = {5, 10, 60, 2, 1243, 2343, 12, 2354, 6654, 23, 1};
    std::vector<int> intVector(testarray, testarray+sizeof(testarray)/sizeof(testarray[0]));
    std::vector<int> sortedVector{1, 2, 5, 10, 12, 23, 60, 1243, 2343, 2354, 6654};
    mergeSort(intVector);
    QCOMPARE(intVector,sortedVector);

    const std::size_t randomVectorLength = 10;
    const int maxRandomNumber = 100;
    std::vector<int> randomVector;
    do {
        std::generate_n(std::back_insert_iterator<std::vector<int>>(randomVector),
               randomVectorLength, []() { return rand()%(maxRandomNumber+1); });
    } while (std::is_sorted(randomVector.begin(), randomVector.end()));
    QVERIFY(!std::is_sorted(randomVector.begin(), randomVector.end()));
    mergeSort(randomVector.begin(), randomVector.end());
    QVERIFY(std::is_sorted(randomVector.begin(), randomVector.end()));
}

void TestMergeSort::mergeVectorTest()
{
    int testarray[] = {0,3,11,50,3,6,7,49,81};
    std::vector<int> intVector(testarray, testarray+sizeof(testarray)/sizeof(testarray[0]));
    std::vector<int>::iterator end1 = intVector.begin();
    end1 = end1 + 3;
    merge(intVector, end1, intVector.end());
    QVERIFY(std::is_sorted(intVector.begin(), intVector.end()));

    for (int i = 0; i < 5; ++i) {  // repeat 5 times
    // creat two sorted std::vectors of length 10, combine them into an array and test merge on it
    const std::size_t randomVectorLength = 10;
    const int maxRandomNumber = 100;
    std::vector<int> randomVector1;
    std::generate_n(std::back_insert_iterator<std::vector<int>>(randomVector1),
               randomVectorLength, []() { return rand()%(maxRandomNumber+1); });
    std::vector<int> randomVector2;
    std::generate_n(std::back_insert_iterator<std::vector<int>>(randomVector2),
               randomVectorLength, []() { return rand()%(maxRandomNumber+1); });
    std::sort(randomVector1.begin(), randomVector1.end());
    std::vector<int>::iterator end1 = randomVector1.end();
    std::sort(randomVector2.begin(), randomVector2.end());
    randomVector1.insert(randomVector1.end(), randomVector2.begin(), randomVector2.end());
    print(randomVector1.begin(), randomVector1.end());
    QVERIFY(!std::is_sorted(randomVector1.begin(), randomVector1.end()));
    merge(randomVector1, randomVector1.begin() + randomVectorLength -1, randomVector1.end());
    QVERIFY(std::is_sorted(randomVector1.begin(), randomVector1.end()));
    }
}

QTEST_MAIN(TestMergeSort)
#include "mergesorttest.moc"
