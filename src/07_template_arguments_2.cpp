// templateDefaultArgument.cpp

#include <functional>
#include <iostream>
#include <string>

/*
 * In the first example, we have passed only built-in data types. In this example, we have used the built-in types int,
 * double, std::string in lines 26 – 28 and the Account class in line 30. The function template isSmaller is parametrized
 * by a second template parameter, which defines the comparison criterion. The default for the comparison is the predefined
 * function object std::less. A function object is a class for which the call operator (operator ()) is overloaded.
 * This means that instances of function objects behave similar to functions. The Account class doesn’t support the < operator.
 * Thanks to the second template parameter, a lambda expression as in lines 30 and 33 can be used. This means two Account
 * instances can be compared by their balance and strings by their number. stod converts a string to a double.
 */

class Account{
public:
    explicit Account(double b): balance(b){}
    double getBalance() const {
        return balance;
    }
private:
    double balance;
};

template <typename T, typename Pred= std::less<T> >
bool isSmaller(T fir, T sec, Pred pred= Pred() ){
    return pred(fir,sec);
}

int main(){

    std::cout << std::boolalpha << std::endl;

    std::cout << "isSmaller(3,4): " << isSmaller(3,4) << std::endl;
    std::cout << "isSmaller(2.14,3.14): "  << isSmaller(2.14,3.14) << std::endl;
    std::cout << "isSmaller(std::string(abc),std::string(def)): " << isSmaller(std::string("abc"),std::string("def")) << std::endl;

    bool resAcc= isSmaller(Account(100.0),Account(200.0),[](const Account& fir, const Account& sec){ return fir.getBalance() < sec.getBalance();});
    std::cout << "isSmaller(Account(100.0),Account(200.0)): " << resAcc << std::endl;

    bool acc= isSmaller(std::string("3.14"),std::string("2.14"),[](const std::string& fir, const std::string& sec){ return std::stod(fir) < std::stod(sec);});
    std::cout << "isSmaller(std::string(3.14),std::string(2.14)): " << acc << std::endl;

    std::cout << std::endl;
}
