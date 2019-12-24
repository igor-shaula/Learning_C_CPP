// 'default' and 'delete' are new instructions for compiler - to generate functions or to avoid their generation
struct SomeType {
    SomeType() = default; // now this default constructor will be created by compiler
    SomeType(int) {};
};
struct NonCopyable { // intended to be impossible to copy
    NonCopyable() = default;
    NonCopyable(const NonCopyable &) = delete;
    NonCopyable &operator=(const NonCopyable &) = delete;
};

// else we can delete other functions - in fact anything we want:
template<class T>
void f(T const *p) {}
void f(char const *) = delete; // so it's now impossible to invoke this function with a string

// конструктор, не определенный юзером, всегда тривиален (i. e. ничего не делает).