#include <iostream>
using namespace std;

char *resize(char *source, unsigned oldSize, unsigned newSize)
{
    char *result = new char[newSize];
    unsigned limit = oldSize < newSize ? oldSize : newSize;
    for (unsigned i = 0; i < limit; i++)
        *(result + i) = *(source + i);
    delete[] source;
    return result;
}

char *getLine()
{
    char *container = new char[0];
    char c;
    unsigned i = 0;
    do
    {
        container = resize(container, i, i + 1);
        cin.get(c);
        *(container + i) = c;
        cout << container << endl;
        i++;
    } while (c != '\n' || c != '\0' || c != '\t');
    *(container + i) = '\0';
    return container;
}

int main()
{
    char *s = getLine();
    cout << "result string: " << s << endl;
    delete[] s;
    return 0;
}