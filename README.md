virtual-destruction-5-cents
===========================

Overview
--------

According to [StackOverflow question](http://stackoverflow.com/q/19174529/135079)
The general rule can be expressed in pseudo-code:

```
if static type of object is different from its dynamic type:
    if the static type is a base class of the dynamic type:
        if the static type has a virtual destructor:
            We're fine - dynamic type's destructor will be called
        else:
            behavior is undefined [1]
    else:
        behavior is undefined [2]
```

[1] Code will compile without warnings and probably will work fine,
but it's not guaranteed and may cause entangled error at runtime.

[2] That means code is something like:

```cpp
class A {};
class B {};
B *a = (B*)(new A());
delete a;
```

Scenarios
---------

```cucumber
Scenario 1: Entangled undefined behaviour

Given Base class has no virtual members
And Base's destructor is not virtual
And Derived class has no virtual members
When you delete derived class by pointer to base class (e.g. Base *pb = Derived(); delete pb;)
Then Derived's destructor isn't called
But no memory leak occurs.
```

```cucumber
Scenario 2: Entangled undefined behaviour

Given Base class has virtual member
And Base's destructor is not virtual
And Derived class has another more virtual member
When you delete derived class by pointer to base class (e.g. Base *pb = Derived(); delete pb;)
Then Derived's destructor isn't called
But no memory leak occurs.
```

```cucumber
Scenario 3: The correct one

Given Base class has virtual member
And Base's destructor is virtual
And Derived class has another more virtual member
When you delete derived class by pointer to base class (e.g. Base *pb = Derived(); delete pb;)
Then Derived's destructor is called
And no memory leak occurs.
```

```cucumber
Scenario 4: Runtime error

Given Base class has no virtual member
And Base's destructor is not virtual
And Derived class has virtual member
When you delete derived class by pointer to base class (e.g. Base *pb = Derived(); delete pb;)
Then Derived's destructor is not called
Derived's virtual table leaks memory which causes assertion fail.
```

```cucumber
Scenario 5: Memory leak

Given Base class has virtual member
But Base's destructor is not virtual
And Derived class has one more dynamic member
When you delete derived class by pointer to base class (e.g. Base *pb = Derived(); delete pb;)
Then Derived's destructor isn't called
And new member leaks memory.
```

How to build
------------

```shell
mkdir build
cd build
cmake ..
```
