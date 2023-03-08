// Example 1: mixins with CRTP
// templateCRTPRelational.cpp
#include <iostream>
#include <string>

template<class Derived>
class Relational{};

// Relational Operators

template <class Derived>
bool operator > (Relational<Derived> const& op1, Relational<Derived> const & op2){
    Derived const& d1 = static_cast<Derived const&>(op1);
    Derived const& d2 = static_cast<Derived const&>(op2);
    return d2 < d1;
}

template <class Derived>
bool operator == (Relational<Derived> const& op1, Relational<Derived> const & op2){
    Derived const& d1 = static_cast<Derived const&>(op1);
    Derived const& d2 = static_cast<Derived const&>(op2);
    return !(d1 < d2) && !(d2 < d1);
}

template <class Derived>
bool operator != (Relational<Derived> const& op1, Relational<Derived> const & op2){
    Derived const& d1 = static_cast<Derived const&>(op1);
    Derived const& d2 = static_cast<Derived const&>(op2);
    return (d1 < d2) || (d2 < d1);
}

template <class Derived>
bool operator <= (Relational<Derived> const& op1, Relational<Derived> const & op2){
    Derived const& d1 = static_cast<Derived const&>(op1);
    Derived const& d2 = static_cast<Derived const&>(op2);
    return (d1 < d2) || (d1 == d2);
}

template <class Derived>
bool operator >= (Relational<Derived> const& op1, Relational<Derived> const & op2){
    Derived const& d1 = static_cast<Derived const&>(op1);
    Derived const& d2 = static_cast<Derived const&>(op2);
    return (d1 > d2) || (d1 == d2);
}

// Apple

class Apple:public Relational<Apple>{
public:
    explicit Apple(int s): size{s}{};
    friend bool operator < (Apple const& a1, Apple const& a2){
        return a1.size < a2.size;
    }
private:
    int size;
};

// Man

class Man:public Relational<Man>{
public:
    explicit Man(const std::string& n): name{n}{}
    friend bool operator < (Man const& m1, Man const& m2){
        return m1.name < m2.name;
    }
private:
    std::string name;
};

int main(){

    std::cout << std::boolalpha << std::endl;

    Apple apple1{5};
    Apple apple2{10};
    std::cout << "apple1 < apple2: " << (apple1 < apple2) << std::endl;
    std::cout << "apple1 > apple2: " << (apple1 > apple2) << std::endl;
    std::cout << "apple1 == apple2: " << (apple1 == apple2) << std::endl;
    std::cout << "apple1 != apple2: " << (apple1 != apple2) << std::endl;
    std::cout << "apple1 <= apple2: " << (apple1 <= apple2) << std::endl;
    std::cout << "apple1 >= apple2: " << (apple1 >= apple2) << std::endl;

    std::cout << std::endl;

    Man man1{"grimm"};
    Man man2{"jaud"};
    std::cout << "man1 < man2: " << (man1 < man2) << std::endl;
    std::cout << "man1 > man2: " << (man1 > man2) << std::endl;
    std::cout << "man1 == man2: " << (man1 == man2) << std::endl;
    std::cout << "man1 != man2: " << (man1 != man2) << std::endl;
    std::cout << "man1 <= man2: " << (man1 <= man2) << std::endl;
    std::cout << "man1 >= man2: " << (man1 >= man2) << std::endl;

    std::cout << std::endl;

}

/*
 * We have implemented, for the classes Apple and Man, the smaller operators separately (lines 51-52 and 63-64).
 * The classes Man and Apple are publicly derived (lines 48 and 60) from the class Relational<Man> and Ralational<Apple>.
 * For classes of the kind Relational, we have implemented the greater than operator > (lines 11 – 16), the equality o
 * perator == (lines 18 – 23), the not equal to operator != (lines 25 – 30), the less than or equal to operator
 * <= (line 32 – 37) and the greater than or equal to operator >= (lines 39 – 44). The less than or equal (<=) and
 * greater than or equal to (>=) operators used the equality operator == (line 36 and 43). All these operators convert
 * their operands: Derived const&: Derived const& d1 = static_cast<Derived const&>(op1).

In the main program, we have compared the Apple and Man classes for all the above-mentioned operators.

 */