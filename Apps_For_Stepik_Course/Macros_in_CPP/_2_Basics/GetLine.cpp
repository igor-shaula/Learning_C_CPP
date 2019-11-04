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

char *getline()
{
    // char *container = new char[10];
    char *container = new char[0];
    char c;
    unsigned i = 0;
    while (cin.get(c) && c != '\n' && c != '\0')
    {
        container = resize(container, i, i + 1);
        *(container + i) = c;
        cout << container << endl;
        i++;
    }
    *(container + i) = '\0';
    return container;
}

int main()
{
    char *s = getline();
    cout << "result string: " << s << endl;
    delete[] s;
    return 0;
}

/*
на деле все не так сложно:

1) функция расширения динамического массива;

2) функция добавления одного элемента в существующий;

3) функция чтения/останова из потока вывода.

3 читает из потока и передает по одному в ф.2; ф.2 добавляет элемент если массив строки не переполнен. если переполнен, то расширяет его. ф.1 из предыдущей задачи.

следить за окончанием потока так:

while(std::cin.get(symbol) && symbol != '\n' && symbol != std::cin.eof())

массив строки увеличивать при достижении конца в 2 раза.
*/