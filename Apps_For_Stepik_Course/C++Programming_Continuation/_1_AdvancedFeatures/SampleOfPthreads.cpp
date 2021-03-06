/*
 * Один из примеров, на которых можно увидеть, как применяются указатели на функции
 * — это использование Linux библиотеки pthread для написания многопоточных приложений.
 * Библиотека pthread позволяет создавать потоки в POSIX системах.
 */

#include <iostream>
#include <cmath>

// подключаем библиотеку pthread
#include <pthread.h>

// функция создания потоков имеет следующую сигнатуру
//int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
//                   void *(*start_routine) (void *), void *arg);

// структура для хранения данных о задаче интегрирования
struct Task {
    // функция
    double (*f)(double);
    // начальная точка отрезка
    double start;
    // конечная точка отрезка
    double end;
    // шаг интегрирования
    double eps;
    // куда записать результат
    double *result;
};

// функция потока
void *thread_fun(void *data) {
    // получаем задачу
    Task &t = *static_cast<Task *>(data);

    // переменная для результата
    double res = 0;
    for (double x = t.start; x < t.end; x += t.eps)
        res += t.f(x + t.eps / 2) * t.eps;

    *t.result = res;
    return 0;
}

// функция, которую будем интегрировать
double function(double x) {
    return exp(x * sin(x));
}

int main() {
    // количество потоков
    int const THREAD_COUNT = 8;

    // массив, в который будут записаны результаты
    double results[THREAD_COUNT] = {};

    // задачи для потоков
    Task tasks[THREAD_COUNT] = {};

    // пределы интегрирования
    double const start = -5;
    double const end = 5;

    // заполняем задачи
    double const taskLen = (end - start) / THREAD_COUNT;
    for (int i = 0; i != THREAD_COUNT; ++i) {
        tasks[i].f = &function;
        tasks[i].start = start + taskLen * i;
        tasks[i].end = tasks[i].start + taskLen;
        tasks[i].eps = 1e-7;
        tasks[i].result = &results[i];
    }

    // создаём дескрипторы потоков
    pthread_t threads[THREAD_COUNT];

    // создаём и запускаем потоки
    for (size_t i = 0; i != THREAD_COUNT; ++i)
        pthread_create(&threads[i], 0, &thread_fun, &tasks[i]);

    // дожидаемся завершения потоков
    for (size_t i = 0; i != THREAD_COUNT; ++i)
        pthread_join(threads[i], 0);

    // складываем результаты
    double res = 0;
    for (size_t i = 0; i != THREAD_COUNT; ++i)
        res += results[i];

    // выводим результат
    std::cout << "Result: " << res << std::endl;

    return 0;
}
// При компиляции нужно указать, что используется библиотека pthread (это нужно для линковщика):
// g++ integrate.cpp -O2 -o integrate -pthread

// Если захотите сравнить время различных модификаций, то самый простой способ это сделать в Linux — команда time:
// time ./integrate

/*
Стандартный вывод time дает процессорное время выполнения всех потоков, поэтому оно не меняется.
Чтобы получить время "часов" (elapsed time) можно либо смотреть полный вывод утилиты time
\time -v ./integrate
 либо задать формат вывода только этого времени
\time -f "%E" ./integrate
П.С. интересно было узнать, что в линуксе есть два способа получения времен:
 bash скрипт time, и утилита /usr/bin/time (которую я использую выше)
 */

/* for compilation & work on Windows:
 Заменил:

    // создаём дескрипторы потоков
    pthread_t threads[THREAD_COUNT];

    // создаём и запускаем потоки
    for (size_t i = 0; i != THREAD_COUNT; ++i)
        pthread_create(&threads[i], 0, &thread_fun, &tasks[i]);

    // дожидаемся завершения потоков
    for (size_t i = 0; i != THREAD_COUNT; ++i)
        pthread_join(threads[i], 0);
на:

#include <thread>

    std::vector<std::thread> threads;

    for (size_t i = 0; i != THREAD_COUNT; ++i)
    {
        std::thread temp(&thread_fun, &tasks[i]);
        threads.push_back(std::move(temp));
    }

    for (size_t i = 0; i != THREAD_COUNT; ++i)
        threads[i].join();
Все остальное – без изменений.
 */