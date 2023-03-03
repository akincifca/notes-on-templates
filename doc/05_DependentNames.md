## Dependent Names
A dependent name is essentially a name that depends on a template parameter. A dependent name can be a type, a non-type, 
or a template-template parameter.

If a dependent name is used in a template declaration or template definition, the compiler has no idea whether this name 
refers to a type, a non-type, or a template parameter. In this case, the compiler assumes that the dependent name refers 
to a non-type, which may be wrong.

Let’s have a look at an example of dependent names:
```c++
template<typename T>
struct X : B<T>   // "B<T>" is dependent on T
{
    typename T::A* pa;   // "T::A" is dependent on T
    void f(B<T>* pb) {
        static int i = B<T>::i;    // "B<T>::i" is dependent on T
        pb->j++;    // "pb->j" is dependent on T
    }
};
```

T is the template parameter. The names B<T>, T::A, B<T>, B<T>::i, and pb->j are dependent.

### Two phase name lookup

* Dependent names are resolved during template instantiation.
* Non-dependent names are resolved during template definition.

A from a template parameter T is dependent; the qualified name T::A can be a

* type
* non type
* template

```
The compiler assumes by default that T::A is a non-type.
```
The compiler has to be convinced that T::A is a type or a template.

### The Dependent Name is a Type typename#

```c++
template <typename T> void test(){
  std::vector<T>::const_iterator* p1;          // ERROR
  typename std::vector<T>::const_iterator* p2; //OK
}
```

Without typename like in line 3, the expression in line 2 would be interpreted as multiplication.

### The Dependent Name is a Template .template#

```c++
template<typename T>
struct S{
  template <typename U> void func(){}
}

template<typename T>
void func2(){
  S<T> s;
  s.func<T>();             // ERROR
  s.template func<T>();    // OK
}
```

Compare lines 9 and 10. When the compiler reads the name s.func (line 9), it decides to interpret it as non-type. 
In this case, the < sign stands for the comparison operator, not the opening square bracket of the template argument 
of the generic method func. To help the parser, specify that s.func is a template like in line 10: s.template func.