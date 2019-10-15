#include <iostream>
using namespace std;

int main()
{
    char c = '\0';
    bool noticed = false;
    while (cin.get(c))
    {
        if (c == ' ')
        {
            if (noticed)
            {
                continue;
            }
            cout << c;
            noticed = true;
        }
        else if (c != '\t' && c != '\n' && c != '\0') // space excluded previously
        {
            cout << c;
            noticed = false;
        }
        else if (c != '\0') // it means: c == n OR t
        {
            cout << ' ';
        }
        else // endl
        {
            cout << endl;
            return 0;
        }
    }

    return 0;
}