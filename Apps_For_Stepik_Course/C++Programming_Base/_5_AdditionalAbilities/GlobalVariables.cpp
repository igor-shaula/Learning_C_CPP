#include <iostream>
using namespace std;

int global = 10; // no problem with declaration & initialization in one line here
// if we haven't initialized 'global' here - it would just have value '0' & compile as usual

extern int gExtern = 10; // WARNING if we initialize and declare extern variable at once
// if we haven't initialized 'gExtern' here - we wouldn't be able to compile & link code

static int gStatic = 10; // behaves the same as 'global' but is alike 'extern' or so ???
// if we haven't initialized 'gStatic' here - it would just have value '0' & compile as usual

void changeGlobalVar()
{
    global = 4;  // this works fine
    gExtern = 4; // PROBLEM - this has no effect after we return from function
    gStatic = 4;
    cout << "changed value in separate function:" << global << endl;
    cout << "changed EXTERN value in separate function:" << gExtern << endl;
    cout << "changed STATIC value in separate function:" << gStatic << endl;
}
int main()
{
    cout << global << endl;
    cout << gExtern << endl;
    cout << gStatic << endl;
    global = 2;
    gExtern = 2;
    gStatic = 2;
    cout << "first value of global variable in main():" << global << endl;
    cout << "first value of EXTERN global variable in main():" << gExtern << endl;
    cout << "first value of STATIC global variable in main():" << gStatic << endl;
    changeGlobalVar();
    cout << "global value after return from separate function:" << global << endl;
    cout << "EXTERN value after return from separate function:" << gExtern << endl;
    cout << "STATIC value after return from separate function:" << gStatic << endl;
    return 0;
}