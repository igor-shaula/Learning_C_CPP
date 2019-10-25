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
    void append(String &other)
    {
        cout << str << "\\size: " << size << endl;
        cout << other.str << "\\size: " << other.size << endl;
        char *tmp = new char[size];
        size += other.size;
        cout << "new size: " << size << endl;
        // char *tmp = str;
        strcpy(tmp, str);
        delete[] str;
        str = new char[size + 1]; // this time "size" is bigger than previous
        // str[0] = '\0';
        strcat(str, tmp);
        delete[] tmp;
        strcat(str, other.str);
        // strcpy(str + strlen(tmp), other.str);
        str[size] = '\0';
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
    String h1("Hello");
    String h2(",World");
    h1.append(h2);
    cout << h1.str << "\\size=" << h1.size << endl;
    return 0;
}