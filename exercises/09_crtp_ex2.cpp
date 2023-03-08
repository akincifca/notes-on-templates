// templateCRTP.cpp

#include <iostream>

template <typename Derived>
struct Base{
    void interface(){
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
    base.interface();
}

// Write the struct here

int main(){

    std::cout << std::endl;

    // call the function here

    std::cout << std::endl;

}

/*
 * In example 2, how can we prevent a derived class, which has the wrong template parameter: Derived4: Base<Derived3>
 */