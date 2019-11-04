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

struct BaseDevice
{
    // BaseDevice(void *data, size_t size) : data(data), size(size) {}
    void send(void *data, size_t size)
    {
        cout << "start sending" << endl;
        sendImpl(data, size);
        cout << "stop sending" << endl;
    }
    // virtual void sendPureV(void *data, size_t size) = 0;

private:
    // realization from here will never be used - derivatives must use their own sendImpl() /
    virtual void sendImpl(void *data, size_t size) { cout << "you should not see this"; }
    void *data;
    size_t size;
};

struct Router : BaseDevice
{
    // // undefined reference to `BaseDevice::sendPureV(void*, unsigned long)'
    // void sendPureV(void *data, size_t size)
    // {
    //     cout << "implementation works instead of base - that's correct!" << endl;
    //     cout << "sending data: " << *((int *)data) << " , size: " << size << endl;
    //     BaseDevice::sendPureV(data, size);
    // }

private:
    // main thing here - it's possible to OVERRIDE even PRIVATE method from base class /
    void sendImpl(void *data, size_t size)
    {
        cout << "implementation works instead of base - that's correct!" << endl;
        cout << "sending data: " << *((int *)data) << " , size: " << size << endl;
        // BaseDevice::send(data, size);
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

    int data = 42;
    int *ptr = &data;
    // BaseDevice *bd = new Router(ptr, 4);
    BaseDevice *bd = new Router();
    bd->send(ptr, 2);
    // bd->sendPureV(ptr, 4);
    delete bd;
    return 0;
}

/*
OOP style of inheritance allows to use link/pointer to base class for instance created by derived class /
classic OOP inheritance is in fact public inheritance - other types behave differently /
private & protected inheritance is better replaceable by agregation /
the only reason to use protected & private inheritance - ability to rewrite methods of base class /
*/

// interface - is an abstract class without fields and with all methods being abstract /
// all methods of interface are pure virtual - but destructor has to be real - for compilability /
// the only question is - what is pure virtual method with definition ? how is it possible ? /