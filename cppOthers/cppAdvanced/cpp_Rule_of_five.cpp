// This document is taken from: https://www.codementor.io/@sandesh87/the-rule-of-five-in-c-1pdgpzb04f

// In C++, we can place objects on the heap memory by dynamically allocating memory for them. For example, if we want to dynamically allocate memory for an integer we may just say

int* itr_p = new int(10);

/* Here we dynamically created an integer and assigned it the value of 10. The memory for the integer is allocated from the heap.

When a C++ class manages one or more such resources that are placed on the heap, we need some functions to be part of the class.

The rule of three:

The Rule of Three states that if a type ever needs one of the following, then it must have all three.
            1. copy constructor
            2. copy assignment
            3. destructor

In accordance with RAII principles, the aforementioned functions are usually required when a class is manually managing at least one dynamically allocated resource.

What is RAII principles? https://en.cppreference.com/w/cpp/language/raii

Let's consider an example.
*/


// Example 1
class Student {
private:
  int id;
  char* name;

public:
  Student() {
    this->id = 0;
    this->name = nullptr;
  }

  Student(char* name, int id) {
    this->id = id;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
  }

  ~Student() {
    delete[] this->name;
  }
};


/*
In Example 1, we have a class Student that manually manages a dynamically allocated resources, viz. name. The 2-arg constructor allocates memory for name and the destructor frees the allocated memory. This avoids memory leaks.

But what happens when an object of Student is copied?
*/

Student s1("John", 10);
Student s2 = s1;

/*
When s2 is being constructed, the default copy constructor for Student will be executed (as there's no user-defined copy constructor). A default copy constructor is supplied by the C++ compiler whenever there's a missing user-defined copy constructor. (Note: The rules are a bit more involved, but let's oversimplify things a bit here). The default copy constructor will copy each attribute of the class as-is (this is referred to as shallow copy). Which means, both s1.name and s2.name point to the same C-string.

What happens when the scope ends? s2's destructor will be called, which will free the memory allocated for name C-string. Then, s1's destructor gets called which will again try freeing the memory for the name C-string. But it's already freed! This results in undefined behaviour.

To avoid this, suitable copy operations need to be provided. So now we add copy constructor and copy assignment functions to the Student class.
*/


// copy constructor
Student(const Student& other) {
  this->id = other.id;
  this->name = new char[strlen(other.name) + 1];
  strcpy(this->name, other.name);
}

// copy assignment
Student& operator=(const Student& rhs) {
  // self-asignment check
  if (this != &rhs) {

    this->id = rhs.id;

    // delete old data
    if (this->name) {
      delete[] this->name;
    }

    this->name = new char[strlen(rhs.name) + 1];
    strcpy(this->name, rhs.name);
  }

  return *this;
}

/*
Update 1: The above version of the copy assignment is not exception safe. In the event the new call throws an exception, your object is left in a broken state: it holds a pointer this->name to freed memory.
        When your (failed) assigned-to object goes out of scope its destructor causes a double-delete.
        If you recover in a catch block, trying to dereference this->name gives garbage or segfault if that memory was return to OS.
        Fix is simple: allocate the new memory and assign to a temp variable before deleting your member.

*/
// copy assignment
Student& operator=(const Student& rhs) {
  // self-asignment check
  if (this != &rhs) {

    this->id = rhs.id;

    char *tmp = new char[strlen(rhs.name) + 1];
    strcpy(tmp, rhs.name);

    // delete old data
    if (this->name) {
      delete[] this->name;
    }

    this->name = tmp;
  }

  return *this;
}

/*
Both the copy constructor and the copy assignment operator perform a deep copy of the dynamically allocated resourse.

Now, when we run the following code
*/

Student s1("John", 10);
Student s2 = s1;

/*
there's no memory leak. When s2 is created, a copy of the name C-string is created in memory. s1 and s2 no longer share the same C-string.

The implementation of the copy assignment is a bit more involved as compared to the copy constructor. In the copy assignment, we also have to account for self-assignment and freeing up of old memory.
*/

/*
The Rule of Five:

The Rule of Five is a modern extension to the Rule of Three. The Rule of Five states that if a type ever needs one of the following, then it must have all five.
            1. copy constructor
            2. copy assignment
            3. destructor
            4. move constructor
            5. move assignment

In addition to copy semantics (Rule of Three), we also have to implement move semantics. Move operations are efficient as compared to copy operations as they make use of the already allocated memory and avoid unnecessary copy operations.

Not implementing move semantics is not usually considered an error. If move semantics are missing, the compiler would normally use the less efficient copy operations wherever possible. If a class does not require move operations, we can easily skip those. But, implementing them results in increased efficiency.

Let's see how we can add move semantics to the aforementioned Student class.
*/

// move constructor
Student(Student&& other) {
  this->id = other.id;
  this->name = other.name;
  other.name = nullptr;
}

// move assignment
Student& operator=(Student&& rhs) {
  // self-asignment check
  if (this != &rhs) {

    this->id = rhs.id;

    // delete old data
    if (this->name) {
      delete[] this->name;
    }

    this->name = rhs.name;
    rhs.name = nullptr;
  }

  return *this;
}

/*
Notice the && in the parameters of the move operations. Also, the parameters are not marked as const as opposed to const parameters in copy operations.

The move operations are called when copy of a soon-to-be-destroyed (dying) object is being made. As the object is soon going to be destroyed, instead of making a copy, we make use of the dying object's resources. In essence, we steal resources from the dying object.
*/

Student s1("John", 10);
Student s2 = s1; //copy constructor
Student s3;
s3 = s1; // copy assignment

Student s4("Jane", 12);
Student s5 = std::move(s4); // move constructor
Student s6;
s6 = std::move(s5); //move assignment


/*
Using the std::move library function, we can force move semantics (provided the resource supports move operations).

Another example of move semantics is where a function returns an object by value.
*/

Student foo() {
  Student s1("Arnold", 15);
  return s1;
}

int main () {
  Student someStu = foo();
}

/*
In the fucntion foo(), the Student object s1 is local to foo. So the object is about to be destroyed when the function returns. But before returning, the function is returning the object by value (or by copy).

Here, in absence of move semantics, the copy constructor would have been automatically called which would have created a deep copy of the object. But, as we have move operations in the Student class, the compiler will make use of those to make the code efficient. Instead of calling the copy constructor, the move constructor will be called and the object someStu steals data from the dying object s1.
*/

// Conclusion:
//Now that we know the Rule of Three and Rule of Five, we should start using them in our code. This will avoid many bugs that may crop up in a complex code; bugs that are otherwise hard to find and fix. These bugs are related to memory leaks and accessing of unallocated memory locations. We can easily avoid those by just applying these rules to all the classes that we write.