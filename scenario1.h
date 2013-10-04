/*
Scenario 1:

Given Base class has no virtual members
And Base's destructor is not virtual
And Derived class has no virtual members
When you delete derived class by pointer to base class (e.g. Base *pb = Derived(); delete pb;)
Then Derived's destructor isn't called
But no memory leak occurs.
*/

#include <iostream>


namespace scenario1 {
    class Base {
    public:
        Base() {
            std::cout << "Base::Base()" << std::endl;
        }

        ~Base() {
            std::cout << "Base::~Base()" << std::endl;
        }

	    void foo() {
		    std::cout << "Base::foo()" << std::endl;
	    }
    };

    class Derived : public Base {
    public:
        Derived() {
            std::cout << "Derived::Derived()" << std::endl;
        }

        ~Derived() {
            std::cout << "Derived::~Derived()" << std::endl;
        }

	    void foo() {
		    std::cout << "Derived::foo()" << std::endl;
	    }

        void new_method() {
		    std::cout << "Derived::new_method()" << std::endl;
        }
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
        std::cout << "--- scenario1::for_base ---" << std::endl;
	    for_base();
        std::cout << "--- scenario1::for_derived ---" << std::endl;
	    for_derived();
        std::cout << "--- scenario1::for_base_pointer ---" << std::endl;
        for_base_pointer();
    }
}
