#include <iostream>
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy
using namespace std;

struct String
{
    unsigned size;
    char *str;
    String(const char *str = "")
    {
        size = strlen(str);
        this->str = new char[size + 1]; // because otherwize task is not accepted by Stepik
        strcpy(this->str, str);
        // this->str[size] = '\0'; // only after copying this line has its effect - but it's not needed!
    }
};

int main()
{
    // cout << "enter any string:" << endl;
    char *initialString = "initial";
    // cin >> initialString;
    String s = String(initialString);
    cout << s.str << endl;
    cout << strlen(initialString) << ' ' << strlen(s.str) << endl;
    // initialString[0] = 'I'; // avoiding of "Segmentation fault"
    s.str[0] = '_';
    cout << initialString << endl;
    cout << s.str << endl;
    return 0;
}