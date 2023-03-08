// Example 2: static polymorphism with CRTP
#include <iostream>

template <typename Derived>
struct Base{
    void Interface(){
        static_cast<Derived*>(this)->implementation();
    }

    void implementation(){
        std::cout << "Implementation Base" << std::endl;
    }
};

struct Derived1: Base<Derived1>{
    void implementation(){
        std::cout << "Implementation Derived1" << std::endl;
    }
};

struct Derived2: Base<Derived2>{
    void implementation(){
        std::cout << "Implementation Derived2" << std::endl;
    }
};

struct Derived3: Base<Derived3>{};

template <typename T>
void execute(T& base){
    base.Interface();
}

int main(){

    std::cout << std::endl;

    Derived1 d1;
    execute(d1);

    Derived2 d2;
    execute(d2);

    Derived3 d3;
    execute(d3);

    std::cout << std::endl;

}

/*
 * We have used static polymorphism in the function template execute (lines 30-33). We then invoked the method base.
 * Interface on each base argument. These method Base::Interface, in lines (7-9), is the key point of the CRTP idiom.
 * The methods dispatch to the implementation of the derived class: static_cast<Derived*>(this)->implementation() which
 * is possible because the method will be instantiated when called. At this point in time, the derived classes Derived1,
 * Derived2, and Derived3 are fully defined. Therefore, the method Base::Interface can use the details of its derived
 * classes. The method Base::implementation (lines 11-13) is especially interesting. This method works as the default
 * implementation for the static polymorphism for the class Derived3 (line 28).
 */