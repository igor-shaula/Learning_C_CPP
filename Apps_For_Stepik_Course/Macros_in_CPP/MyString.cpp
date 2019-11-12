#include <iostream>
using namespace std;

// useful utils for upcoming tasks - decided to avoid using any given standard function //
size_t myStrLen(char const *const str)
{
    size_t length = 0;
    for (; *(str + length) != '\0'; length++)
        ; // shifting pointer forward & checking every next symbol until 0 value is found
    return length;
}
void myStrCopy(char *const dest, char const *const src, const size_t count)
// dest cannot be const as its content has to be changed during copying from src //
{
    for (size_t i = 0; i != count; i++)
        dest[i] = src[i];
    // dest[count] = '\0'; // decided that this has to be done in other place - may be after invocation
}

struct MyString
{
private:
    size_t size;
    char *str;

public:
    size_t getSize() const { return size; }
    char *getCharPtr() const { return str; }
    // solution for task 1 //
    MyString(char const *const givenPtr = "") // creating empty string by default - 'str' ptr is not const here
    {
        size = myStrLen(givenPtr);
        str = new char[size + 1]; // because otherwize task is not accepted by Stepik
        myStrCopy(str, givenPtr, size);
        str[size] = '\0';
    }
    // solution for task 2 //
    MyString(size_t const n, char const c) // filling newly created string with specific char
    {
        size = n;
        str = new char[size + 1];
        for (size_t i = 0; i != n; i++)
            str[i] = c;
        str[size] = '\0';
    }
    ~MyString()
    {
        delete[] str;
    }
    // solution for task 3 //
    void append(MyString &other)
    {
        /*
        before we append - we have to change size of array in dynamic memory /
        that can be done by allocating new region of needed size using 'new[]' operator
        before that we have to save existing content in current string
        and after that we can repoint 'str' to newly created memory region /
        in the end we have to copy 'tmp' into new array and than 'other' as well /
        */
        char *tmp = new char[size + 1];
        myStrCopy(tmp, str, size);
        tmp[size] = '\0';
        // now initial content is saved into tmp and we can allocate new memory and point 'str' on it //
        size_t initialSize = size; // we'll need it later to avoid excess counting of tmp's length
        size += other.size;        // only data without ending zeroes
        delete[] str;              // time to clean previously used memory
        str = new char[size + 1];  // this time "size" is bigger than previous
        myStrCopy(str, tmp, initialSize);
        myStrCopy(str, other.getCharPtr(), other.size);
        str[size] = '\0';
        delete[] tmp;
    }
    /*
    // another attempt:
    void effectiveConcat(char *to, const char *from)
    {
        for (; *to != '\0'; to++)
            ;
        for (; *from != '\0'; to++, from++)
            *to = *from;
        *to = '\0';
    }
    void appendManual(MyString &other)
    {
        // detect new size - it must not include final zero symbol:
        size += other.size;
        // trying to use previously written & accepted function for concatenation:
        effectiveConcat(str, other.str);
        // at the end we place the closing zero:
        str[size] = '\0';
    }

    // merged code from effectiveConcat into append:
    void append1(MyString &other)
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
*/
    // MyString(const MyString &other) : size(other.size), str(new char[size + 1])
    // {
    //     for (size_t i = 0; i != size; i++)
    //         str[i] = other.str[i];
    //     str[size] = '\0';
    // }

    // MyString &operator=(MyString const &other)
    // {
    //     if (this != &other)
    //     {
    //         delete[] str;
    //         size = other.size;
    //         str = new char[size + 1];
    //         for (size_t i = 0; i != size; i++)
    //             str[i] = other.str[i];
    //         str[size] = '\0';
    //     }
    //     return *this;
    // }
};

int main()
{
    // cout << "enter any string:" << endl;
    char *initialString = "initial";
    // cin >> initialString;
    MyString s = MyString(initialString);
    cout << s.getCharPtr() << endl;
    cout << myStrLen(initialString) << ' ' << myStrLen(s.getCharPtr()) << endl;
    // initialString[0] = 'I'; // avoiding of "Segmentation fault"
    s.getCharPtr()[0] = '_';
    cout << initialString << endl;
    cout << s.getCharPtr() << endl;
    cout << "enter a symbol and number of repetiotions for this symbol: ";
    char c;
    size_t n;
    cin >> c >> n;
    cout << MyString(n, c).getCharPtr() << endl;
    MyString h1("Hello");
    MyString h2(",World");
    h1.append(h2);
    MyString h3("SMTH");
    h1.append(h3);
    cout << h1.getCharPtr() << "\\size=" << h1.getSize() << endl;
    return 0;
}