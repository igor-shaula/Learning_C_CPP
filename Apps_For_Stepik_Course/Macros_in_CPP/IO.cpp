#include <cstdio>
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

void printfANDscanf() // C style - requires "cstdio"
{
    int a = 0, b = 0;
    printf("enter a & b: ");
    scanf("%d %d", &a, &b); // dangerous here - in fact any type of pointer can be sent here
    printf("a + b = %d\n", (a + b));
}

void coutANDcin() // requires "iostream" library
{
    string name;
    cout << "enter any name: ";
    cin >> name;
    cout << "hi, " << name << endl;
}

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

void workWithFiles() // requires "fstream" library
{
    // reading from a file
    string content;
    ifstream fromFile("testFileForInput.txt");
    fromFile >> content;
    cout << content << endl;
    // writing to a file
    ofstream toFile("testFileForOutput.txt");
    toFile << "hi, " << content << endl;
}

void testStrings() // ptr vs array-like declaration, const & non-const strings
{
    char *a = "hello";
    char b[] = "hello";
    std::cout << a << " " << b << std::endl;
    std::cout << &a << " " << &b << std::endl;
    std::cout << a[0] << " " << b[0] << std::endl;
    std::cout << *a << " " << *b << std::endl;
    /* result has to ollk like this:
    hello hello
    0x6afefc 0x6afef6
    h h
    h h
    */
    // this has to lead to execution error:
    char *sptr = "hello";
    sptr[0] = 'x';
    // and this has to work perfectly:
    char s[] = "hello";
    s[0] = 'x';
    const char s1[] = "hello";
    const char *s2 = "hello";
    /*
    В первом случае создается массив и в него копируется содержимое строкового литерала.
    Во втором случае берется строковый литерал (который является неизменяемым массивом) и приводится к указателю и сохраняется в s.
    Итого в первом случае у вас есть копия данных, а во втором у вас всего лишь указатель на данные.
    */
}

int strcmpAlternative(const char *a, const char *b)
{
    while (*a && *b && *a == *b)
        ++a, ++b;
    return *a - *b;
}

/*
// redirection of input stream - useful for testing:

// 1st variant - can be used in C as well:
freopen("input.txt", "r", stdin); // перенаправление стандартного потока в стиле C

// 2nd variant - only CPP style:
#include <iostream>
#include <fstream>
std::streambuf *stdin_bcp=std::cin.rdbuf(); // сохраняем старый поток stdin
std::ifstream ifs("input.txt"); // Создаём поток для чтения из файла "input.txt"
std::cin.rdbuf(ifs.rdbuf()); // Перенаправили стандартный ввод на ввод из файла
//..... Ваш код ........
std::cin.rdbuf(stdin_bcp); // восстанавливаем поток stdin по умолчанию
ifs.close(); // закрываем поток чтения из файла.
*/

int main()
{
    stringsInCStyle();
    stringsInCppStyle();
    printfANDscanf();
    coutANDcin();
    workWithFiles();
    // testStrings();

    return 0;
}