template<class F>
int *find_if(int *p, int *q, F f) {
    for (; p != q; ++p)
        if (f(*p))
            return p;
    return q;
}
/*
 * Определите переменную gen_finder,
 * хранящую безымянную функцию,
 * которая принимает массив значений типа int через два указателя
 * и возвращает безымянную функцию,
 * которая в свою очередь принимает значение типа int
 * и проверяет, есть ли это значение в переданном массиве.
 */

void runGivenTest() {
    int primes[5] = {2, 3, 5, 7, 11};
    int m[10] = {0, 0, 1, 1, 4, 6, 7, 8, 9, 10};
    // first_prime будет указывать на число 7
    int *first_prime = find_if(m, m + 10, gen_finder(primes, primes + 5));
}

int main() {
    runGivenTest();
    return 0;
}