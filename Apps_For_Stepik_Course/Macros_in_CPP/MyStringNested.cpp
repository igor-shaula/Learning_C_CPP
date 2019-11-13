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

struct MyString
{
private:
    size_t size;
    char *str;

public:
    size_t getSize() const { return size; }
    virtual char *getCharPtr() const { return str; }
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
    MyString(const MyString &other) : size(other.size), str(new char[size + 1])
    {
        for (size_t i = 0; i != size; i++)
            str[i] = other.str[i];
        str[size] = '\0';
    }
    MyString &operator=(MyString const &other)
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
    // char operator[](int const i) const
    // {
    //     char c = (this->str)[i];
    //     return c;
    // }
    struct SubString
    {
        SubString() // default empty constructor is really needed here
        {
            innerSize = 0;
            innerStr = new char[1];
            innerStr[0] = '\0';
        };
        SubString(char const c)
        {
            innerStr = new char[2];
            innerStr[0] = c;
            innerStr[1] = '\0';
        }
        SubString(MyString const &s)
        {
            innerSize = s.size;
            innerStr = s.str;
        }
        // standard getters //
        char *getInnerStr() const { return innerStr; }
        size_t getInnerSize() const { return innerSize; }
        // setters //
        char *&getInnerStr() { return innerStr; }
        size_t &getInnerSize() { return innerSize; }
        // we'll need this method right after its declaration //
        MyString const subMyString(int const i) const
        {
            MyString ms;
            cout << "i=" << i << " innerSize=" << innerSize << "innerStr=" << innerStr << endl;
            ms.size = innerSize - i;
            // we need a reduced copy of given string //
            char *tmp = new char[ms.size];
            size_t j = 0;
            // size_t j = i - 1; // going from end to start
            for (; j != i - 1; j++)
                // for (; j >= 0; --j)
                tmp[j] = innerStr[j];
            tmp[j + 1] = '\0';
            ms.str = tmp;
            return MyString(ms.str);
        }
        // creating content for second use of [] operator - it has to be MyString again //
        MyString const operator[](int const i) const
        {
            const MyString ms = subMyString(i);
            return ms;
        }

    private:
        char *innerStr;
        size_t innerSize;
    }; // end of struct SubString

    MyString::SubString const subStringFrom(int const i) const
    {
        SubString ss;
        ss.getInnerSize() = size - i;              // subtracting number of symbols before given position
        ss.getInnerStr() = str + i * sizeof(char); // shifting pointer needed amount of steps forward
        return ss;
    }
    MyString::SubString const operator[](int const i) const
    {
        const SubString ss = subStringFrom(i);
        return ss;
    }
};

// void verify(char const given, char const right)
// {
//     cout << given << ':' << (given == right ? "OK" : "FAILED") << endl;
// }
void verify(MyString::SubString const &given, MyString::SubString const &right)
{
    cout << given.getInnerStr() << ':' << right.getInnerStr() << endl;
    // cout << given.getInnerStr() << ':' << (given.getInnerStr() == right.getInnerStr() ? "OK" : "FAILED") << endl;
}

int main()
{
    MyString const hello("hello");
    MyString::SubString const ss0 = hello[0];
    verify(ss0, MyString("hello"));
    MyString::SubString const ss1 = hello[1];
    verify(ss1, MyString("ello"));
    MyString const hell = hello[0][4]; // теперь в hell хранится подстрока "hell"
    verify(hell, MyString("hell"));
    MyString const ell = hello[1][4]; // теперь в ell хранится подстрока "ell"
    verify(ell, MyString("ell"));
    MyString const el = hello[1][3];
    verify(el, MyString("el"));
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