// constexpr keyword serves for constants and functions during compile time

constexpr double accOfGravity = 9.8;

constexpr double moonGravity = accOfGravity / 6; // compiler will calculate exact value

constexpr int pow(int x, int k) { // compiler knows exact value that is returned from the function
    return k == 0 ? 1 : x * pow(x, k - 1);
}

int data[pow(3, 5)] = {}; // array of needed size will be created

struct Point { // constexpr functions can belong to a type - and constexpr constructor is possible
    double x, y;
    constexpr Point(double x = 0, double y = 0) : x(x), y(y) {}
    constexpr double getX() const { return x; }
    constexpr double getY() const { return y; }
};

constexpr Point p(moonGravity, accOfGravity); // one constexpr out of other
constexpr auto x = p.getX(); // this value will be calculated during compile time

// constexpr functions must contain only one return value that can be calculated \
// constexpr functions cannot use usual functions - only constexpr-marked ones \\

/*
 * Отличаются ли constexpr переменные от const?
 * Могут ли значения const зависеть от результата constexpr функции константного аргумента?
 * - да, отличаются, constexpr переменные должны быть известны на этапе компиляции, а const - не обязательно. Могут.
 */