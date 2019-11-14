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
        // SubString(char const c)
        // {
        //     innerStr = new char[2];
        //     innerStr[0] = c;
        //     innerStr[1] = '\0';
        // }
        SubString(MyString const &s)
        {
            innerSize = s.size;
            innerStr = s.str;
        }
        SubString(char const *given)
        {
            // cout << "started constructor of SubString" << endl;
            innerSize = myStrLen(given);
            // cout << "innerSize=" << innerSize << endl;
            innerStr = new char[innerSize + 1];
            for (size_t i = 0; i != innerSize; ++i)
                innerStr[i] = given[i];
            innerStr[innerSize] = '\0';
        }
        SubString(SubString const &ss) : innerSize(ss.innerSize), innerStr(ss.innerStr) {}
        ~SubString()
        {
            delete[] innerStr;
            innerSize = 0;
            shift = 0;
            // THE PROBLEM IS HERE - memory leak appear in Stepik test if this destructor is not set
        }
        SubString &operator=(SubString const &other)
        {
            if (this != &other) // to avoid unnecessary operations if we have the same instance
            {
                delete[] innerStr;
                innerSize = other.innerSize;
                innerStr = new char[innerSize + 1];
                for (size_t i = 0; i != innerSize; i++)
                    innerStr[i] = other.innerStr[i];
                innerStr[innerSize] = '\0';
            }
            return *this;
        }
        // standard getters //
        char *getInnerStr() const { return innerStr; }
        size_t getInnerSize() const { return innerSize; }
        int getShift() const { return shift; }
        // setters //
        char *&getInnerStr() { return innerStr; }
        size_t &getInnerSize() { return innerSize; }
        int &getShift() { return shift; }
        // we'll need this method right after its declaration //
        MyString const innerSubStringFrom(int const i) const // not including symbol by given index - 9
        {
            MyString msResult;
            cout << "\tGIVEN SubString:" << innerStr << ':' << innerSize << endl;
            msResult.size = i - shift; // one more for closing zero
            // cout << "msResult.size=" << msResult.size << endl;
            char *tmp = new char[msResult.size + 1]; // we need a reduced copy of given string
            // cout << "size of tmp = " << myStrLen(tmp) << endl;
            size_t j = 0;
            for (; j != msResult.size; ++j)
                tmp[j] = innerStr[j];
            tmp[j + 1] = '\0';
            msResult.str = tmp;
            cout << "\tCREATED MyString:" << msResult.str << ':' << msResult.size << endl;
            return msResult;
        }
        // creating content for second use of [] operator - it has to be MyString again //
        MyString const operator[](int const i) const
        {
            const MyString msResult = innerSubStringFrom(i);
            return msResult;
        }

    private:
        char *innerStr;
        size_t innerSize;
        int shift;
    }; // end of struct SubString

    MyString::SubString const subStringFrom(int const i) const
    {
        SubString ss;
        ss.getInnerSize() = size - i;              // subtracting number of symbols before given position
        ss.getInnerStr() = str + i * sizeof(char); // shifting pointer needed amount of steps forward
        ss.getShift() = i;
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

bool diffInSize(size_t givenSize, size_t rightSize) { return givenSize != rightSize; }

bool diffInContent(char *givenStrPtr, char const *rightStrPtr)
{
    bool diffIsFound = false;
    for (size_t i = 0; i != myStrLen(givenStrPtr); ++i)
        if (givenStrPtr[i] != rightStrPtr[i])
        {
            diffIsFound = true;
            break;
        }
    return diffIsFound;
}

void verify(MyString::SubString const &given, MyString::SubString const &right)
{
    /* 1 - comparing sizes */
    if (diffInSize(given.getInnerSize(), right.getInnerSize()))
    {
        cout << given.getInnerStr() << ':' << "FAILED because innerSize is wrong: " << given.getInnerSize() << endl;
        return;
    }
    /* 2 - comparing content */
    if (diffInContent(given.getInnerStr(), right.getInnerStr()))
    {
        cout << given.getInnerStr() << ':' << "FAILED because innerStr is wrong!" << endl;
        return;
    }
    /* 3 - if we've reached here - it seems that all is OK */
    cout << "OK_" << ':' << given.getInnerStr() << endl;
}

void verify(MyString const &givenMS, char const *right)
{
    if (diffInSize(givenMS.getSize(), myStrLen(right)))
    {
        cout << givenMS.getCharPtr() << ':' << "FAILED because size is wrong: " << givenMS.getSize() << endl;
        return;
    }
    if (diffInContent(givenMS.getCharPtr(), right))
    {
        cout << givenMS.getCharPtr() << ':' << "FAILED because str is wrong!" << endl;
        return;
    }
    cout << "OK_" << ':' << givenMS.getCharPtr() << endl;
}

int main()
{
    MyString const msResult("0123456789");

    /* checking is SubString is created correctly from first [] */
    MyString::SubString const ss0 = msResult[0];
    cout << "\tss0 created: " << ss0.getInnerStr() << endl;
    verify(ss0, "0123456789");
    MyString::SubString const ss1 = msResult[1];
    cout << "\tss1 created: " << ss1.getInnerStr() << endl;
    verify(ss1, "123456789");
    MyString::SubString const ss8 = msResult[8];
    cout << "\tss8 created: " << ss8.getInnerStr() << endl;
    verify(ss8, "89");
    MyString::SubString const ss9 = msResult[9];
    cout << "\tss9 created: " << ss9.getInnerStr() << endl;
    verify(ss9, "9");
    MyString::SubString const ss10 = msResult[10];
    cout << "\tss10 created: " << ss10.getInnerStr() << endl;
    verify(ss10, "");

    /* checking if MyString is created correctly from second [] */

    MyString const ms0_10 = msResult[0][10];
    cout << "\tms0_10 created: " << ms0_10.getCharPtr() << endl;
    verify(ms0_10, "0123456789");
    MyString const ms1_10 = msResult[1][10];
    cout << "\tms1_10 created: " << ms1_10.getCharPtr() << endl;
    verify(ms1_10, "123456789");
    MyString const ms0_9 = msResult[0][9];
    cout << "\tms0_9 created: " << ms0_9.getCharPtr() << endl;
    verify(ms0_9, "012345678");
    MyString const ms1_9 = msResult[1][9];
    cout << "\tms1_9 created: " << ms1_9.getCharPtr() << endl;
    verify(ms1_9, "12345678");

    MyString const hello("hello");
    MyString::SubString const s0 = hello[0];
    verify(s0, MyString("hello"));
    MyString::SubString const s1 = hello[1];
    verify(s1, MyString("ello"));
    MyString const hell = hello[0][4]; // теперь в hell хранится подстрока "hell"
    verify(hell, MyString("hell"));
    MyString const ell = hello[1][4]; // теперь в ell хранится подстрока "ell"
    verify(ell, MyString("ell"));
    MyString const el = hello[1][3];
    verify(el, MyString("el"));
    MyString const l = hello[2][3];
    verify(l, MyString("l"));

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