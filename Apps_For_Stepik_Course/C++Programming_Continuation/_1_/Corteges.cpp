// what if we want to return many values from a function at once - there is a standard ability

#include <tuple>
#include <iostream>

// note that this is in fact a template function
std::tuple<std::string, int, int> getUnitInfo(int id) {
    if (id == 0) return std::make_tuple("Elf", 60, 9);
    if (id == 1) return std::make_tuple("Dwarf", 90, 6);
    if (id == 2) return std::make_tuple("Orc", 120, 3);
}

void showTuples() {
    auto unitInfo0 = getUnitInfo(0);
    std::cout << "race: " << std::get<0>(unitInfo0) << ", ";
    std::cout << "HP: " << std::get<1>(unitInfo0) << ", ";
    std::cout << "IQ: " << std::get<2>(unitInfo0) << std::endl;
}

int main() {
    showTuples();
    return 0;
}