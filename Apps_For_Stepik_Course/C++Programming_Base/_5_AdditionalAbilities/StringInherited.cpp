#include <iostream>
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy
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

struct SubString2;

struct String
{
private:
    size_t size;
    char *str;

public:
    size_t getSize() const { return size; }
    virtual char *getCharPtr() const { return str; }
    // solution for task 1 //
    String(char const *const givenPtr = "") // creating empty string by default - 'str' ptr is not const here
    {
        size = myStrLen(givenPtr);
        str = new char[size + 1]; // because otherwize task is not accepted by Stepik
        myStrAdd(str, givenPtr, size);
        // str[size] = '\0';
    }
    // solution for task 2 //
    String(size_t const n, char const c) // filling newly created string with specific char
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
        size = 0;
    }
    // solution for task 3 //
    void append(String &other)
    {
        /*
        before appending we have to change size of array in dynamic memory /
        that can be done by allocating new region of needed size using 'new[]' operator
        before that we have to save existing content in current string
        and after saving we can repoint 'str' to newly created memory region /
        in the end we have to copy 'tmp' and than 'other' into new array 'src' /
        one more thing - we need second 'tmp' container for 'other' instance -
        in case when we add string to itself - 'this' and 'other' are in fact the same //
        */
        char *tmp = new char[size + 1];
        tmp[0] = '\0';
        myStrAdd(tmp, str, size);
        char *tmpOther = new char[other.size + 1];
        tmpOther[0] = '\0';
        myStrAdd(tmpOther, other.str, other.size);
        // now initial content is saved into tmps and we can allocate new memory and point 'str' on it //
        delete[] str;                         // time to clean previously used memory
        size_t initialSizeThis = size;        // we'll need it later to avoid excess counting of tmp's length
        size_t initialSizeOther = other.size; // needed for case when we add string to itself
        size += initialSizeOther;             // only data without ending zeroes
        str = new char[size + 1];             // this time "size" is bigger than previous
        str[0] = '\0';
        myStrAdd(str, tmp, initialSizeThis);
        delete[] tmp;
        myStrAdd(str, tmpOther, initialSizeOther);
        delete[] tmpOther;
    }
    // ADDITIONS FROM LECTURES :
    String(const String &other) : size(other.size), str(new char[size + 1])
    {
        for (size_t i = 0; i != size; i++)
            str[i] = other.str[i];
        str[size] = '\0';
    }
    String &operator=(String const &other)
    {
        if (this != &other) // to avoid unnecessary operations if we have the same instance
        {
            delete[] str;
            size = other.size;
            str = new char[size + 1];
            for (size_t i = 0; i != size; i++)
                str[i] = other.str[i];
            str[size] = '\0';
        }
        return *this;
    }

    SubString2 any();

    // char operator[](int const i) const
    // {
    //     char c = (this->str)[i];
    //     return c;
    // }
    struct SubString
    {
        SubString(char const c)
        {
            innerStr = new char[2];
            innerStr[0] = c;
            innerStr[1] = '\0';
        }
        char *getInnerStr() const { return innerStr; }
        size_t getInnerSize() const { return innerSize; }

    private:
        char *innerStr;
        size_t innerSize;
    };
    String::SubString subStringFrom(int const i) const
    {
        return SubString((this->str)[i]);
    }
    String::SubString const operator[](int const i) const
    {
        const SubString ss = subStringFrom(i);
        return ss;
    }
};

struct SubString2 : String
{
};

SubString2 String::any()
{
    cout << "OKKKK" << endl;
    return SubString2();
}

struct B;

struct A
{
    B any();
};

struct B : A
{
};

void verify(char const given, char const right)
{
    cout << given << ':' << (given == right ? "OK" : "FAILED") << endl;
}
void verify(String::SubString const &given, String::SubString const &right)
{
    cout << given.getInnerStr() << ':' << right.getInnerStr() << endl;
    // cout << given.getInnerStr() << ':' << (given.getInnerStr() == right.getInnerStr() ? "OK" : "FAILED") << endl;
}

int main()
{
    String const hello("hello");
    String::SubString const ss = hello[0];
    verify(ss, 'h');
    // MyString const hell = hello[0][4]; // теперь в hell хранится подстрока "hell"
    // MyString const ell = hello[1][4];  // теперь в ell хранится подстрока "ell"
    /*
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
    h1.append(h1);
    h1.append(h1);
    cout << h1.getCharPtr() << "\\size=" << h1.getSize() << endl;
*/
    return 0;
}