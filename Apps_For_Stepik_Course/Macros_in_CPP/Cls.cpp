#include <iostream>
using namespace std;

struct Cls
{
    Cls(char c, double d, int i) : c(c), d(d), i(i) {}

    char &get_c(Cls &cls)
    {
        return cls.c;
    }

    double &get_d(Cls &cls)
    {
        return cls.d;
    }

    int &get_i(Cls &cls)
    {
        return cls.i;
    }

private:
    char c;
    double d;
    int i;
};

struct ClsAccessor
{
    // ...
};

int main()
{
    Cls *cls = new Cls('C', 1.2, -3);
    Cls &link = *cls;
    cout << cls->get_c(link) << ' ' << cls->get_d(link) << ' ' << cls->get_i(link) << endl;
    return 0;
}