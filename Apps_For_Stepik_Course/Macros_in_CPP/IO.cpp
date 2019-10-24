#include <cstdio>
void printfANDscanf() // C style - requires "cstdio"
{
    int a = 0, b = 0;
    printf("enter a & b: ");
    scanf("%d %d", &a, &b); // dangerous here - in fact any type of pointer can be sent here
    printf("a + b = %d\n", (a + b));
}

#include <iostream>
using namespace std;
void coutANDcin() // requires "iostream" library
{
    string name;
    cout << "enter any name: ";
    cin >> name;
    cout << "hi, " << name << endl;
}

#include <cstring>
void stringsInCStyle() // C style - requires "cstring" library
{
    char str1[100] = "hello";
    cout << strlen(str1) << endl;

    char str2[] = ", world";
    strcat(str1, str2);
    cout << strlen(str1) << endl;

    char str3[6] = {72, 101, 108, 108, 111};
    if (strcmp(str1, str3) == 0)
        cout << "str1 == str3" << endl;
}

void stringsInCppStyle() // CPP style - requires no libraries
{
    string s1 = "HELLO";
    cout << s1.size() << endl;

    string s2 = ", world";
    s1 = s1 + s2;
    cout << s1.size() << endl;

    if (s1 == s2)
        cout << "s1 == s3" << endl;
}

#include <fstream>
void workWithFiles() // requires "fstream" library
{
    // reading from a file
    string content;
    ifstream fromFile("input.txt");
    fromFile >> content;
    cout << content;
    // writing to a file
    ofstream toFile("output.txt");
    toFile << "hi, " << content << endl;
}

int main()
{
    stringsInCStyle();
    stringsInCppStyle();
    printfANDscanf();
    coutANDcin();

    return 0;
}