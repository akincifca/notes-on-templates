## CRTP

The acronym CRTP stands for the C++ idiom Curiously Recurring Template Pattern. It is a technique in C++ in which 
a Derived class derives from a class template Base. The key is that Base has Derived as a template argument.

Let’s have a look at an example:

```c++
template<class T> 
class Base{
   ...
};

class Derived: public Base<Derived>{ 
   ...
};
```

CRTP enables static polymorphism.

### Typical use-case

There are two typical use-cases for CRTP: Mixins and static polymorphism.

#### Mixins

Mixins are a popular concept in the design of classes used to mix in new code. Therefore, 
it’s a technique often used in Python to change the behavior of a class by using multiple inheritances. 
In contrast to C++, it is legal in Python to have more than one definition of a method in a class hierarchy. 
Python simply uses the first method in the Method Resolution Order (MRO).

We can implement mixins in C++ by using CRTP. A prominent example is the class std::enable_shared_from_this. 
Using this class, we can create objects that return an std::shared_ptr with themselves. We have to derive the public 
class MySharedClass from std::enable_shared_from_this. Now, our MySharedClass has a method called shared_from_this.

An additional common use-case for mixins is a class that we want to extend with the capability that their instances 
support the comparison for equality and inequality.

#### Static polymorphism

Static polymorphism is quite similar to dynamic polymorphism. But contrary to dynamic polymorphism with virtual methods, 
the dispatch of the method calls will take place at compile-time. Now, we are at the center of the CRTP idiom.

```c++
class ShareMe: public std::enable_shared_from_this<ShareMe>{
  std::shared_ptr<ShareMe> getShared(){
    return shared_from_this();
  } 
};
```

* std::enable_shared_from_this creates a shared _ptr for an object.
* std::enable_shared_from_this: is the base class of the object.
* shared_from_this: returns the shared object.

