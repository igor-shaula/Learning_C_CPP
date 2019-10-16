#include <iostream>

using namespace std;

int evaluateLogarithm(unsigned int limit)
{
    unsigned int l = 0;
    unsigned int candidate = 1;
    while (candidate <= limit)
    {
        // cout << "initial " << candidate << ' ';
        // candidate << 1;
        candidate *= 2;
        // cout << "after multiplication " << candidate << endl;
        l++;
        if (l > 9)
        {
            break;
        }
    }
    return l;
}

bool test_evaluateLogarithm()
{
    cout << "test_evaluateLogarithm" << endl;
    cout << "log2of0=" << evaluateLogarithm(0) << endl;
    cout << "log2of1=" << evaluateLogarithm(1) << endl;
    cout << "log2of2=" << evaluateLogarithm(2) << endl;
    cout << "log2of3=" << evaluateLogarithm(3) << endl;
    cout << "log2of4=" << evaluateLogarithm(4) << endl;
    cout << "log2of5=" << evaluateLogarithm(5) << endl;
    cout << "log2of6=" << evaluateLogarithm(6) << endl;
    cout << "log2of7=" << evaluateLogarithm(7) << endl;
    cout << "log2of8=" << evaluateLogarithm(8) << endl;
    cout << "log2of9=" << evaluateLogarithm(9) << endl;
    cout << "log2of10=" << evaluateLogarithm(10) << endl;
    cout << "log2of20=" << evaluateLogarithm(20) << endl;
    cout << "log2of30=" << evaluateLogarithm(30) << endl;
    cout << "log2of40=" << evaluateLogarithm(40) << endl;
    cout << "log2of50=" << evaluateLogarithm(50) << endl;
    cout << "log2of60=" << evaluateLogarithm(60) << endl;
    cout << "log2of70=" << evaluateLogarithm(70) << endl;
    cout << "log2of80=" << evaluateLogarithm(80) << endl;
    cout << "log2of90=" << evaluateLogarithm(90) << endl;
    cout << "log2of100=" << evaluateLogarithm(100) << endl;
    cout << "log2of1000000000=" << evaluateLogarithm(1000000000) << endl;
}

int main()
{
    // int t;
    // cin >> t;
    // int l = evaluateLogarithm(t);

    test_evaluateLogarithm();

    return 0;
}