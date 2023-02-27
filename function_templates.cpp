#include <iostream>
#include <string>
#include <vector>

/*
 * Function Templates
 */
template<typename T>
void xchg(T& x, T& y) {
    T t = x;
    x = y;
    y = t;
}

template<int N>
// non-type template parameter N
int nTimes(int n) {
    return N * n;
}

/*
 * Exercise 1
 * Function to calculate 2 to the power of 10
 */
//template<int N>
//int power(int arg) {
//    int result = 1;
//    for (int i = 0; i < N; ++i) {
//        result *= arg;
//    }
//    return result;
//}

// using template arguments
// calculation done in compile time
template<int m, int n>
struct Power {
    static constexpr int value = m * Power<m, n - 1>::value;
};

template<int m>
struct Power<m, 0> {
    static constexpr int value = 1;
};

// using template arguments & function arguments
// (arg) is evaluated at runtime and <> is evaluated at compile time
template <int n>
int power(int m) {
    return m * power<n-1>(m);
}
template <>
int power<0>(int m) {
    return 1;
}

int main() {
    // auto val = Power<2,5>::value;
    auto val = power<5>(2);
    std::cout << val << "\n";
    return 0;
}

