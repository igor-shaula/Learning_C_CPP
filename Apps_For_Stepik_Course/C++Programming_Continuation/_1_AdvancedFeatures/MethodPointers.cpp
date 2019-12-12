// we definitely need object here - differs from function pointers - not needed there

#include <utility> // this include is not definitely correct - just chosen for compilation

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

int main() {
    Unit p(1, 10);
    Unit q(2, 5);
    sort(&p, &q, &Unit::hp);
}