#include <iostream>
using namespace std;

struct Person // base
{
    Person(string name, int age) : name_(name), age_(age) {}
    // if we did explicit copying constructor -> code like 'Person p = s;' would be impossible

    string name() const { return name_; }
    int age() const { return age_; }

private:
    string name_;
    int age_;
};

struct Student : Person
{ // derivative
    Student(string name, int age, string university) : Person(name, age), university_(university) {}
    // constructor for base class has already been invoked before entering body of this constructor

    string university() const { return university_; }

private:
    // fields name_ and age_ of the base class will be on the very first place in memory for this object
    string university_;
};

// destructors are called in reverse order - first ~Student and then for its base class ~Person

// code for passing test:
struct Foo
{
    void say() const { cout << "Foo says: " << msg << endl; }

protected:
    Foo(const char *msg) : msg(msg) {}

private:
    const char *msg;
};

void fooSays(const Foo &foo) { foo.say(); }
// we have to get instance of foo somehow for this function to work - of course via its derivative!
struct FooChild : Foo
{
    FooChild(char const *msg) : Foo(msg) {}
};
// now comes the main point of interest in given test:
const FooChild get_foo(const char *msg)
{
    return FooChild(msg);
}

int main()
{
    Student s("Alex", 21, "Oxford");
    cout << s.name() << s.age() << s.university() << endl; // note that methods here can be used without brackets!!!
    Person &l = s;                                         // casting link of derivative to base class: Student & -> Person &
    Person *r = &s;                                        // casting pointer to derivative to its base clas: Student * -> Person *
    // reverse casting (from base to parent) is impossible
    Person p = s; // only fields from parent class will be copied here - university_ will be lost
    // in fact copying costructor Person(Person const &p) is invoked in the line before

    char *msg = new char[4];
    msg[0] = 't';
    string S = "test";
    // msg = "test";
    cout << "string ready" << endl;
    FooChild fc1(S.c_str());
    cout << "constructor 1 worked" << endl;
    FooChild fc2 = FooChild(S.c_str());
    cout << "constructor 2 worked" << endl;
    FooChild fc3 = get_foo(S.c_str());
    cout << "constructor 3 worked" << endl;
    fooSays(get_foo(S.c_str()));
    // delete[] msg;
    // delete &fc3;
    return 0;
}