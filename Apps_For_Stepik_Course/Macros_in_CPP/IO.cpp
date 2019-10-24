#include <iostream>
using namespace std;

#include <cstring>

int main()
{
    // block 1 - C style

    char str1[100] = "hello";
    cout << strlen(str1) << endl;

    char str2[] = ", world";
    strcat(str1, str2);
    cout << strlen(str1) << endl;

    char str3[6] = {72, 101, 108, 108, 111};
    if (strcmp(str1, str3) == 0)
        cout << "str1 == str3" << endl;

    // block 2 - CPP style

    string s1 = "HELLO";
    cout << s1.size() << endl;

    string s2 = ", world";
    s1 = s1 + s2;
    cout << s1.size() << endl;

    if (s1 == s2)
        cout << "s1 == s3" << endl;

    return 0;
}