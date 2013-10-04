/*
Scenario 3:

Given Base class has virtual member
And Base's destructor is virtual
And Derived class has another more virtual member
When you delete derived class by pointer to base class (e.g. Base *pb = Derived(); delete pb;)
Then Derived's destructor is called
And no memory leak occurs.
*/

#include <iostream>


namespace scenario3 {
    class Base {
    public:
        Base() {
            std::cout << "Base::Base()" << std::endl;
        }

        virtual ~Base() {
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
        }

        ~Derived() {
            std::cout << "Derived::~Derived()" << std::endl;
        }

	    void foo() {
		    std::cout << "Derived::foo()" << std::endl;
	    }

        virtual void new_method() {
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
        std::cout << "--- scenario3::for_base ---" << std::endl;
	    for_base();
        std::cout << "--- scenario3::for_derived ---" << std::endl;
	    for_derived();
        std::cout << "--- scenario3::for_base_pointer ---" << std::endl;
        for_base_pointer();
    }
}
