#include <iostream>
using namespace std;

enum COLORS {
    BLACK, WHITE, RED, GREEN = 4, BLUE = 8 // by default BLACK is 0, WHITE is 1, RED is 2
};
// given sample of enums is NOT type safe - because actually those are int numbers and
// values of DIFFERENT enums can be compared between themselves \
// another problem is that enum does not set any areas of visibility
// - so they all are accessible from outside (without specifying the name of enum)
enum NOT_COLORS {
    NOT_BLACK, NOT_WHITE, NOT_RED
};
void checkOldEnums() {
    cout << WHITE << endl;
    cout << COLORS::GREEN + 2 * COLORS::RED << endl;
    cout << (COLORS::BLACK == NOT_COLORS::NOT_BLACK) << endl; // gives warning but 1 in result
}

// new standard (11) removes these problems:
enum class COLORS_NEW {
    BLACK, WHITE, RED, GREEN = 4, BLUE = 8
};
enum class NOT_COLORS_NEW {
    BLACK, WHITE, RED, GREEN = 4, BLUE = 8
};
// type can be specified now - but it has to be integral (non-double, non-float)
enum class SPECIFIED : unsigned char {
    MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY = 9
};

void checkNewEnums() {
//    cout << COLORS_NEW::GREEN << endl; // does not compile
//    cout << (COLORS_NEW::WHITE == NOT_COLORS_NEW::WHITE) << endl; // does not compile
    cout << "how many bytes in type: " << sizeof(SPECIFIED::SUNDAY) << endl;
}

// if old-type enums already are used in project - it's possible to specify type for them:
enum OLD : unsigned char {
    MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY = 11
};

int main() {
    checkOldEnums();
    checkNewEnums();
    cout << SUNDAY << " - how many bytes in its type: " << sizeof(SUNDAY) << endl;
    return 0;
}