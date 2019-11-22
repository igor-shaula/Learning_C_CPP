#include "Singleton.hpp"
#include "iostream"

using namespace std;

void testSingleton();

int main() {
    testSingleton();
    return 0;
}

void testSingleton() {
    Singleton &s1 = Singleton::instance(); // impossible to use without (&) reference
    string data = s1.data() = "first";
    cout << "data from s1 singleton: " << data << endl;
    Singleton &s2 = Singleton::instance();
    cout << "data from s2 singleton: " << s2.data() << endl;
    Singleton &s3 = Singleton::instance().instance(); // omit access the static via instance
    cout << "data from s3 singleton: " << s3.data() << endl;
    s1.data() = "changed";
    cout << "changed data from s1 singleton: " << s1.data() << endl;
    cout << "changed data from s2 singleton: " << s2.data() << endl;
    cout << "changed data from s3 singleton: " << s2.data() << endl;
}