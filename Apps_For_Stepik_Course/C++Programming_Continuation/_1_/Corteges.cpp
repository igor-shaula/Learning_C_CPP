// what if we want to return many values from a function at once - there is a standard ability

#include <tuple>
#include <iostream>

// note that this is in fact a template function
std::tuple<std::string, int, int> getUnitInfo(int id) {
    if (id == 0) return std::make_tuple("Elf", 60, 9);
    if (id == 1) return std::make_tuple("Dwarf", 90, 6);
    if (id == 2) return std::make_tuple("Orc", 120, 3);
}

void showTuple() {
    auto unitInfo0 = getUnitInfo(0);
    std::cout << "race: " << std::get<0>(unitInfo0) << ", ";
    std::cout << "HP: " << std::get<1>(unitInfo0) << ", ";
    std::cout << "IQ: " << std::get<2>(unitInfo0) << std::endl;
}

void showTie() {
    auto unitInfo1 = getUnitInfo(1);
    std::string race1;
    int hp1, iq1;
    std::tie(race1, hp1, iq1) = getUnitInfo(1);
    std::cout << "race: " << race1 << ", ";
    std::cout << "HP: " << hp1 << ", ";
    std::cout << "IQ: " << iq1 << std::endl;
}

// sample of lexicographic ordering:
class foo {
public:
    foo(int n_, char c_, double d_) : n{n_}, c{c_}, d{d_} {}
    friend bool operator<(const foo &lh, const foo &rh) {
        return std::tie(lh.n, lh.c, lh.d) < std::tie(rh.n, rh.c, rh.d);
    }
private:
    int n;
    char c;
    double d;
};

int main() {
    showTuple();
    showTie();

    foo f1(1, 'a', 3.14);
    foo f2(1, 'b', 2.78);
    if (f1 < f2) return 1;

    return 0;
}

// Implement a lexicographic ordering over class members.
//
// The class `foo`, on [6-22], has three member variables `n`, `c` and
// `d` declared on [19-21]. We wish to implement an ordering relation
// for `foo` where these members are compared lexicographically.
//
// Getting an ordering relation right with 3 elements or more is
// tedious and error-prone. Fortunately, the standard library
// provides a lexicographic ordering over
// [`std::tuple`](cpp/utility/tuple), which we can utilise.
//
// The less-than operator for `foo` defined on [13-17] compares the
// member `n` first, then `c` if the `n`s are equal, and finally the
// member `d` if both the `n`s and `c`s are equal. To achieve this,
// we use [`std::tie`](cpp/utility/tuple/tie) on [15] and [16] to
// create `std::tuple`s containing references to the members of
// the left operand and right operand respectively. The comparison
// of these `std::tuple`s provides a lexicographic ordering over
// these members.