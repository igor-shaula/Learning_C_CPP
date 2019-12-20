// complicated sample:
char *(*f1(int, int))(int, int, int *, float);
// the same as previous but simplified a lot:
typedef char *(*MyFunction)(int, int, int *, float);
MyFunction f2(int, int);

// more sophisticated approach:
typedef char *Function(int, int, int *, float);
typedef Function *PtrFunction;
PtrFunction f3(int, int);

// very nice thing to know - http://c-faq.com/decl/spiral.anderson.html

/*
Разбираем подробно

char * ( * func (int, int)) (int, int, int*, float)

1) у нас определяется функция func, потому что func стоит левее круглых скобок, которая берет в качестве параметров (int, int)

2)  и возвращает указатель *(звездочка левее func)

3) на функцию, потому что конструкция ( * func (int, int)) стоит левее круглых скобок, которая берет

(int, int, int*, float)

4) которая, в свою очередь, возвращает указатель на char:  char *

Ещё раз, порядок интерпретации char * ( * func (int, int)) (int, int, int*, float):

1) func (int, int) - func - это фукнция, принимающая 2 инта

2) * func (int, int)  - возвращающая указатель

3) ( * func (int, int)) (int, int, int*, float)  - на функцию, принимающую указанный список параметров

4) char * ( * func (int, int)) (int, int, int*, float) - и возвращающую указатель на char
*/

typedef int *(*IIF)(char const *);
typedef int (*IF)(double);
typedef IIF (*ComplexFunction)(int, IF);
//typedef (int* (*)) ((*ComplexFunction) (int, int (*)(double))) (char const *) // this may be wrong