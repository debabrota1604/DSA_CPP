#include <stdio.h> 

/*
Unlike normal pointers, a function pointer points to code, not data. Typically a function pointer stores the start of executable code.

Unlike normal pointers, we do not allocate de-allocate memory using function pointers.


*/

// A normal function with an int parameter 
// and void return type 
void fun(int a) 
{ 
	printf("Value of a is %d\n", a); 
} 

int main() 
{ 
	// fun_ptr is a pointer to function fun() 
	void (*fun_ptr)(int) = &fun; 

	/* The above line is equivalent of following two 
	void (*fun_ptr)(int); 
	fun_ptr = &fun; 
	*/

	// Invoking fun() using fun_ptr 
	(*fun_ptr)(10); 


    /*
    A function’s name can also be used to get functions’ address. For example, in the below program, we have removed address operator ‘&’ in assignment. We need to also change function call by removing *, the program still works.

    void (*fun_ptr)(int) = fun;  // & removed 
    fun_ptr(10);  // * removed 
    */

	return 0; 
} 
