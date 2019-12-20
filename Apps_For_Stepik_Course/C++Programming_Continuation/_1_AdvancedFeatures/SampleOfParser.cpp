/* Другой пример, на котором можно увидеть, как применяются указатели на функции
 * — это библиотека Expat для парсинга XML. Библиотека Expat реализует так называемый SAX-парсер.
 * Когда в процессе разбора XML встречается, например, новый тег,
 * то вызывается пользовательская функция для обработки этого события.
 * Для того, чтобы установить свою функцию обработки, в библиотеку нужно передать указатель на эту функцию.
 *
 * Ниже приведён пример кода с использованием библиотеки Expat,
 * который разбирает XML и выводит содержимое тегов "title".
 */
#include <iostream>
#include <fstream>

#include <string>
#include <vector>

#include <expat.h>

using std::string;

// структура для хранения пользовательских данных
struct MyData {
    // заголовки новостей
    std::vector<string> news;
    // текущий открытый тег
    string openTag;
    // текст внутри тега title
    string title;
};

// вызывается для открывающего тега
// el - имя тега
// attr - аттрибуты тега
void start(void *data, const char *el, const char **attr) {
    MyData &d = *static_cast<MyData *>(data);

    // сохраняем последний открытый тег
    d.openTag = el;
}

// вызывается для закрывающего тега
// el - имя тега
void end(void *data, const char *el) {
    MyData &d = *static_cast<MyData *>(data);
    if (d.openTag == "title") {
        // сохраняем заголовок в векторе
        d.news.push_back(d.title);

        // очищаем title
        d.title = "";
    }
}

// вызывается для текста внутри тегов
void text(void *data, const char *s, int len) {
    MyData &d = *static_cast<MyData *>(data);

    if (d.openTag == "title") {
        // добавиляем текст заголовка
        d.title += string(s, len);
    }
}

int main() {
    // создаём XML парсер
    XML_Parser p = XML_ParserCreate(0);

    // открываем файл с XML в бинарном режиме
    std::ifstream f("rss.xml", std::ifstream::binary);

    // обработка ошибки открытия файла
    if (!f.is_open()) {
        std::cerr << "Can not open 'rss.xml' for reading\n";
        return 1;
    }

    // устанавливаем указатель на функции, которые
    // будут вызывать при встрече открывающего тега
    // (start) и закрывающего тега (end)
    XML_SetElementHandler(p, start, end);

    // устанавливаем указатель на функцию для обработки
    // текста внутри XML тегов
    XML_SetCharacterDataHandler(p, text);

    // пользовательские данные, которые мы будем использовать
    // при парсинге XML
    MyData data;

    // устанавливаем указатель на пользовательские данные
    XML_SetUserData(p, &data);

    // будем считывать по 1Кб за раз
    char buff[1024];

    // читаем данные из файла
    while (f.read(buff, sizeof(buff))) {
        // колличество считанных байтов
        size_t len = f.gcount();

        // парсим прочитанный кусочек
        if (!XML_Parse(p, buff, len, f.eof())) {
            // обработка ошибок при парсинге
            std::cerr << "Parser error at line "
                      << XML_GetCurrentLineNumber(p) << ": "
                      << XML_ErrorString(XML_GetErrorCode(p))
                      << std::endl;
            return 1;
        }
    }

    // выводим все заголовки на стандартный вывод
    for (size_t i = 0; i != data.news.size(); ++i)
        std::cout << data.news[i] << std::endl;

    return 0;
}
/* Этот код можно использовать для того чтобы вывести все заголовки новостей из какого-нибудь RSS-потока.
 * Например, можно скачать какой-нибудь RSS файл:
wget "https://stackoverflow.com/feeds/tag?tagnames=c%2b%2b&sort=newest" -O rss.xml
(в этом примере скачиваются последние темы с сайта StackOverflow с тегом "c++").
Для того, чтобы скомпилировать этот код, вам потребуется установить библиотеку Expat.
В Ubuntu это можно сделать следующей командой:
sudo apt install libexpat1-dev
При компиляции нужно указать, что используется библиотека expat (это нужно для линковщика).
g++ rss.cpp -o rss -lexpat

Попробуйте поэкспериментировать с этим кодом,
 например, улучшить его или написать свой парсер для какого-нибудь другого типа XML документов.
 */