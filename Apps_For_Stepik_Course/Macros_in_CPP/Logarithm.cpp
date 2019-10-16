#include <iostream>

using namespace std;

int evaluateLogarithm(unsigned int limit)
{
    if (limit <= 0)
    {
        cout << "(number must be positive value)";
        return -1;
    }

    unsigned int logarithm = -1;
    unsigned int candidate = 1;
    while (candidate <= limit) // we'll have at least 1 iteration if limit is 1 & more if 2 or bigger
    {
        // cout << "initial " << candidate << ' ';
        candidate *= 2;
        // candidate << 1;
        logarithm++;
        // cout << "after multiplication " << candidate << endl;
    }
    return logarithm;
}

void test_evaluateLogarithm(unsigned int howManyTimes)
{
    if (howManyTimes <= 0)
    {
        cout << "invalid number of times";
    }
    unsigned int testData[] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

    cout << "test_evaluateLogarithm:" << endl;
    for (int i = 0; i < howManyTimes; i++)
    {
        cout << "log2of" << testData[i] << '=' << evaluateLogarithm(testData[i]) << endl;
    }
}

int main()
{
    int t;
    cin >> t;

    // test_evaluateLogarithm(t);

    if (t < 0)
    {
        cout << "count T cannot be lesser than 1";
        return 1;
    }

    unsigned int givenValues[t];
    for (int i = 0; i < t; i++)
    {
        cin >> givenValues[i];
    }

    for (int i = 0; i < t; i++)
    {
        cout << evaluateLogarithm(givenValues[i]) << endl;
    }

    return 0;
}