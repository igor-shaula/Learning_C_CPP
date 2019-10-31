#include <iostream>
using namespace std;

struct Person // base
{
    Person(string name, int age) : name_(name), age_(age) {}

private:
    string name_;
    int age_;
};

struct Student : Person
{ // derivative
    Student(string name, int age, string university) : Person(name, age), university_(university) {}
    // constructor for base class has already been invoked before entering body of this constructor

private:
    // fields name_ and age_ of the base class will be on the very first place in memory for this object
    string university_;
};

// destructors are called in reverse order - first ~Student and then for its base class ~Person