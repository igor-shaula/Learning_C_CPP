#include <iostream>
using namespace std;

struct Person // when base class has virtual method with zerod body - it becomes abstract class
{
    // Person(string s) : name_(s) {} // this constructor is the older one

    Person(string const &name, int age) : name_(name), age_(age) {}

    virtual ~Person() {} // obligatory thing for avoiding memory leaks from using polymorphism

    virtual string name() const { return name_; } // 'virtual' makes compiler to use method from derivative
    // from now exact method address now depends on type of derivative, on which the method is called
    virtual string occupation() const = 0; // that means: use method's body only from derivative
private:
    string name_;
    int age_;
};

struct Teacher : Person
{
    Teacher(string const &nameIn, int age, string const &course)
        : Person(nameIn, age), course_(course)
    {
        cout << name() << endl; // virtual method in constructors & destructor behave like real methods there
    }

    string occupation() { return "teacher"; }
    virtual string course() { return course_; }
    // this method will be present in virtual methods table of class Professor
private:
    string course_;
};

struct Professor : Teacher
{
    Professor(string const &nameIn, int age, string const &course, string const &thesis)
        : Teacher(nameIn, age, course), thesis_(thesis) {}
    string name() const { return "Prof. " + Person::name(); }
    string occupation() const { return "professor"; }
    string thesis() const { return thesis_; }
    // method course() is not overriden - so we'll use its base realization from class Teacher
private:
    string thesis_;
};

struct Student : Person
{
    Student(string const &nameIn, int age, string const &university)
        : Person(nameIn, age), university_(university) {}
    string occupation() const { return "student"; }
    string university() { return university_; }

private:
    string university_;
};

int main()
{
    Professor pr("Stroustrup", 63, "C++", "The C++ language");
    cout << pr.name() << endl;
    Person *p = &pr;
    cout << p->name() << endl; // without 'virtual' name() from base class would be used here
    // the same scheme will work with using link instead of pointer

    Person *s = new Student("Alex", 23, "Oxford"); // ptr s points to region in dynamic memory
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