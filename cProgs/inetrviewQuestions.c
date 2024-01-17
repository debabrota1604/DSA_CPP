/*
Resource: https://www.interviewbit.com/c-interview-questions/
/*
What is an r-value and l-value?
The term "r-value" refers to a data value stored in memory at a given address. An r-value is an expression that cannot have a value assigned to it, hence it can only exist on the right side of an assignment operator(=).
The term "l-value" refers to a memory location that is used to identify an object. The l-value can be found on either the left or right side of an assignment operator(=). l-value is frequently used as an identifier.


l-value or location value refers to an expression that can be used on left side of assignment operator. For example in expression “a = 3”, a is l-value and 3 is r-value. 
l-values are of two types: 
“nonmodifiable l-value” represent a l-value that can not be modified. const variables are “nonmodifiable l-value”. 
“modifiable l-value” represent a l-value that can be modified.

More info: https://www.geeksforgeeks.org/lvalue-and-rvalue-in-c-language/
*/


/*
What is the difference between malloc() and calloc()?
calloc() and malloc() are memory dynamic memory allocating functions. 
The main difference is that malloc() only takes one argument, which is the number of bytes, but calloc() takes two arguments, which are the number of blocks and the size of each block.
*/

/*
What is the difference between struct and union in C?
A struct is a group of complex data structures stored in a block of memory where each member on the block gets a separate memory location to make them accessible at once
Whereas in the union, all the member variables are stored at the same location on the memory as a result to which while assigning a value to a member variable will change the value of all other members.\
*/

void struct_union_example(){
    /* struct & union definations*/
    struct bar {
        int a;	// we can use a & b both simultaneously
        char b;
    }	bar;

    union foo {
        int a;	// we can't use both a and b simultaneously
        char b;
    }	foo;

    /* using struc and union variables*/

    struct bar y;
    y.a = 3;	// OK to use
    y.b = 'c'; // OK to use

    union foo x;
    x.a = 3; // OK
    x.b = 'c'; // NOl this affects the value of x.a!
}


/*
What is Dynamic memory allocation in C? Name the dynamic allocation functions.
C is a language known for its low-level control over the memory allocation of variables in DMA there are two major standard library malloc() and free. The malloc() function takes a single input parameter which tells the size of the memory requested It returns a pointer to the allocated memory. If the allocation fails, it returns NULL. The prototype for the standard library function is like this:
void *malloc(size_t size);

The free() function takes the pointer returned by malloc() and de-allocates the memory. No indication of success or failure is returned. The function prototype is like this: 
void free(void *pointer);

There are 4 library functions provided by C defined under <stdlib.h> header file to facilitate dynamic memory allocation in C programming. They are:
        malloc()
        calloc()
        free()
        realloc()
*/


/*
What is typedef?
typedef is a C keyword, used to define alias/synonyms for an existing type in C language. In most cases, we use typedef's to simplify the existing type declaration syntax. Or to provide specific descriptive names to a type.
    typedef <existing-type> <new-type-identifiers>;
typedef provides an alias name to the existing complex type definition. With typedef, you can simply create an alias for any type. Whether it is a simple integer to complex function pointer or structure declaration, typedef will shorten your code.
*/


/*
Why is it usually a bad idea to use gets()? Suggest a workaround.
The standard input library gets() reads user input till it encounters a new line character. However, it does not check on the size of the variable being provided by the user is under the maximum size of the data type which makes the system vulnerable to buffer overflow and the input being written into memory where it isn’t supposed to.
We, therefore, use gets() to achieve the same with a restricted range of input
Bonus: It remained an official part of the language up to the 1999 ISO C standard, but it was officially removed by the 2011 standard. Most C implementations still support it, but at least GCC issues a warning for any code that uses it.

*/


/*
What is the difference between #include "..." and #include <...>?
In practice, the difference is in the location where the preprocessor searches for the included file.

For #include <filename> the C preprocessor looks for the filename in the predefined list of system directories first and then to the directories told by the user(we can use -I option to add directories to the mentioned predefined list). 

For #include "filename" the preprocessor searches first in the same directory as the file containing the directive, and then follows the search path used for the #include <filename> form. This method is normally used to include programmer-defined header files.
*/

/*
What is Dangling pointer?
Dangling Pointer is a pointer that doesn’t point to a valid memory location. Dangling pointers arise when an object is deleted or deallocated, without modifying the value of the pointer, so that the pointer still points to the memory location of the deallocated memory. Following are examples.
The dangling pointer points to a memory that has already been freed. The storage is no longer allocated. Trying to access it might cause a Segmentation fault. A common way to end up with a dangling pointer:
*/

// EXAMPLE 1 
void danglingPointerExample1(){ // Accessing memory after calling free()
    int* ptr = (int*)malloc(sizeof(int)); 
    //some code in between
    free(ptr); 
    //some code in between

    // ptr is a dangling pointer now and operations like following are invalid 
    *ptr = 10; // or printf("%d", *ptr); 
}


// EXAMPLE 2 
void danglingPointerExample2(){ // Accessing local memory outside it's scope
    int* ptr = NULL ;
    { 
        int x = 10; 
        ptr = &x; 
    } 
    // x goes out of scope and memory allocated to x is free now. 
    // So ptr is a dangling pointer now. 
}

char* danglingPointerExample3() // Accessing local memory outside it's scope
{
    char str[10];
    strcpy(str,"Hello!");
    return(str);
}
//You are returning an address that was a local variable, which would have gone out of scope by the time control was returned to the calling function. (Undefined behavior)

void danglingPointerDemo2(){
    int* c = malloc(sizeof(int));
    free(c);
    *c = 3; //writing to freed location!
}

/*
How are dangling pointers different from memory leaks?

In the example shown above writing to a memory that has been freed is an example of the dangling pointer, which makes the program crash.

A memory leak is something where the memory allocated is not freed which causes the program to use an undefined amount of memory from the ram making it unavailable for every other running program(or daemon) which causes the programs to crash. There are various tools like O profile testing which is useful to detect memory leaks on your programs.

Memory leak occurs when programmers create a memory in heap and forget to delete it. Memory leaks are particularly serious issues for programs like daemons and servers which by definition never terminate.

When we assign a variable it takes space of our RAM (either heap or RAM)dependent on the size of data type, however, if a programmer uses a memory available on the heap and forgets to a delta it, at some point all the memory available on the ram will be occupied with no memory left this can lead to a memory leak.
*/

void memoryLeakDemo(){
	char *leak = malloc (10);	//leak assigned but not freed
}

void memoryLeakDemo2() 
{ 
    int* ptr = (int*)malloc(sizeof(int)); 
  
    /* Do some work */
  
    return; /* Return without freeing ptr*/
} 
int memoryLeakDemo3(){
    char * ptr = malloc(sizeof(int));
    
    /* Do some work */
    /*Not freeing the allocated memory*/
    return 0;
}
//To avoid memory leaks, you can trace all your memory allocations and think forward, where you want to destroy (in a good sense) that memory and place delete there. Another way is to use C++ smart pointer in C linking it to GNU compilers.

/*
What is the difference between ‘g’ and “g” in C?
In C double-quotes variables are identified as a string whereas single-quoted variables are identified as the character. Another major difference being the string (double-quoted) variables end with a null terminator that makes it a 2 character array.
*/


/*
What is a near pointer and a far pointer in C?
Near Pointer: In general, the near pointer can be considered because it is used to hold the address, which has a maximum size of just 16 bits. We can't store an address with a size larger than 16 bits using the near pointer. All other smaller addresses that are within the 16-bit limit, on the other hand, can be stored. Because we can only access 64kb of data at a time, you might assume the 16 bits are insufficient. As a result, it is regarded as one of the near-pointer's biggest drawbacks, which is why it is no longer commonly used.
Far Pointer: A far pointer is considered a pointer of size 32 bits. It can, however, use the current segment to access information stored outside the computer's memory. Although, in order to use this type of pointer, we usually need to allocate the sector register to store the data address in the current segment.

These type of pointers are used in windows systems.
*/

/*
Which structure is used to link the program and the operating system?
The file structure is used to link the operating system and a program. The header file "stdio.h" (standard input/output header file) defines the file. It contains information about the file being used like its current size and its memory location. It contains a character pointer that points to the character which is currently being opened. When you open a file, it establishes a link between the program and the operating system about which file is to be accessed.
*/


/*
Suppose a global variable and local variable have the same name. Is it possible to access a global variable from a block where local variables are defined?
No. This isn’t possible in C. It’s always the most local variable that gets preference.
*/

/*
Which is better #define or enum?
    If we let it, the compiler can build enum values automatically. However, each of the defined values must be given separately.
    Because macros are preprocessors, unlike enums, which are compile-time entities, the source code is unaware of these macros. So, if we use a debugger to debug the code, the enum is superior.
    Some compilers will give a warning if we use enum values in a switch and the default case is missing.
    Enum always generates int-type identifiers. The macro, on the other hand, allowed us to pick between various integral types.
    Unlike enum, the macro does not have a defined scope constraint.
*/


/*
Can we compile a program without a main() function?
Yes, we can compile a program without main() function Using Macro.

#include<studio.h>
#define abc main
int abc ()
{
printf("Hello World ");
return 0;
}

*/

//Write a program to get the higher and lower nibble of a byte without using shift operator?
struct full_byte
{
    char first : 4;
    char second : 4;
};

union A
{
    char x;
    struct full_byte by;
};

void getHigherLowerNibble()
{
    char c = 100;
    union A a;
    a.x = c;
    printf("the two nibbles are: %d and %d\n", a.by.first, a.by.second);
}


/*
How do you override a defined macro?
To override a defined macro we can use #ifdef and #undef preprocessors as follows:

#ifdef A
#undef A
#endif
#define A 10
If macro A is defined, it will be undefined using undef and then defined again using define.

*/



/*
How to call a function before main()?
To call a function before the main(), pragma startup directive should be used. E.g.-
*/
#pragma startup fun
void fun()
{
    printf("In fun\n");
}
int mainFunction() //consider this as the "int main()"
{
    printf("In main\n");
}
/*
The output of the above program will be -
In fun
In main

This pragma directive, on the other hand, is compiler-dependent. This is not supported by gcc. As a result, it will ignore the startup directive and produce no error. But the output, in that case, will be -

In main
*/

// Source: https://www.geeksforgeeks.org/c-interview-questions/

/*
What are preprocessor directives in C?
In C preprocessor directives are considered the built-in predefined functions or macros that act as a directive to the compiler and are executed before the program execution. There are multiple steps involved in writing and executing a program in C. Main types of Preprocessor Directives are Macros, File Inclusion, Conditional Compilation, and Other directives like #undef, #pragma, etc.

More info here: https://www.geeksforgeeks.org/cc-preprocessors/

*/



/*
What is the use of static variables in C?
Static variables in the C programming language are used to preserve the data values between function calls even after they are out of their scope. Static variables preserve their values in their scope and they can be used again in the program without initializing again. Static variables have an initial value assigned to 0 without initialization.
*/
// C program to print initial value of static variable 
#include <stdio.h> 
int staticDemo() 
{ 
	static int var; 
	int x; 
	printf("Initial value of static variable %d\n", var); 
	printf("Initial value of variable without static %d", 
		x); 
	return 0; 
}
/*
Output:
Initial value of static variable 0
Initial value of variable without static 0


*/

/*
What is a volatile keyword?
Volatile keyword is used to prevent the compiler from optimization because their values can’t be changed by code that is outside the scope of current code at any time. The System always reads the current value of a volatile object from the memory location rather than keeping its value in a temporary register at the point it is requested, even if previous instruction is asked for the value from the same object. 

The volatile keyword is intended to prevent the compiler from applying any optimizations on objects that can change in ways that cannot be determined by the compiler. 
Objects declared as volatile are omitted from optimization because their values can be changed by code outside the scope of current code at any time. 

The proper use of volatile specifier is when an external io register is memory mapped that can change independently from the current code, hence should not cache it. Another use can be when the same variable is shared by multiple threads, then also it should not be cached, as other thread can change the value in memory invalidating the cache value.

More info : https://www.geeksforgeeks.org/understanding-volatile-qualifier-in-c/
*/

/*
Can a variable be both const and volatile? 
yes, the const means that the variable cannot be assigned a new value. The value can be changed by other code or pointer. For example the following program works fine. 
 This combination is rare but can be useful in certain situations where you want to indicate that a value is read-only and should not be modified by the code, but it can change at any time due to external factors.
*/

// Example 1
void volativeConstCheck()
{
    const volatile int local = 10;
    int* ptr = (int*)&local; // Can use const_cast also to remove const-ness
    printf("Initial value of local : %d \n", local);
    *ptr = 100;
    printf("Modified value of local: %d \n", local);
}


// Example 2
const volatile int* hardwareStatus = (const volatile int*)0x1000;  // Memory-mapped hardware status register
int readRegister() {
    int status = *hardwareStatus;  // Read the hardware status
    // ...
    return 0;
}



/*
What is an auto keyword?
Every local variable of a function is known as an automatic variable in the C language. Auto is the default storage class for all the variables which are declared inside a function or a block. Auto variables can only be accessed within the block/function they have been declared. We can use them outside their scope with the help of pointers. By default auto keywords consist of a garbage value. 

For more information, refer to the article – https://www.geeksforgeeks.org/storage-classes-in-c/
*/

/*
Explain modifiers.
Modifiers are keywords that are used to change the meaning of basic data types in C language. They specify the amount of memory that is to be allocated to the variable. There are five data type modifiers in the C programming language:

long
short
signed
unsigned
long long

*/


/*
What is the use of an extern storage specifier?
The extern keyword is used to extend the visibility of the C variables and functions in the C language. Extern is the short name for external. It is used when a particular file needs to access a variable from any other file. Extern keyword increases the redundancy and variables with extern keyword are only declared not defined. By default functions are visible throughout the program, so there is no need to declare or define extern functions.
*/


/*
What is the difference between getc(), getchar(), getch() and getche().
getc(): The function reads a single character from an input stream and returns an integer value (typically the ASCII value of the character) if it succeeds. On failure, it returns the EOF.
getchar(): Unlike getc(), gechar() can read from standard input; it is equivalent to getc(stdin).
getch(): It is a nonstandard function and is present in ‘conio.h’ header file which is mostly used by MS-DOS compilers like Turbo C. 
getche(): It reads a single character from the keyboard and displays it immediately on the output screen without waiting for enter key.
*/

/*
Write a Program in C to Print all natural numbers up to N without using a semi-colon.
*/
#define N 10 
int allNumUptoN(int val) 
{ 
	if (val <= N && printf("%d ", val) && main(val + 1)) { 
	} 
}


/*
What is the difference between declaration and definition of a variable/function
Ans: Declaration of a variable/function simply declares that the variable/function exists somewhere in the program but the memory is not allocated for them. But the declaration of a variable/function serves an important role. And that is the type of the variable/function. Therefore, when a variable is declared, the program knows the data type of that variable. In case of function declaration, the program knows what are the arguments to that functions, their data types, the order of arguments and the return type of the function. So that’s all about declaration. Coming to the definition, when we define a variable/function, apart from the role of declaration, it also allocates memory for that variable/function. Therefore, we can think of definition as a super set of declaration. (or declaration as a subset of definition).

*/

// This is only declaration. y is not allocated memory by this statement
extern int y;

// This is both declaration and definition, memory to x is allocated by this statement.
int x;


/*
What are local static variables? What is their use?
Ans:A local static variable is a variable whose lifetime doesn’t end with a function call where it is declared. It extends for the lifetime of complete program. All calls to the function share the same copy of local static variables. Static variables can be used to count the number of times a function is called. Also, static variables get the default value as 0. For example, the following program prints “0 1”
*/

void staticTest1() 
{ 
    // static variables get the default value as 0. 
    static int x; 
    printf("%d ", x); 
    x = x + 1; 
} 
  
int callerFunction() 
{ 
    fun(); 
    fun(); 
    return 0; 
} 
// Output: 0 1

/*
What are static functions? What is their use?
Ans:In C, functions are global by default. The “static” keyword before a function name makes it static. Unlike global functions in C, access to static functions is restricted to the file where they are declared. Therefore, when we want to restrict access to functions, we make them static. Another reason for making functions static can be reuse of the same function name in other files. 
*/


/*
Difference between ++*p, *p++ and *++p? 
1) Precedence of prefix ++ and * is same. Associativity of both is right to left. 
2) Precedence of postfix ++ is higher than both * and prefix ++. Associativity of postfix ++ is left to right.
(Refer: Precedence Table)
The expression ++*p has two operators of same precedence, so compiler looks for associativity. Associativity of operators is right to left. Therefore the expression is treated as ++(*p). Therefore the output of first program is “arr[0] = 10, arr[1] = 20, *p = 11“.
The expression *p++ is treated as *(p++) as the precedence of postfix ++ is higher than *. Therefore the output of second program is “arr[0] = 10, arr[1] = 20, *p = 20“.
The expression *++p has two operators of same precedence, so compiler looks for associativity. Associativity of operators is right to left. Therefore the expression is treated as *(++p). Therefore the output of third program is “arr[0] = 10, arr[1] = 20, *p = 20“

The expression ‘i++’ returns the old value and then increments i. The expression ++i increments the value and returns new value. 
2) Precedence of postfix ++ is higher than that of prefix ++. 
3) Associativity of postfix ++ is left to right and associativity of prefix ++ is right to left. 
4) In C++, ++i can be used as l-value, but i++ cannot be. In C, they both cannot be used as l-value. 
Link: https://www.geeksforgeeks.org/difference-between-p-p-and-p/
*/

/*
Explain Deep Copy and Shallow Copy with examples? 
In the following C program, struct variable st1 contains pointer to dynamically allocated memory. When we assign st1 to st2, str pointer of st2 also start pointing to same memory location. This kind of copying is called Shallow Copy. 
*/

struct testStruct
{
  char *str;
};
 
void shallowCopyCaller()
{
  struct testStruct st1, st2;
  st1.str = (char *)malloc(sizeof(char) * 20);
 
  strcpy(st1.str, "GeeksforGeeks");
 
  st2 = st1;
  st1.str[0] = 'X';
  st1.str[1] = 'Y';
 
  /* Since copy was shallow, both strings are same */
  printf("st1's str = %s\n", st1.str); // st1's str = XYeksforGeeks
  printf("st2's str = %s\n", st2.str); // st2's str = XYeksforGeeks
}

void deepCopyCaller()
{
  struct testStruct st1, st2;
  st1.str = (char *)malloc(sizeof(char) * 20);
 
  strcpy(st1.str, "GeeksforGeeks");
 
  st2 = st1;
 
  // We add extra statements to do deep copy
  st2.str = (char *)malloc(sizeof(char) * 20);
  strcpy(st2.str, st1.str);
 
  st1.str[0] = 'X';
  st1.str[1] = 'Y';
 
  /* Since copy was deep, both strings are different */
  printf("st1's str = %s\n", st1.str); // st1's str = XYeksforGeeks
  printf("st2's str = %s\n", st2.str); // st2's str = GeeksforGeeks
 
  return 0;
}






























