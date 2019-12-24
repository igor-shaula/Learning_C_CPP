// again like in Java we have new abilities to check and restrict inheritance options
struct Base {
    virtual void update();
    virtual void f(int);
    virtual void fc() const;
};
struct Derived : Base {
//    void update1() override; // would compile without 'override' but it could be wrong
    void f(int) override;
//    void f() override; // 'override' prevents from inheritance with wrong parameter list
//    virtual void f(long) override; // error - long instead of int
//    virtual void f(int) const override; // error - const added
//    virtual float f(int) override; // error - return type is different
    virtual void fc(long); // ok without 'override' - so this function cannot be used with parent class
    virtual void fc() const final; // now this function cannot be overridden in any derivative class
};
struct Derived2 final : Derived { // making the whole class final here
//    virtual void fc() const; // remember we made this function final in parent class
};
//struct Derived3 : Derived2 {}; // cannot compile because Derived2 was final before this declaration

// override лучше использовать везде, где есть виртуальные методы. final — по назначению

/* Ещё final помогает компилятору в девиртуализации
 * (тип оптимизации, когда вызовы к виртуальным методам заменяются на прямые).
 * Например если у объекта, переданного по указателю, вызывается final метод,
 * то можно к виртуальной таблице не обращаться.
 */