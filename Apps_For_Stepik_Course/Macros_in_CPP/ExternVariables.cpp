#include <iostream>
using namespace std;

int global = 10; // no problem with declaration & initialization in one line here
// if we haven't initialized 'global' here - it would just have value '0' & compile as usual
extern int globalExtern = 10; // WARNING if we initialize and declare extern variable at once
// if we haven't initialized 'globalExtern' here - we wouldn't be able to compile & link code

void changeGlobalVar()
{
    global = 4;       // this works fine
    globalExtern = 4; // PROBLEM - this has no effect after we return from function
    cout << "changed value in separate function:" << global << endl;
    cout << "changed EXTERN value in separate function:" << globalExtern << endl;
}
int main()
{
    cout << global << endl;
    cout << globalExtern << endl;
    global = 2;
    globalExtern = 2;
    cout << "first value of global variable in main():" << global << endl;
    cout << "first value of EXTERN global variable in main():" << globalExtern << endl;
    changeGlobalVar();
    cout << "value after return from separate function:" << global << endl;
    cout << "EXTERN value after return from separate function:" << globalExtern << endl;
    return 0;
}