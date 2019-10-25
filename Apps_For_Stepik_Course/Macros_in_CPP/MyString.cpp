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
    String(size_t n, char c)
    {
        size = n;
        str = new char[size + 1];
        for (size_t i = 0; i != n; i++)
            str[i] = c;
        str[size] = '\0';
    }
    ~String()
    {
        delete[] str;
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
    cout << "enter a symbol and number of repetiotions for this symbol: ";
    char c;
    size_t n;
    cin >> c >> n;
    cout << String(n, c).str << endl;
    return 0;
}