// field pointers are like usual pointers - but again we need object here

#include <utility>
struct Unit {
    unsigned id;
    unsigned hp;
};

typedef unsigned Unit::*UnitField;

// again using bubble sort for our sample:
void sort(Unit *p, Unit *q, UnitField unitField) {
    for (Unit *m = q; m != p; --m)
        for (Unit *r = p; r + 1 < m; ++r)
            if ((r->*unitField) > ((r + 1)->*unitField))
                std::swap(*r, *(r + 1)); // need to swap by value - because we're sorting values
}

int main() {
    Unit p = {1, 10};
    Unit q = {2, 5};
    sort(&p, &q, &Unit::hp);
}

/*
 * В сортировке пузырьком предполагается, что при окончании каждой i-й итерации (считаем с нуля)
 * внешнего цикла сортировки в конце сортируемой последовательности находится (i + 1) отсортированный элемент.

// T arr[N] = {...};

for (size_t i = 0; i < N - 1; ++i) {
  for (size_t j = 0; j < N - i - 1); ++j) {
    if (arr[j] > arr[j + 1]) {
      swap(arr[j], arr[j + 1]);
    }
  }
}

Ну а в коде на слайде внутренний цикл итерируется не с 0 до (N - i - 1), а с i до N.
Элементы в начале последовательности могут остаться неотсортированными.
 */