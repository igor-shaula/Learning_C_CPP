struct Base {};

struct D1 : Base {};

struct D2 : Base {};

struct D3 : D1, D2 {};

/*
Напишите функцию D1BaseToD2Base,
 которая преобразует указатель типа Base на объект типа D3,
 который ссылается на экземпляр Base, соответствующий D1,
 в указатель, ссылающийся на экземпляр Base соответствующий D2.
Указание: не забывайте про константность!
 */

// base указывает на экземпляр Base, соответствующий D1
// нужно вернуть указатель на экземпляр Base, соответствующий D2
Base const *D1BaseToD2Base(Base const *base) {
    return (D2 const *) ((D3 const *) ((D1 const *) base));
}

int main() {
    return 0;
}