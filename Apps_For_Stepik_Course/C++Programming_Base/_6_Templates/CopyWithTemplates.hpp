#ifndef C_PROGRAMMING_BASE_COPY_WITH_TEMPLATES_HPP
#define C_PROGRAMMING_BASE_COPY_WITH_TEMPLATES_HPP

//class CopyWithTemplates {
//};

#include <cstddef>

template<typename U, typename T>
void copy_N(T *t, U const *u, size_t count);
// U and T are voluntary types which have defined conversion from U to T \
// U* is a source array, T* is destination array

#endif //C_PROGRAMMING_BASE_COPY_WITH_TEMPLATES_HPP