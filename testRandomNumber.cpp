// C++ program to illustrate the use of 
// operator(), min and max
// in random_device 
#include <iostream>
#include <random>
using namespace std;

//Driver program
int main ()
{
	random_device example;
	
	cout << "default random_device characteristics:" << endl;
	
	// use of min
	cout << "minimum: " << example.min() << endl;
	
	// use of max
	cout << "maximum: " << example.max() << endl;
	
	// use of entropy
	cout << "entropy: " << example.entropy() << endl;
	
	// use of operator()
	cout << "a random number: " << example() << endl;


    int randomNum = example();
    cout << "Random Number " << randomNum << endl;
	
	return 0;
}
