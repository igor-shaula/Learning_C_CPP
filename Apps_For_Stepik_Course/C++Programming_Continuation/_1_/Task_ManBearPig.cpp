#include <cstddef>
#include <iostream>
using namespace std;

struct Unit {
    explicit Unit(size_t id) : id_(id) {}
    size_t id() const { return id_; }
private:
    size_t id_;
};

// базовый класс для животных
struct Animal : virtual Unit {
    explicit Animal(string const &name, size_t id) : Unit(id), name_(name) {}
    string const &name() const { return name_; }
private:
    string name_; // "bear" для медведя & "pig" для свиньи
};

struct Man : virtual Unit {
    explicit Man(size_t id) : Unit(id) {}
};

struct Bear : Animal {
    explicit Bear(size_t id) : Animal("bear", id), Unit(id) {}
};

struct Pig : Animal {
    explicit Pig(size_t id) : Animal("pig", id), Unit(id) {}
};

// класс для челмедведосвина
struct ManBearPig : Bear, Pig, Man {
    ManBearPig(size_t id) : Bear(id), Pig(id), Man(id), Unit(id) {}
};

int main() {
    return 0;
}