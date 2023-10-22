print("Hello World!\n")

if 0+0 ==0 and 1*1 ==1:
    print("The world is logical")
else:
    print("The world is illogical")


for iter in range(1,10):
    if iter ==8:
        print("Going to end the loop in next iteration")
    print (iter)



'''
for ... else loop:
Any code in the else block after a for loop is executed only if the for loop completes without encountering a break statement.

while loops can also have a else clause!
'''
for n in range(3):
    password = input("Password: ") 
    if password == "I<3Bieber":
        break
    print("Password is incorrect.") 
else:
    print("Suspicious activity. The authorities have been alerted.")



'''
What is the difference between Python Arrays and lists?
Arrays in python can only contain elements of same data types i.e., data type of array should be homogeneous. It is a thin wrapper around C language arrays and consumes far less memory than lists.
Lists in python can contain elements of different data types i.e., data type of lists can be heterogeneous. It has the disadvantage of consuming large memory.

'''
import array
a = array.array('i', [1, 2, 3])
for i in a:
    print(i, end=' ')    #OUTPUT: 1 2 3
#a = array.array('i', [1, 2, 'string'])    #OUTPUT: TypeError: an integer is required (got type str)
a = [1, 2, 'string']
for i in a:
   print(i, end=' ')    #OUTPUT: 1 2 string

'''
What are lists and tuples? What is the key difference between the two?
Lists and Tuples are both sequence data types that can store a collection of objects in Python. The objects stored in both sequences can have different data types. Lists are represented with square brackets ['sara', 6, 0.19], while tuples are represented with parantheses ('ansh', 5, 0.97).
But what is the real difference between the two? The key difference between the two is that while lists are mutable, tuples on the other hand are immutable objects. This means that lists can be modified, appended or sliced on the go but tuples remain constant and cannot be modified in any manner. You can run the following example on Python IDLE to confirm the difference:
'''
my_tuple = ('sara', 6, 5, 0.97)
my_list = ['sara', 6, 5, 0.97]
print(my_tuple[0])     # output => 'sara'
print(my_list[0])     # output => 'sara'
#my_tuple[0] = 'ansh'    # modifying tuple => throws an error
my_list[0] = 'ansh'    # modifying list => list modified
print(my_tuple[0])     # output => 'sara'
print(my_list[0])     # output => 'ansh'

'''
What are negative indexes and why are they used?
Negative indexes are the indexes from the end of the list or tuple or string.
Arr[-1] means the last element of array Arr[]

'''
arr = [1, 2, 3, 4, 5, 6]
#get the last element
print(arr[-1]) #output 6
#get the second last element
print(arr[-2]) #output 5




# List operations
firstList = [1, 2, 3, 4, 5]
secondList = [9, 8, 7, 6, 10]
print("FirstList: ", firstList)
print("SecondList: ", secondList)

print("firstList[0]: ", firstList[0])
firstList.append(11)
print("After appending 11 at the end, FirstList: ", firstList)
print("FirstList[-1]: ", firstList[-1])
firstList.insert(1, 15)
print("After inserting 15 in pos 1", firstList)
firstList.pop(5)
print("After removing element from index 5, FirstList: ", firstList)
firstList.remove(3)
print("Removed the element 3 from the list: ", firstList)

combinedList = firstList + secondList
print(combinedList)

# sort the list
combinedList.sort()
print(combinedList)

# get a new list from the list after sorting
newSortedList = sorted(secondList, reverse= True)
print(newSortedList)

'''
Exceptions in python:
'''

try:
    '1'+2
except TypeError:
    print("TypeError: Can only concatenate string to string")

try:
    print(doesNotExist)
except NameError:
    print("NameError: Name is not defined")

try:
    1/0
except ZeroDivisionError:
    print("ZeroDivisionError: Check your divisor")

try:
    pow(2.0, 1_000_000)
except OverflowError:
    print("OverflowError: Check max count!")

try:
    name = int(input("Enter a non-numeric string: "))
except ValueError:
    print("ValueError: Non-numeric string entered!!!")


try:
    num = '1' +5
except:
    print("Unconditional except: Something error has happened!")

'''
What is pass in Python?
The pass keyword represents a null operation in Python. It is generally used for the purpose of filling up empty blocks of code which may execute during runtime but has yet to be written. Without the pass statement in the following code, we may run into some errors during code execution.
'''


# Function with argument print
def addFunction(x: int, y:int) -> int:
    return x+y

x=5; y=10
ans = addFunction(x,y)
print(f"The addition of {x} and {y} is {ans}")

'''
What are modules and packages in Python?
Python packages and Python modules are two mechanisms that allow for modular programming in Python. Modularizing has several advantages -

    Simplicity: Working on a single module helps you focus on a relatively small portion of the problem at hand. This makes development easier and less error-prone.
    Maintainability: Modules are designed to enforce logical boundaries between different problem domains. If they are written in a manner that reduces interdependency, it is less likely that modifications in a module might impact other parts of the program.
    Reusability: Functions defined in a module can be easily reused by other parts of the application.
    Scoping: Modules typically define a separate namespace, which helps avoid confusion between identifiers from other parts of the program.
    Modules, in general, are simply Python files with a .py extension and can have a set of functions, classes, or variables defined and implemented. They can be imported and initialized once using the import statement. If partial functionality is needed, import the requisite classes or functions using from foo import bar.

Packages allow for hierarchial structuring of the module namespace using dot notation. As, modules help avoid clashes between global variable names, in a similar manner, packages help avoid clashes between module names.
Creating a package is easy since it makes use of the system's inherent file structure. So just stuff the modules into a folder and there you have it, the folder name as the package name. Importing a module or its contents from this package requires the package name as prefix to the module name joined by a dot.

Note: You can technically import the package as well, but alas, it doesn't import the modules within the package to the local namespace, thus, it is practically useless.

'''



print("Class tutorial in python:")
class A:
    num = 5
    def __init__(self):
        self.num = 0

    def printNum(self):
        print("Number in class A: ", self.num)
    def __del__(self):
        print("This is destructor")

obj1 = A()
obj1.printNum()

class B(A): # class B extends class A
    num2 = 15
    def __init__(self):
        self.num2 = 20

    def printNum(self):
        print(f"num & num2 in obj2 is {self.num} & {self.num2} respectively")

obj2 = B()
obj2.printNum()

'''
How virtual functions are defined in Python?
Python methods are always virtual. So, all class methods are virtual.


'''

'''
What are global, protected and private attributes in Python?
Global variables are public variables that are defined in the global scope. To use the variable in the global scope inside a function, we use the global keyword.
Protected attributes are attributes defined with an underscore prefixed to their identifier eg. _sara. They can still be accessed and modified from outside the class they are defined in but a responsible developer should refrain from doing so.
Private attributes are attributes with double underscore prefixed to their identifier eg. __ansh. They cannot be accessed or modified from the outside directly and will result in an AttributeError if such an attempt is made.

What is the use of self in Python?
Self is used to represent the instance of the class. With this keyword, you can access the attributes and methods of the class in python. It binds the attributes with the given arguments. self is used in different places and often thought to be a keyword. But unlike in C++, self is not a keyword in Python.

What is __init__?
__init__ is a contructor method in Python and is automatically called to allocate memory when a new object/instance is created. All classes have a __init__ method associated with them. It helps in distinguishing methods and attributes of a class from local variables.
'''

# class definition
class Student:
   def __init__(self, fname, lname, age, section):
       self.firstname = fname
       self.lastname = lname
       self.age = age
       self.section = section
# creating a new object
stu1 = Student("Sara", "Ansh", 22, "A2")



'''
What is slicing in Python?
    As the name suggests, ‘slicing’ is taking parts of.
    Syntax for slicing is [start : stop : step]
    start is the starting index from where to slice a list or tuple
    stop is the ending index or where to sop.
    step is the number of steps to jump.
    Default value for start is 0, stop is number of items, step is 1.
    Slicing can be done on strings, arrays, lists, and tuples.


    
Explain how can you make a Python Script executable on Unix?
Script file must begin with #!/usr/bin/env python



How is memory managed in Python?
Memory management in Python is handled by the Python Memory Manager. The memory allocated by the manager is in form of a private heap space dedicated to Python. All Python objects are stored in this heap and being private, it is inaccessible to the programmer. Though, python does provide some core API functions to work upon the private heap space.
Additionally, Python has an in-built garbage collection to recycle the unused memory for the private heap space.






What are Python namespaces? Why are they used?
A namespace in Python ensures that object names in a program are unique and can be used without any conflict. Python implements these namespaces as dictionaries with 'name as key' mapped to a corresponding 'object as value'. This allows for multiple namespaces to use the same name and map it to a separate object. A few examples of namespaces are as follows:

Local Namespace includes local names inside a function. the namespace is temporarily created for a function call and gets cleared when the function returns.
Global Namespace includes names from various imported packages/ modules that are being used in the current project. This namespace is created when the package is imported in the script and lasts until the execution of the script.
Built-in Namespace includes built-in functions of core Python and built-in names for various types of exceptions.
The lifecycle of a namespace depends upon the scope of objects they are mapped to. If the scope of an object ends, the lifecycle of that namespace comes to an end. Hence, it isn't possible to access inner namespace objects from an outer namespace.



What are decorators in Python?
Decorators in Python are essentially functions that add functionality to an existing function in Python without changing the structure of the function itself. They are represented the @decorator_name in Python and are called in a bottom-up fashion. For example:
'''

# decorator function to convert to lowercase
def lowercase_decorator(function):
   def wrapper():
       func = function()
       string_lowercase = func.lower()
       return string_lowercase
   return wrapper
# decorator function to split words
def splitter_decorator(function):
   def wrapper():
       func = function()
       string_split = func.split()
       return string_split
   return wrapper
@splitter_decorator # this is executed next
@lowercase_decorator # this is executed first
def hello():
   return 'Hello World'
hello()   # output => [ 'hello' , 'world' ]



# The beauty of the decorators lies in the fact that besides adding functionality to the output of the method, they can even accept arguments for functions and can further modify those arguments before passing it to the function itself. The inner nested function, i.e. 'wrapper' function, plays a significant role here. It is implemented to enforce encapsulation and thus, keep itself hidden from the global scope.


# decorator function to capitalize names
def names_decorator(function):
   def wrapper(arg1, arg2):
       arg1 = arg1.capitalize()
       arg2 = arg2.capitalize()
       string_hello = function(arg1, arg2)
       return string_hello
   return wrapper
@names_decorator
def say_hello(name1, name2):
   return 'Hello ' + name1 + '! Hello ' + name2 + '!'
say_hello('sara', 'ansh')   # output => 'Hello Sara! Hello Ansh!'


'''
What are Dict and List comprehensions?
Python comprehensions, like decorators, are syntactic sugar constructs that help build altered and filtered lists, dictionaries, or sets from a given list, dictionary, or set. Using comprehensions saves a lot of time and code that might be considerably more verbose (containing more lines of code). Let's check out some examples, where comprehensions can be truly beneficial:
'''


#Performing mathematical operations on the entire list
my_list = [2, 3, 5, 7, 11]
squared_list = [x**2 for x in my_list]    # list comprehension
# output => [4 , 9 , 25 , 49 , 121]
squared_dict = {x:x**2 for x in my_list}    # dict comprehension
# output => {11: 121, 2: 4 , 3: 9 , 5: 25 , 7: 49}



#Performing conditional filtering operations on the entire list
my_list = [2, 3, 5, 7, 11]
squared_list = [x**2 for x in my_list if x%2 != 0]    # list comprehension
# output => [9 , 25 , 49 , 121]
squared_dict = {x:x**2 for x in my_list if x%2 != 0}    # dict comprehension
# output => {11: 121, 3: 9 , 5: 25 , 7: 49}



# Combining multiple lists into one: Comprehensions allow for multiple iterators and hence, can be used to combine multiple lists into one. 
a = [1, 2, 3]
b = [7, 8, 9]
[(x + y) for (x,y) in zip(a,b)]  # parallel iterators
# output => [8, 10, 12]
[(x,y) for x in a for y in b]    # nested iterators
# output => [(1, 7), (1, 8), (1, 9), (2, 7), (2, 8), (2, 9), (3, 7), (3, 8), (3, 9)] 



#Flattening a multi-dimensional list: A similar approach of nested iterators (as above) can be applied to flatten a multi-dimensional list or work upon its inner elements. 

my_list = [[10,20,30],[40,50,60],[70,80,90]]
flattened = [x for temp in my_list for x in temp]
# output => [10, 20, 30, 40, 50, 60, 70, 80, 90]


'''
What is lambda in Python? Why is it used?
Lambda is an anonymous function in Python, that can accept any number of arguments, but can only have a single expression. It is generally used in situations requiring an anonymous function for a short time period. Lambda functions can be used in either of the two ways:
'''

# Assigning lambda functions to a variable:
mul = lambda a, b : a * b
print(mul(2, 5))    # output => 10


#Wrapping lambda functions inside another function:
def myWrapper(n):
 return lambda a : a * n
mulFive = myWrapper(5)
print(mulFive(2))    # output => 10


'''
How do you copy an object in Python?
In Python, the assignment statement (= operator) does not copy objects. Instead, it creates a binding between the existing object and the target variable name. To create copies of an object in Python, we need to use the copy module. Moreover, there are two ways of creating copies for the given object using the copy module -

Shallow Copy is a bit-wise copy of an object. The copied object created has an exact copy of the values in the original object. If either of the values is a reference to other objects, just the reference addresses for the same are copied.
Deep Copy copies all values recursively from source to target object, i.e. it even duplicates the objects referenced by the source object.
'''

from copy import copy, deepcopy
list_1 = [1, 2, [3, 5], 4]
## shallow copy
list_2 = copy(list_1) 
list_2[3] = 7
list_2[2].append(6)
list_2    # output => [1, 2, [3, 5, 6], 7]
list_1    # output => [1, 2, [3, 5, 6], 4]
## deep copy
list_3 = deepcopy(list_1)
list_3[3] = 8
list_3[2].append(7)
list_3    # output => [1, 2, [3, 5, 6, 7], 8]
list_1    # output => [1, 2, [3, 5, 6], 4]


'''
What is the difference between xrange and range in Python?
xrange() and range() are quite similar in terms of functionality. They both generate a sequence of integers, with the only difference that range() returns a Python list, whereas, xrange() returns an xrange object.

So how does that make a difference? It sure does, because unlike range(), xrange() doesn't generate a static list, it creates the value on the go. This technique is commonly used with an object-type generator and has been termed as "yielding".

Yielding is crucial in applications where memory is a constraint. Creating a static list as in range() can lead to a Memory Error in such conditions, while, xrange() can handle it optimally by using just enough memory for the generator (significantly less in comparison).
'''
for i in range(10):    # numbers from o to 9
   print (i)      # output => 0 1 2 3 4 5 6 7 8 9
for i in range(1,10):    # numbers from 1 to 9
   print (i)       # output => 1 2 3 4 5 6 7 8 9
for i in range(1, 10, 2):    # skip by two for next
   print (i)       # output => 1 3 5 7 9

# Note: xrange has been deprecated as of Python 3.x. Now range does exactly the same as what xrange used to do in Python 2.x, since it was way better to use xrange() than the original range() function in Python 2.x.


'''
What is pickling and unpickling?
Python library offers a feature - serialization out of the box. Serializing an object refers to transforming it into a format that can be stored, so as to be able to deserialize it, later on, to obtain the original object. Here, the pickle module comes into play.

Pickling: Pickling is the name of the serialization process in Python. Any object in Python can be serialized into a byte stream and dumped as a file in the memory. The process of pickling is compact but pickle objects can be compressed further. Moreover, pickle keeps track of the objects it has serialized and the serialization is portable across versions.
The function used for the above process is pickle.dump().

Unpickling: Unpickling is the complete inverse of pickling. It deserializes the byte stream to recreate the objects stored in the file and loads the object to memory.
The function used for the above process is pickle.load().
Note: Python has another, more primitive, serialization module called marshall, which exists primarily to support .pyc files in Python and differs significantly from the pickle.





What are generators in Python?
Generators are functions that return an iterable collection of items, one at a time, in a set manner. Generators, in general, are used to create iterators with a different approach. They employ the use of yield keyword rather than return to return a generator object.
Let's try and build a generator for fibonacci numbers -
'''

## generate fibonacci numbers upto n
def fib(n):
   p, q = 0, 1
   while(p < n):
       yield p
       p, q = q, p + q
x = fib(10)    # create generator object 
 
## iterating using __next__(), for Python2, use next()
x.__next__()    # output => 0
x.__next__()    # output => 1
x.__next__()    # output => 1
x.__next__()    # output => 2
x.__next__()    # output => 3
x.__next__()    # output => 5
x.__next__()    # output => 8
#x.__next__()    # error
 
## iterating using loop
for i in fib(10):
   print(i)    # output => 0 1 1 2 3 5 8


'''
What is the difference between .py and .pyc files?
.py files contain the source code of a program. Whereas, .pyc file contains the bytecode of your program. We get bytecode after compilation of .py file (source code). .pyc files are not created for all the files that you run. It is only created for the files that you import.
Before executing a python program python interpreter checks for the compiled files. If the file is present, the virtual machine executes it. If not found, it checks for .py file. If found, compiles it to .pyc file and then python virtual machine executes it.
Having .pyc file saves you the compilation time.



How Python is interpreted?
Python as a language is not interpreted or compiled. Interpreted or compiled is the property of the implementation. Python is a bytecode(set of interpreter readable instructions) interpreted generally.
Source code is a file with .py extension.
Python compiles the source code to a set of instructions for a virtual machine. The Python interpreter is an implementation of that virtual machine. This intermediate format is called “bytecode”.
.py source code is first compiled to give .pyc which is bytecode. This bytecode can be then interpreted by the official CPython or JIT(Just in Time compiler) compiled by PyPy.


How are arguments passed by value or by reference in python?
Pass by value: Copy of the actual object is passed. Changing the value of the copy of the object will not change the value of the original object.
Pass by reference: Reference to the actual object is passed. Changing the value of the new object will change the value of the original object.
In Python, arguments are passed by reference, i.e., reference to the actual object is passed.

'''
def appendNumber(arr):
   arr.append(4)
arr = [1, 2, 3]
print(arr)  #Output: => [1, 2, 3]
appendNumber(arr)
print(arr)  #Output: => [1, 2, 3, 4]


'''
What are iterators in Python?
An iterator is an object.
It remembers its state i.e., where it is during iteration (see code below to see how)
__iter__() method initializes an iterator.
It has a __next__() method which returns the next item in iteration and points to the next element. Upon reaching the end of iterable object __next__() must return StopIteration exception.
It is also self-iterable.
Iterators are objects with which we can iterate over iterable objects like lists, strings, etc.
'''

class ArrayList:
   def __init__(self, number_list):
       self.numbers = number_list
   def __iter__(self):
       self.pos = 0
       return self
   def __next__(self):
       if(self.pos < len(self.numbers)):
           self.pos += 1
           return self.numbers[self.pos - 1]
       else:
           raise StopIteration
array_obj = ArrayList([1, 2, 3])
# it = iter(array_obj)
# print(next(it)) #output: 2
# print(next(it)) #output: 3
# print(next(it))
#Throws Exception
#Traceback (most recent call last):
#...
#StopIteration




'''
Explain split() and join() functions in Python?
You can use split() function to split a string based on a delimiter to a list of strings.
You can use join() function to join a list of strings based on a delimiter to give a single string.
'''

string = "This is a string."
string_list = string.split(' ') #delimiter is ‘space’ character or ‘ ‘
print(string_list) #output: ['This', 'is', 'a', 'string.']
print(' '.join(string_list)) #output: This is a string.



'''
What does *args and **kwargs mean?

*args is a special syntax used in the function definition to pass variable-length arguments.
“*” means variable length and “args” is the name used by convention. You can use any other.

**kwargs is a special syntax used in the function definition to pass variable-length keyworded arguments.
Here, also, “kwargs” is used just by convention. You can use any other name.
Keyworded argument means a variable that has a name when passed to a function.
It is actually a dictionary of the variable names and its value.


'''
# **args example
def multiply(a, b, *argv):
   mul = a * b
   for num in argv:
       mul *= num
   return mul
print(multiply(1, 2, 3, 4, 5)) #output: 120

# **kwargs example
def tellArguments(**kwargs):
   for key, value in kwargs.items():
       print(key + ": " + value)
tellArguments(arg1 = "argument 1", arg2 = "argument 2", arg3 = "argument 3")
#output:
# arg1: argument 1
# arg2: argument 2
# arg3: argument 3



'''
How do you create a class in Python?
To create a class in python, we use the keyword “class”.
To instantiate or create an object from the class created above, we do the following:
emp_1=InterviewbitEmployee("Mr. Employee")

To access the name attribute, we just call the attribute using the dot operator as shown below:

print(emp_1.emp_name)
# Prints Mr. Employee
To create methods inside the class, we include the methods under the scope of the class as shown below:

class InterviewbitEmployee:
   def __init__(self, emp_name):
       self.emp_name = emp_name
       
   def introduce(self):
       print("Hello I am " + self.emp_name)
The self parameter in the init and introduce functions represent the reference to the current class instance which is used for accessing attributes and methods of that class. The self parameter has to be the first parameter of any method defined inside the class. The method of the class InterviewbitEmployee can be accessed as shown below:

emp_1.introduce()
The overall program would look like this:

'''
class InterviewbitEmployee:
   def __init__(self, emp_name):
       self.emp_name = emp_name
       
   def introduce(self):
       print("Hello I am " + self.emp_name)
       
# create an object of InterviewbitEmployee class
emp_1 = InterviewbitEmployee("Mr Employee")
print(emp_1.emp_name)    #print employee name
emp_1.introduce()        #introduce the employee




'''
How does inheritance work in python? Explain it with an example.
Inheritance gives the power to a class to access all attributes and methods of another class. It aids in code reusability and helps the developer to maintain applications without redundant code. The class inheriting from another class is a child class or also called a derived class. The class from which a child class derives the members are called parent class or superclass.

Python supports different kinds of inheritance, they are:

Single Inheritance: Child class derives members of one parent class.
'''
# Parent class
class ParentClass:
    def par_func(self):
         print("I am parent class function")

# Child class
class ChildClass(ParentClass):
    def child_func(self):
         print("I am child class function")

# Driver code
obj1 = ChildClass()
obj1.par_func()
obj1.child_func()

'''
Multi-level Inheritance: The members of the parent class, A, are inherited by child class which is then inherited by another child class, B. The features of the base class and the derived class are further inherited into the new derived class, C. Here, A is the grandfather class of class C.

'''
# Parent class
class A:
   def __init__(self, a_name):
       self.a_name = a_name
   
# Intermediate class
class B(A):
   def __init__(self, b_name, a_name):
       self.b_name = b_name
       # invoke constructor of class A
       A.__init__(self, a_name)

# Child class
class C(B):
   def __init__(self,c_name, b_name, a_name):
       self.c_name = c_name
       # invoke constructor of class B
       B.__init__(self, b_name, a_name)
       
   def display_names(self):
       print("A name : ", self.a_name)
       print("B name : ", self.b_name)
       print("C name : ", self.c_name)

#  Driver code
obj1 = C('child', 'intermediate', 'parent')
print(obj1.a_name)
obj1.display_names()


'''
Multiple Inheritance: This is achieved when one child class derives members from more than one parent class. All features of parent classes are inherited in the child class.
'''
# Parent class1
class Parent1:
   def parent1_func(self):
       print("Hi I am first Parent")

# Parent class2
class Parent2:
   def parent2_func(self):
       print("Hi I am second Parent")

# Child class
class Child(Parent1, Parent2):
   def child_func(self):
       self.parent1_func()
       self.parent2_func()

# Driver's code
obj1 = Child()
obj1.child_func()



'''
Hierarchical Inheritance: When a parent class is derived by more than one child class, it is called hierarchical inheritance.
'''
# Base class
class A:
     def a_func(self):
         print("I am from the parent class.")

# 1st Derived class
class B(A):
     def b_func(self):
         print("I am from the first child.")

# 2nd Derived class
class C(A):
     def c_func(self):
         print("I am from the second child.")
 
# Driver's code
obj1 = B()
obj2 = C()
obj1.a_func()
obj1.b_func()    #child 1 method
obj2.a_func()
obj2.c_func()    #child 2 method








































