// RTTI = Runtime Type Information \
// there are two ways of getting RTTI (or there are 2 components of RTTI) \
// 1 - operator 'typeid' and type std::type_info  - reviewed here \
// 2 - operator 'dynamic_cast' - reviewed some later \\

/* type_info =
 * it is a class declared in 'typeinfo' system header (what is it ?)
 * contains information about type
 * has methods: == , != , name , before (set by compiler)
 * has no public constructors and assignment operators
 * link to type_info for given type or value can be got from operator 'typeid'
 * new standard has additional method 'hashcode' for type_info
 */