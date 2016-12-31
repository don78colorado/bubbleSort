#include "mergeSort.h"
#include <QtTest/QtTest>

class TestMergeSort: public QObject
{
    Q_OBJECT
private slots:
    void initTestCase()
    { qDebug("called before everything else"); }
    void arrayTest();
    void stdArrayTest();
    void vectorTest();
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

QTEST_MAIN(TestMergeSort)
#include "mergesorttest.moc"
