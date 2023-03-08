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

// Implement a person class here

// Person

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

class Person: public Relational<Person>{
public:
    Person(std::string fst, std::string sec): first(fst), last(sec){}
    friend bool operator < (Person const& p1, Person const& p2){
        return std::make_pair(p1.first, p2.last) < std::make_pair(p2.first, p2.last);
    }
private:
    std::string first;
    std::string last;
};

int main(){

    std::cout << std::boolalpha << std::endl;

    // Call Person class object here checks them for all relational operaotrs
    Person rainer{"Rainer", "Grimm"};
    Person marius{"Marius", "Grimm"};
    std::cout << "rainer < marius: " << (rainer < marius) << std::endl;
    std::cout << "rainer > marius: " << (rainer > marius) << std::endl;
    std::cout << "rainer == marius: " << (rainer == marius) << std::endl;
    std::cout << "rainer != marius: " << (rainer != marius) << std::endl;
    std::cout << "rainer <= marius: " << (rainer <= marius) << std::endl;
    std::cout << "rainer >= marius: " << (rainer >= marius) << std::endl;

    std::cout << std::endl;

}

/*
 * Extend the given piece of code with a Person class. A Person should have a first and last name.

We need to create two objects of the Person class and compare these objects using relational operators.
 */
