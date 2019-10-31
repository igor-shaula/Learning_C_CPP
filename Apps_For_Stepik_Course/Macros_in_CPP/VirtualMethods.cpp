#include <iostream>
using namespace std;

struct Person // when base class has virtual method with zerod body - it becomes abstract class
{
    Person(string s) : name_(s) {}

    virtual ~Person() {} // obligatory thing for avoiding memory leaks from using polymorphism

    virtual string name() const { return name_; } // 'virtual' makes compiler to use method from derivative
    // from now exact method address now depends on type of derivative, on which the method is called
    virtual string occupation() const = 0; // that means: use method's body only from derivative
private:
    string name_;
};

struct Professor : Person
{
    Professor(string s) : Person(s) {}
    string name() const { return "Prof. " + Person::name(); }
    string occupation() const { return "professor"; }
};

struct Student : Person
{
    Student(string s, string university) : Person(s), university_(university) {}
    string occupation() const { return "professor"; }

private:
    string university_;
};

int main()
{
    Professor pr("Stroustrup");
    cout << pr.name() << endl;
    Person *p = &pr;
    cout << p->name() << endl; // without 'virtual' name() from base class would be used here
    // the same scheme will work with using link instead of pointer

    Person *s = new Student("Alex", "Oxford"); // ptr s points to region in dynamic memory
    // ... working with s ...
    delete s; // as we have virtual destructor in base class - at first ~Student() is called, and then ~Person
    return 0;
}
/*
what is polymorphism ? -> ability to work with different data types in one style ..

OVERLOADING - is a static form of polymorphism - it's done during compilation time ..

OVERRIDING / VIRTUAL METHODS - form of dynamic polymorphism - choosing a method works durin execution time ..
dynamic polymorphism is the one of three OOP main concepts/ideas which are often asked ..
*/