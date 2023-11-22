// CPP program without virtual destructor causing undefined behavior
#include <iostream>
using namespace std;

/*
Deleting a derived class object using a pointer of base class type that has a non-virtual destructor results in undefined behavior. 
To correct this situation, the base class should be defined with a virtual destructor. 
For example, the following program results in undefined behavior. 
*/

class base {
public:
	base()	 
	{ cout << "UnsafeDesign: Constructing base\n"; }
	~base()
	{ cout<< "UnsafeDesign: Destructing base\n"; }	 
};

class derived: public base {
public:
	derived()	 
	{ cout << "UnsafeDesign: Constructing derived\n"; }
	~derived()
	{ cout << "UnsafeDesign: Destructing derived\n"; } // This function won't be called.
};

void unsafeCall()
{
    derived *d = new derived(); 
    base *b = d;
    delete b;

    cout<< endl;

    /* Output:
        Constructing base
        Constructing derived
        Destructing base
    */

   // Error: derived class object not deleted. Potential memory leak possible.
}


/*
Making base class destructor virtual guarantees that the object of derived class is destructed properly, i.e., both base class and derived class destructors are called. For example, 
*/

// A program with virtual destructor
class baseSafe {
public:
	baseSafe()	 
	{ cout << "SafeDesign: Constructing base\n"; }
	virtual ~baseSafe()
	{ cout << "SafeDesign: Destructing base\n"; }	 
};

class derivedSafe : public baseSafe {
public:
	derivedSafe()	 
	{ cout << "SafeDesign: Constructing derived\n"; }
	~derivedSafe()
	{ cout << "SafeDesign: Destructing derived\n"; }
};

void safeCall()
{
    derivedSafe *d = new derivedSafe(); 
    baseSafe *b = d;
    delete b;

    /*
    Constructing base
    Constructing derived
    Destructing derived
    Destructing base
    */
}


int main(){
    unsafeCall();
    safeCall();

    return 0;
}


//As a guideline, any time you have a virtual function in a class, you should immediately add a virtual destructor (even if it does nothing). This way, you ensure against any surprises later. 
