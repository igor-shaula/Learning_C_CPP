#include <iostream>
using namespace std;

int sLength(char *s)
{
    unsigned length = 0;
    for (; *s != 0; s++, length++)
        ;
    return length;
}

int search(char *where, char *what)
{
    int foundPosition = -1;
    for (unsigned i = 0; where != where + sLength(where); where++, i++)
        if (*where == *what)
        {
            foundPosition = i;
            cout << "found " << *what << " at position " << foundPosition << endl;
            for (; what != what + sLength(what); what++, where++)
                if (*what != *where)
                {
                    foundPosition = -1;
                    break;
                }
        }
    return foundPosition;
}

int main()
{
    // cout << "enter a string:" << endl;
    // cin >> ???
    char s[] = "test string";
    char t[] = "st";
    int foundPosition = search(s, t);
    cout << "first occurence of \"" << t << "\" found is at position: " << foundPosition << endl;

    return 0;
}