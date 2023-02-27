## Friends
Friends of a class template have access to all members of the class template.

A class or a class template can have a friendship to class or class templates, function or function templates, and types.

**Rules:**
1. The declaration of friends can be made at an arbitrary place in the class declaration. 
2. The access rights in the class have no influence. 
3. Friendship is not inherited. 
4. Friendship is not transitive.

```
A friend has unrestricted access to the members of the class.
```

### General Friends
A class or a class template can grant friendship to each instance of a class template or a function template.

```c++
template <typename T> int myFriendFunction(T); 

template <typename T> class MyFriend;

template <typename T> 
class GrantingFriendshipAsClassTemplate{
  template <typename U> friend int myFriendFunction(U); 
  template <typename U> friend class MyFriend; 
  ...
```

```
When a class template grants friendship to a template using the same template parameter name, the friendship is granted 
only for the same types. If the intention is to grant friendship for any type of template parameter, the template 
parameter names should be different.
```

### Special Friends

A special friendship is a friendship that depends on the type of the template parameter.



```c++
template <typename T> int myFriendFunction(T);
template <typename T> class MyFriend;

template <typename T>
class GrantingFriendshipAsClassTemplate{
  friend int myFriendFunction<>(double);
  friend class MyFriend<int>
  friend class MyFriend<T>;
```
If the name of the template parameter is identical to the name of the template parameter granting the friendship, 
the friendship will be between instances of the same type.




