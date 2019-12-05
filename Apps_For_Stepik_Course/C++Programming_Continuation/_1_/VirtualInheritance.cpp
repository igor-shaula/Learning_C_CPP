#include <cstdlib>

void testSample1();
void testSample2();
int main() {
    testSample1();
    testSample2();
    return 0;
}
void testSample1() {
    struct Unit { int id; };
    struct Elf : virtual Unit {};
    struct Archer : virtual Unit {};
    struct ElfArcher : Elf, Archer {};

    Elf *e = (rand() % 2) ? new Elf() : new ElfArcher();
    int id = e->id;
    // in fact this pointer-based work is done via the following code:
    /* int id = e -> __getUnitPtr__() -> id; where  __getUnitPtr__() is virtual service method */
    // that's because compiler at first has to determine shift of base type pointer
}
void testSample2() {

}