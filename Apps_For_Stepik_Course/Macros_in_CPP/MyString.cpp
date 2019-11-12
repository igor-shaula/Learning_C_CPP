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
void myStrAdd(char *const dest, char const *const src, size_t const count)
// 'dest' value cannot be const as its content has to be changed during copying from 'src' //
{
    // 0 - we'll need to find amount of shift - as we add data - not rewrite initial content //
    size_t shift = 0;
    char *destBeginPtr = dest; // temporary variable - as 'dest' is const - so we need similar var ptr
    // 1 - we have to shift destination pointer to string's ending - first occurance of '\0' //
    for (; *destBeginPtr != '\0'; destBeginPtr++)
        ++shift;      // we'll have the number of symbols in initial 'dest' - not counting the last '\0'
    destBeginPtr = 0; // that's a paranoic action
    // 2 - now adding data from 'src' to 'dest' //
    for (size_t i = 0; i != count; i++)
        dest[i + shift] = src[i];
    dest[count + shift] = '\0'; // decided to complete string preparation here
}

struct MyString
{
private:
    size_t size;
    char *str;

public:
    // solution for task 1 //
    MyString(char const *const givenPtr = "") // creating empty string by default - 'str' ptr is not const here
    {
        size = myStrLen(givenPtr);
        str = new char[size + 1]; // because otherwize task is not accepted by Stepik
        myStrAdd(str, givenPtr, size);
        // str[size] = '\0';
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
        size = 0;
    }
    // solution for task 3 //
    void append(MyString &other)
    {
        /*
        before appending we have to change size of array in dynamic memory /
        that can be done by allocating new region of needed size using 'new[]' operator
        before that we have to save existing content in current string
        and after saving we can repoint 'str' to newly created memory region /
        in the end we have to copy 'tmp' and than 'other' into new array 'src' /
        */
        char *tmp = new char[size + 1];
        tmp[0] = '\0';
        myStrAdd(tmp, str, size);
        // tmp[size] = '\0';
        // now initial content is saved into tmp and we can allocate new memory and point 'str' on it //
        size_t initialSize = size; // we'll need it later to avoid excess counting of tmp's length
        size += other.size;        // only data without ending zeroes
        delete[] str;              // time to clean previously used memory
        str = new char[size + 1];  // this time "size" is bigger than previous
        str[0] = '\0';
        myStrAdd(str, tmp, initialSize);
        myStrAdd(str, other.str, other.size);
        // str[size] = '\0';
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
    size_t getSize() const { return size; }
    char *getCharPtr() const { return str; }
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
    h1.append(h1);
    // MyString h2(",World");
    // h1.append(h2);
    // MyString h3("SMTH");
    // h1.append(h3);
    cout << h1.getCharPtr() << "\\size=" << h1.getSize() << endl;
    h1.append(h1);
    cout << h1.getCharPtr() << "\\size=" << h1.getSize() << endl;
    return 0;
}