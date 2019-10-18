#include <iostream>
using namespace std;

void concatenate(char *to, const char *from)
{
    unsigned s1Length = 0;
    for (; *to != '\0'; to++, s1Length++)
        ;
    unsigned s2Length = 0;
    for (; *from != '\0'; to++, from++, s2Length++) // "to" continues to grow - its value has been already changed by previous loop
        *to = *from;
    // cout << "s1Length: " << s1Length << endl;
    // cout << "s2Length: " << s2Length << endl;
    *to = '\0';
}

void effectiveConcat(char *to, const char *from)
{
    for (; *to != '\0'; to++)
        ;
    for (; *from != '\0'; to++, from++)
        *to = *from;
    *to = '\0';
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
    cout << "string before after concatenation: " << strlen(to) << endl;
    effectiveConcat(to, from);
    cout << "string length after concatenation: " << strlen(to) << endl;
    cout << *(to + 0);
    cout << *(to + 1);
    cout << *(to + 2);
    cout << *(to + 3);
    cout << *(to + 4);
    cout << *(to + 5);
    cout << *(to + 6);
    cout << endl;

    return 0;
}