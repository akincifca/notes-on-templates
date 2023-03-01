#include <iostream>

using namespace std;
// Write class templates for given commented code

template <char c>
class AcceptChar {
public:
    AcceptChar() {
        cout << "AcceptChar() " << typeid(c).name() << endl;
    }
};

template <void (*func)(int)>
class AcceptFunction {
public:
    AcceptFunction() {
        cout << "AcceptFunction() " << typeid(func).name() << endl;
    }
};

template <int(&arr)[5]>
class AcceptReference {
public:
    AcceptReference() {
        cout << "AcceptReference() " << typeid(arr).name() << endl;
    }
};

template <std::nullptr_t p>
class AcceptNullptr {
public:
    AcceptNullptr() {
        cout << "AcceptNullptr() " << typeid(p).name() << endl;
    }
};

void myFunc(int) {}
int arr[5];
int main() {
    // uncomment these lines after implementing codes


    AcceptChar<'c'> acceptChar;
    AcceptFunction< myFunc> acceptFunction;
    AcceptReference< arr > acceptReference;
    AcceptNullptr< nullptr > acceptNullptr;

}