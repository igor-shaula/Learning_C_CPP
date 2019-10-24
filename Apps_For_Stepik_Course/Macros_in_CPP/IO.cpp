#include <iostream>
using namespace std;

#include <cstring>

int main()
{
    char s1[100] = "hello";
    cout << strlen(s1) << endl;

    char s2[] = ", world";
    strcat(s1, s2);
    cout << strlen(s1) << endl;

    char s3[6] = {72, 101, 108, 108, 111};
    if (strcmp(s1, s3) == 0)
        cout << "s1 == s3" << endl;

    return 0;
}