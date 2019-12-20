#include <iostream>
using namespace std;

void println(string const &s) {
    cout << s << endl;
}

void showAllStings() {
    println(u8"UTF-8 string"); // char[]
    cout << u"UTF-16" << endl; // char_16_t[] - println() is not possible here
    cout << U"UTF-32" << endl; // char_32_t[] - println() is not possible here
    cout << L"wide-char string" << endl; // wchar_t[] - println() is not possible here
    println(u8"Unicode character: \u2018");
    cout << u"Unicode character: \u2018" << endl;
    cout << U"Unicode character: \u00002018" << endl; // had to be big U instead of u - but with U it doesn't compile
    println(R"(the string data \ stuff" ")");
    println(R"DEL(the string data stuff" ")DEL");
    cout << LR"(raw wide string literal \t without a tab)" << endl;
    println(u8R"XXX(raw "UTF-8" string)XXX");
    cout << uR"*(raw "UTF-16" string)*" << endl;
    cout << uR"(raw "UTF-32" string)" << endl;
    // in fact all cases where i could not use println() worked badly - showing addresses instead of strings
}

int main() {
    showAllStings();
    return 0;
}