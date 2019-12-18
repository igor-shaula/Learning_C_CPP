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

/*
 * Оператор приведение dynamic_cast<void *> для некоторого объекта возвращает
 * самый маленький адрес из всех возможных адресов для этого объекта, т.е. адрес его первого байта.
 * А "восстановиться" потом от void* к какому-нибудь классу иерархии через dynamic_cast получится?
 * - из void * можно только static_cast-ом восстановиться.
 * dynamic_cast работает только для полиморфа, т.е. в базовом классе должен быть виртуальный метод.
 * а у 'void' вообще нет методов. Поэтому из 'void*'а dynamic_cast`ом не восстановиться.
 * Другой вопрос, почему именно 'dynamic_cast<void*>(TYPE)'? не C-style и не reinterpret/static_cast ?
 * - Потому, что нужен полиморфизм. Остальные упомянутые преобразования в данном случае не будут сдвигать указатель.
 */

/*
 * Предположим, что вам даётся два указателя на объект некоторого сложного полиморфного класса,
 * который использует множественное наследование. Оба указателя имеют один и тот же тип,
 * но могут ссылаться на разные однотипные базы внутри одного объекта.
 * Напишите шаблонную функцию, которая по двум однотипным указателям проверяет, указывают ли они на один объект.
 */
// возвращает true, если p и q указывают на один и тот же объект
template<class T>
bool isSameObject(T const *p, T const *q) {
    return dynamic_cast<void const *>(p) == dynamic_cast<void const *>(q);
}