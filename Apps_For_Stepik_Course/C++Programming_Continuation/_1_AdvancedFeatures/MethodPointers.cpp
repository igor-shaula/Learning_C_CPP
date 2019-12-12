// we definitely need object here - differs from function pointers - not needed there

#include <utility> // this include is not definitely correct - just chosen for compilation
#include <cstdint>
#include <iostream>

struct Unit {
    Unit(int id, int hp) : id_(id), hp_(hp) {}
    // we gonna use these methods by passing them into another functions later:
    unsigned id() const { return id_; }
    unsigned hp() const { return hp_; };
private:
    int id_;
    int hp_;
};

// simplifying complicated syntax:
typedef unsigned (Unit::*UnitMethod)() const;

void sort(Unit *p, Unit *q, UnitMethod unitMethod) {
    // actually bubble sorting is shown here
    for (Unit *m = q; m != p; --m)
        for (Unit *r = p; r + 1 < m; ++r)
            if ((r->*unitMethod)() > ((r + 1)->*unitMethod)()) // invoking needed method by ->*
                std::swap(*r, *(r + 1)); // passing by value
}

//int main() {
//    Unit p(1, 10);
//    Unit q(2, 5);
//    sort(&p, &q, &Unit::hp);
//}

// Почему при работе с указателем на метод его нужно разыменовывать, а указатель на функцию - нет?
// - без этого правила было бы непонятно что именно использовать тогда, когда имя переменной совпадает с именем метода.
// Например:
struct UnitS {
    uint32_t method() const { return 1; }
    uint32_t method2() const { return 2; }
};

typedef uint32_t (UnitS::* unitMethod)() const;

void PrintValueByMethod(UnitS *unit, unitMethod method) {
    std::cout << (unit->*method)() << "\n";
    std::cout << (unit->method)() << "\n";
}

int main() {
    UnitS unit;
    PrintValueByMethod(&unit, &UnitS::method2);
    // Вывод:
    // 2
    // 1
    return 0;
}

// Как не используя typedef записать тоже самое ?
// void sort (Unit* p, Unit* q, ...); ?
// void sort (Unit* p, Unit* q, unsigned (Unit::*mtd)() const)