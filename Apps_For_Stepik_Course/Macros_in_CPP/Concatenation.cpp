#include <iostream>
using namespace std;

void concatenate(char *to, const char *from)
{
    unsigned s1Length = 0;
    for (; *to != '\0'; to++, s1Length++)
        ;
    unsigned s2Length = 0;
    for (; *from != '\0'; to++, from++, s2Length++)
        *to = *from;
    *(to + s1Length + s2Length - 1) = '\0';
}

unsigned strlen(const char *str)
{
    unsigned length = 0;
    for (; *str != '\0'; str++)
        length++;
    return length;
}

int main()
{
    char to[] = "a23";
    char from[] = "b56";
    concatenate(to, from);
    cout << *(to + 0) << endl;
    cout << *(to + 1) << endl;
    cout << *(to + 2) << endl;
    cout << *(to + 3) << endl;
    cout << *(to + 4) << endl;
    cout << *(to + 5) << endl;
    cout << *(to + 6) << endl;
    cout << *(to + 7) << endl;
    cout << "string length after concatenation: " << strlen(to) << endl;

    return 0;
}