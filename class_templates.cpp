#include <iostream>
#include <string>
#include <vector>

// function template declaration
template <typename T>
void xchg(T& x, T&y) {
    //
}

// class template declaration
template <typename T1, typename T2>
class Widget {
    T1 val1;
    T2 val2;
public:
    Widget(T1 arg1, T2 arg2) : val1(std::move(arg1)), val2(std::move(arg2)) {
        std::cout << "Widget is instantiated with template parameter T1: "
                  << typeid(T1).name() << "   T2: " << typeid(T2).name() << "\n";
    }
};

/*
 * Exercise
 */

class Account {
public:
    explicit Account(double amount = 0.0) : balance(amount) {}

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        balance -= amount;
    }

    double getBalance() const {
        return balance;
    }

private:
    double balance;
};

template <typename T, int N>
class Array {
public:
    Array() = default;
    int getSize() const;
private:
    T elem[N];
};

template <typename T, int N>
int Array<T,N>::getSize() const {
    return N;
}

template <typename T>
class Base{
public:
    void func1() const {
        std::cout << "func1()" << std::endl;
    }
    void func2() const {
        std::cout << "func2()" << std::endl;
    }
    void func3() const {
        std::cout << "func3()" << std::endl;
    }
};

template <typename T>
class Derived: public Base<T>{
public:
    using Base<T>::func2;

    void callAllBaseFunctions(){
        this->func1();
        func2();
        Base<T>::func3();
    }
};


int main() {

    int x = 5;
    int y = 10;

    xchg(x, y); // automatically derived template parameters <int>

    Widget<int, double> w(1, 5.0); // work pre C++17
    Widget w2 (1, "can"); // does not work pre C++17


    // Exercise
    Array<double, 10> doubleArray;
    std::cout << "size of doubleArray: " << doubleArray.getSize() << std::endl;

    Array<Account, 10> accountArray;
    std::cout << "size of accountArray: " << accountArray.getSize() << std::endl;


    Derived<int> derived;
    derived.callAllBaseFunctions();


    return 0;
}
