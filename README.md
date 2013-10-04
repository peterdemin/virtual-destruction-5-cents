virtual-destruction-5-cents
===========================

My 5 cents to C++ virtual destructors (Examples)

```cucumber
Scenario 1:

Given Base class has no virtual members
And Base's destructor is not virtual
And Derived class has no virtual members
When you delete derived class by pointer to base class (e.g. Base *pb = Derived(); delete pb;)
Then Derived's destructor isn't called
But no memory leak occurs.
```

```cucumber
Scenario 2:

Given Base class has virtual member
And Base's destructor is not virtual
And Derived class has another more virtual member
When you delete derived class by pointer to base class (e.g. Base *pb = Derived(); delete pb;)
Then Derived's destructor isn't called
But no memory leak occurs.
```

```cucumber
Scenario 3:

Given Base class has virtual member
And Base's destructor is virtual
And Derived class has another more virtual member
When you delete derived class by pointer to base class (e.g. Base *pb = Derived(); delete pb;)
Then Derived's destructor is called
And no memory leak occurs.
```

```cucumber
Scenario 4:

Given Base class has no virtual member
And Base's destructor is not virtual
And Derived class has virtual member
When you delete derived class by pointer to base class (e.g. Base *pb = Derived(); delete pb;)
Then Derived's destructor is not called
Derived's virtual table leaks memory which causes assertion fail.
```

```cucumber
Scenario 5:

Given Base class has virtual member
But Base's destructor is not virtual
And Derived class has one more dynamic member
When you delete derived class by pointer to base class (e.g. Base *pb = Derived(); delete pb;)
Then Derived's destructor isn't called
And new member leaks memory.
```
