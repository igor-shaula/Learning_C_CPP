#include <iostream>
using namespace std;

struct Base
{
    Base(int pub, int prot, int priv) : pub(pub), prot(prot), priv(priv) {} //
public:
    int pub = 1; //
protected:
    int prot = 2; //
private:
    int priv = 3;
};

struct ChildPublic : public Base
{
    ChildPublic(int pub, int prot, int priv) : Base(pub, prot, priv) {}
    void useBase() { cout << Base::pub << Base::prot << endl; } // Base::priv is inaccessible
};

struct ChildProtected : protected Base
{
    ChildProtected(int pub, int prot, int priv) : Base(pub, prot, priv) {}
    void useBase() { cout << Base::pub << Base::prot << endl; } // Base::priv is inaccessible
};

struct ChildPrivate : private Base // only this class knows about Base - not its derivatives
{
    ChildPrivate(int pub, int prot, int priv) : Base(pub, prot, priv) {}
    void useBase() { cout << Base::pub << Base::prot << endl; } // Base::priv is inaccessible
};

struct SecondChildPublic : public ChildPublic
{
    SecondChildPublic(int pub, int prot, int priv) : ChildPublic(pub, prot, priv) {}
    void useBase() { cout << Base::pub << Base::prot << endl; } // Base::priv is inaccessible
};

struct SecondChildProtected : protected ChildProtected
{
    SecondChildProtected(int pub, int prot, int priv) : ChildProtected(pub, prot, priv) {}
    void useBase() { cout << Base::pub << Base::prot << endl; } // Base::priv is inaccessible
};

struct SecondChildPrivate : private ChildPrivate
{
    SecondChildPrivate(int pub, int prot, int priv) : ChildPrivate(pub, prot, priv) {}
    void useBase()
    {
        // cout << Base::pub << Base::prot << endl; // type Base is inaccessible even here!
    }
};

int main()
{
    // that's why real OOP-style use works only with public inheritance:
    Base *cpub = new ChildPublic(1, 2, 3);
    // Base *cprot = new ChildProtected(1, 2, 3); // inaccessible base class Base
    // Base *cpiv = new ChildPrivate(1, 2, 3);    // inaccessible base class Base
    Base *scpub = new SecondChildPublic(1, 2, 3);
    // Base *scprot = new SecondChildProtected(1, 2, 3); // inaccessible base class ChildProtected
    // Base *scpiv = new SecondChildPrivate(1, 2, 3);    // inaccessible base class ChildPrivate
    delete cpub, scpub;
    return 0;
}

/*
OOP style of inheritance allows to use link/pointer to base class for instance created by derived class /
classic OOP inheritance is in fact public inheritance - other types behave differently /
private & protected inheritance is better replaceable by agregation /
the only reason to use protected & private inheritance - ability to rewrite methods of base class /
*/