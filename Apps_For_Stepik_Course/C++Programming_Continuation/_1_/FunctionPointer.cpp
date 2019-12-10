#include <iostream>
using namespace std;

void qsort(void *base, size_t howMany, size_t size,
           int (*comparator)(void const *, void const *)); // 'comparator' is function pointer

int compareDoubles(void const *a, void const *b) {
    double da = *static_cast<double const *>(a);
    double db = *static_cast<double const *>(b);
    if (da < db) return -1;
    if (da > db) return +1;
    return 0;
}

void sort(double *p, double *q) {
    qsort(p, q - p, sizeof(double), &compareDoubles); // the last is the function's address
}

// better way of doing the same things - but much more safer with handling types:

void sort_(int *p, int *q, bool (*compare)(int, int)) {
    for (int *m = q; m != p; --m)
        for (int *r = p; r + 1 < m; ++r)
            // if(*(r+1)<*r) - instead of this we'll use pointer to given comparator
            if (compare(*(r + 1), *r))
                std::swap(*r, *(r + 1));
}

bool lesser_(int a, int b) { return a < b; }
bool greater_(int a, int b) { return a > b; }
void sort_(int *p, int *q, bool ascending = true) {
    sort_(p, q, ascending ? &lesser_ : &greater_);
}
/*
 * В чем заключается типобезопасность этого примера по сравнению с предыдущим?
 * - Передавать что-то как void* плохо. Не будет вообще никаких проверок типов.
 *
 * Данный пример скорее учебный, чем рабочий. Серьезным недостатком такого подхода -
 * отсутствие оптимизации компилятором тела цикла.
 * На этапе компиляции элементарная функция сравнения не встроится в код (и не будет оптимизирована),
 * а будет вызываться как функция, со всеми сопутствующими накладными расходами.
 * P.S. В зависимости от компилятора, места применения функции sort и настройки оптимизации,
 * данный пример может быть оптимизирован, но на это надежд возлагать не стоит.
 *
 * По-моему это не пузырьковая сортировка в чистом виде, а гибрид линейной и пузырьковой сортировки.
 * В пузырьковой сортировке, которой учили меня в школе, сравниваются соседние значения,
 * далее, если совершается перестановка, устанавливается флаг на следующий проход,
 * и так повторяется до тех пор, пока не случится ни одной перестановки.
 * Таким образом, в случае сортированного массива совершается лишь один проход,
 * а данном примере проходов больше одного вне зависимости от упорядоченности массива.
 */

int main() {
    double a = 1.2;
    double b = 2.3;
//    sort(&a, &b);
    int i1 = 2;
    int i2 = 3;
    sort_(&i1, &i2);
    sort_(&i1, &i2, true);
    sort_(&i1, &i2, false);
    // for some reason output is: Process finished with exit code -1073741819 (0xC0000005)
    return 0;
}