## Function Templates
A function template is defined by the keyword template followed by type or non-type parameters in front of a 
concrete function. After that, replace the concrete types or non-types with the type or non-type parameters in 
the function.

* The keywords class or typename declare the parameters.
* The name T is usually used for the first parameter.
* The parameters can be used in the body of the function.

### Overloading
Function templates can be overloaded.

The following rules hold:

1. Templates do not support automatic type conversion.
2. If a free function is better or equally as good as a function template that already exists, the free function can be used.
3. The type of the function template can be specified explicitly.

```func<type>(...)```
4. We can specify that we are only interested in a specific instantiation of a function template.

```func<>(...)```
