#include <cstdlib>
#include <iostream>

using namespace std;

struct Unit { virtual ~Unit() {}};
struct Elf : Unit {};
struct Dwarf : Unit {};

Unit *createRandomUnit() {
    Unit *u;
    if (rand() % 2)
        u = new Elf();
    else
        u = new Dwarf();
    // for some reason converting to '?:' for gives compilation error
    return u;
}

void checkChildType(Unit *u) {
    if (Elf *e = dynamic_cast<Elf *>(u)) // will give nullptr (=0 =false) if cast is not successful
        cout << "Elf ";
    else if (Dwarf *d = dynamic_cast<Dwarf *>(u))
        cout << "Dwarf ";
    else cout << "this cannot be!" << endl;
}

int main() {
    Unit *u;
    for (size_t i = 0; i < 10; ++i) {
        u = createRandomUnit();
        checkChildType(u);
    }
}

/*
 * features of dynamic_cast:
 * cannot be replaced with C-style casting (for now it's the only CPP cast with no replacement)
 * requires presence of virtual function table at least in base type as a sign of polymorphism
 * usage of dynamic_cast leads to lots of if-statements in code - this should be avoided
 * unsuccessful dynamic_cast<reference> throws exception 'std::bad_cast'
 * dynamic_cast is precise but works SLOWER - as it is NOT compile time casting
 */