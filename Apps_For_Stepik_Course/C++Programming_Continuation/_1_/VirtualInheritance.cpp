#include <cstdlib>
struct Unit { int id; };
struct Elf : virtual Unit {};
struct Archer : virtual Unit {};
struct ElfArcher : Elf, Archer {};

int main() {

    Elf *e = (rand() % 2) ? new Elf() : new ElfArcher();
    int id = e->id;
    // in fact this pointer-based work is done via the following code:
    /* int id = e -> __getUnitPtr__() -> id; where  __getUnitPtr__() is virtual service method */
    // that's because compiler at first has to determine shift of base type pointer

    return 0;
}