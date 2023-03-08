// templateSpecializationFull.cpp

#include <iostream>
#include <string>

template <typename T>
T min(T fir, T sec){
    return (fir < sec) ? fir : sec;
}

template <>
bool min<bool>(bool fir, bool sec){
    return fir & sec;
}

int main(){

    std::cout << std::boolalpha << std::endl;

    std::cout << "min(3.5, 4.5): "  << min(3.5, 4.5) << std::endl;
    std::cout << "min<double>(3.5, 4.5): "  << min<double>(3.5, 4.5) << std::endl;

    std::cout << "min(true, false): "  << min(true, false) << std::endl;
    std::cout << "min<bool>(true, false): "  << min<bool>(true, false) << std::endl;

    std::cout << std::endl;

}

/*
 * In the example above, we have defined a full specialization for bool. The primary and full specializations are
 * implicitly invoked in lines 20 and 23 and explicitly invoked in lines 21 and 24.
 */