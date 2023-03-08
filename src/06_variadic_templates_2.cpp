
// templatePerfectForwarding.cpp

#include <iostream>
#include <utility>

/*
 * In the example above, we have created a createT function which invokes the constructor T with the arguments args.
 * If there is no value passed, it invokes the default constructor. The magic of the factory function createT is that
 * it can invoke each constructor. Thanks to perfect forwarding, each value can be used such as an lvalue or an rvalue;
 * thanks to parameter packs, any number of arguments can be used. In the case of MyStruct, a constructor that requires
 * three arguments is used.

The pattern of the function template createT is exactly the pattern factory functions such as std::make_unique,
 std::make_shared, std::make_pair, or std::make_tuple use.
 *
 */

template<typename T, typename ... Args>
T createT(Args&& ... args){
    return T(std::forward<Args>(args) ...);
}

struct MyStruct{
    MyStruct(int&, double&, double&&){}
    friend std::ostream& operator<< (std::ostream& out, const MyStruct&){
        out << "MyStruct" << std::endl;
        return out;
    }
};

int main(){

    std::cout << std::endl;

    double myDouble= createT<double>();
    std::cout << "myDouble: " << myDouble << std::endl;

    int myInt= createT<int>(1);
    std::cout << "myInt: " << myInt << std::endl;

    std::string myString= createT<std::string>("My String");
    std::cout << "myString: "  << myString << std::endl;

    MyStruct myStruct= createT<MyStruct>(myInt, myDouble, 3.14);
    std::cout << "myStruct: "  << myStruct << std::endl;

    std::cout << std::endl;
}