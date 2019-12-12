#include <iostream>
using namespace std;

// the question is - what is inside pointer to method (in detail) ?

struct Elf {
    string secretName;
};

struct Archer {
    unsigned arrows() const { return arrows_; } // method is in segment of code - not in the object
    unsigned arrows_;
};

struct ElfArcher : Elf, Archer { // data is placed in the same sequence as base classes are listed:
    // in memory any ElfArcher object has: secretName at the beginning and arrows_ right after that
    ElfArcher(unsigned i) { arrows_ = i; }
};

void launch() {
    ElfArcher ea = {42};
    unsigned (ElfArcher::*method)() const = &Archer::arrows;
    unsigned a = (ea.*method)(); // this is invocation
    cout << a << endl;
}

int main() {
    launch();
    return 0;
}

/* Все ли компиляторы гарантируют, что при записи:
        struct ElfArcher : Elf, Archer{};
в представлении класса ElfArcher в памяти сначала идет информация об Elf, а потом об Archer?
Влият ли это на порядок вызова конструктора?
И вообще, должен ли программист беспокоится об этом вопросе?
=
 Порядок вызовов конструкторов фиксирован - он такой же, как в списке наследования.
 Представление в памяти не гарантируется.
 Обычно порядок такой, как в списке наследования, но этого Вам никто не гарантирует.
 Программисту об этом лучше не думать и писать код так, чтобы он работал по стандарту.
 Вариант: "мы тут делаем С-style касты и явные сдвиги указателей с неопределённым поведением,
 но на всех известных мне компиляторах работает" - это не очень хорошо.
 */