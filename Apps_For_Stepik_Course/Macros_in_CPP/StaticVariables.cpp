#include <iostream>
using namespace std;

int next(int start = 0) // default value -> the function can be invoked as next() and next(int)
{
    static int k = start; // will be initialized only ONCE - during the first invocation of next()
    return k++;
}

struct User
{
    User(string name = "") : name_(name) { counter_++; }
    ~User() { counter_--; }
    string getName() const { return name_; }
    string &getName() { return name_; }
    static size_t howMany() { return counter_; }
    static void initializeCounter() { counter_ = 10; }

public:
    static size_t pubStatic;

private:
    string name_;
    static size_t counter_; // if i try to initialize it here - it must become const
};

size_t User::pubStatic = 42;
size_t User::counter_;

int main()
{
    int result = next(10); // this value will be used for initialization of inner static variable
    cout << "1:" << result << endl;
    result = next(20); // this value will NOT affect anything - we could write next() instead
    cout << "2:" << result << endl;
    result = next(); // the same as previous invocation - no effect on inner static variable
    cout << "3:" << result << endl;

    // User::initializeCounter();

    // User::pubStatic = 10;
    User user1("A");
    User user2("B");
    cout << "created 2 users and checking inner static counter: " << User::pubStatic << endl;
    cout << "created 2 users and checking inner static counter: " << User::howMany() << endl;

    return 0;
}