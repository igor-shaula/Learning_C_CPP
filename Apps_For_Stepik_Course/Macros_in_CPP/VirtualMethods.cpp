#include <iostream>
using namespace std;

struct Person
{
    Person(string s) : name_(s) {}
    virtual string name() const { return name_; } // 'virtual' makes compiler to use method from derivative

private:
    string name_;
};

struct Professor : Person
{
    Professor(string s) : Person(s) {}
    string name() const { return "Prof. " + Person::name(); }
};

int main()
{
    Professor pr("Stroustrup");
    cout << pr.name() << endl;
    Person *p = &pr;
    cout << p->name() << endl; // without 'virtual' name() from base class would be used here
    return 0;
}