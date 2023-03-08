// templateTypes.cpp

#include <iostream>
#include <string>

template<typename T>
struct Type{
    std::string getName() const {
        return "unknown";
    }
};

int main(){

    std::cout << std::boolalpha << std::endl;

    Type<float> tFloat;
    std::cout << "tFloat.getName(): " << tFloat.getName() << std::endl;

    std::cout << std::endl;

}

/*
 * In the example above, the method getName returns unknown for any type passed in the argument of the function type
 * (line 8). If we specialize the class template for other types, we will implement a type deduction system at compile-time.
 * We’ll look at this in the coming exercise.
 */
