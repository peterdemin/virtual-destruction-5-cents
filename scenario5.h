/*
Scenario 5:

Given Base class has virtual member
But Base's destructor is not virtual
And Derived class has one more dynamic member
When you delete derived class by pointer to base class (e.g. Base *pb = Derived(); delete pb;)
Then Derived's destructor isn't called
And new member leaks memory.
*/

#include <iostream>


namespace scenario5 {
    class Base {
    public:
        Base() {
            std::cout << "Base::Base()" << std::endl;
        }

        ~Base() {
            std::cout << "Base::~Base()" << std::endl;
        }

	    virtual void foo() {
		    std::cout << "Base::foo()" << std::endl;
	    }
    };

    class Derived : public Base {
    public:
        Derived() {
            std::cout << "Derived::Derived()" << std::endl;
            new_member = new Base();
        }

        ~Derived() {
            std::cout << "Derived::~Derived()" << std::endl;
            delete new_member;
        }

	    void foo() {
		    std::cout << "Derived::foo()" << std::endl;
	    }

        Base *new_member;
    };

    void for_base() {
	    Base b;
	    b.foo();
    }

    void for_derived() {
	    Derived d;
	    d.foo();
    }

    void for_base_pointer() {
        Base *pb = new Derived();
        pb->foo();
        delete pb;
    }

    void run_all() {
        std::cout << "--- scenario5::for_base ---" << std::endl;
	    for_base();
        std::cout << "--- scenario5::for_derived ---" << std::endl;
	    for_derived();
        std::cout << "--- scenario5::for_base_pointer ---" << std::endl;
        for_base_pointer();
    }
}
