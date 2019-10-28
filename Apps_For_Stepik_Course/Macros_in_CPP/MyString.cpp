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

    // another attempt:
    void effectiveConcat(char *to, const char *from)
    {
        for (; *to != '\0'; to++)
            ;
        for (; *from != '\0'; to++, from++)
            *to = *from;
        *to = '\0';
    }
    void appendManual(String &other)
    {
        // detect new size - it must not include final zero symbol:
        size += other.size;
        // trying to use previously written & accepted function for concatenation:
        effectiveConcat(str, other.str);
        // at the end we place the closing zero:
        str[size] = '\0';
    }

    // merged code from effectiveConcat into append:
    void append1(String &other)
    {
        // at first we have to save content of existing string somewhere:
        char *tmp = new char[size + 1];
        for (; *str != '\0'; str++, tmp++)
            *tmp = *str;
        tmp[size] = '\0';
        // now we can clean previous structure from the memory:
        delete[] str;
        // resetting the size to include new data from other string:
        size += other.size;

        str = new char[size + 1];
        // copying values from our tmp string into the new bigger one:
        for (; *tmp != '\0'; tmp++, str++)
            *str = *tmp;
        // cleaning memory from used tmp data:
        delete[] tmp;
        tmp = 0;
        // copying values from other string to found place:
        for (; *(other.str) != '\0'; (other.str)++, str++)
            *str = *(other.str);
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
    // h1.append(h2);
    h1.append1(h2);
    cout << h1.str << "\\size=" << h1.size << endl;
    return 0;
}