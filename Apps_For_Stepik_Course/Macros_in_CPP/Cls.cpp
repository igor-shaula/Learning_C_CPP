#include <iostream>
using namespace std;

struct Cls
{
    Cls(char c, double d, int i) : c(c), d(d), i(i) {}
    // there are no accessors here - obviously no way of getting inner fileds...
private:
    char c;
    double d;
    int i;
};

char &get_c(Cls &cls)
{
    char *c = (char *)&cls; // as char is on the first place - no shift is needed
    return *c;
}

double &get_d(Cls &cls)
{
    double *d = (double *)&cls + 1; // magic of aligning bytes - just next possible place after char
    return *d;
}

int &get_i(Cls &cls)
{
    int *i = (int *)&cls + 4; // 4 because double took 2 int places + it was aligned by 2 more as well
    return *i;
}

int main()
{
    Cls *cls = new Cls('C', 1.2, -3);
    cout << get_c(*cls) << ' ' << get_d(*cls) << ' ' << get_i(*cls) << endl;
    return 0;
}