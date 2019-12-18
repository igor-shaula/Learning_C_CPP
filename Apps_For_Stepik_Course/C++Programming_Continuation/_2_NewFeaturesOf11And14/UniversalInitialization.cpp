// previously there was different approach of initialization of a structure \
// depending on if it had constructor with arguments - invocation was different \\

struct CStyleStruct { // these structs cannot have methods and constructor as well !!!
    int x;
    double y;
};
struct CPPStyleStruct {
    CPPStyleStruct(int x, double y) : x(x), y(y) {}
    int x;
    double y;
};

// C++03
CStyleStruct s1 = {1, 2.3}; // initialization
CPPStyleStruct s2(1, 2.3); // invocation of constructor

// C++11
CStyleStruct s3{1, 2.3}; // initialization - without =
CPPStyleStruct s4{1, 2.3}; // constructor invocation - {} instead of ()
// now creation of both types looks the same

CStyleStruct getValue() {
    return {2, 3.4}; // note that here we don't specify a type before {} - it's not needed
}

int main() {
    return 0;
}