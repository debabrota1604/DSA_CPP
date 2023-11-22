#include<bits/stdc++.h>
using namespace std;

// unique_ptr demo

template <typename T>
class UniqPtr{
    private:
    T* resource;

    public:
    UniqPtr(T* inpVar = nullptr): resource(a){
        // "inpVar = nullptr" is for null as default value if no value is passed.
        cout << "Constructor\n";
    }

    //copy constructor: not to be allowed.
    UniqPtr(const UniqPtr<T>& copyConsVar) = delete;

    //move constructor
    UniqPtr( UniqPtr<T>&& moveConsVar){
        resource = moveConsVar.resource;
        moveConsVar.resource = nullptr; //transfer the ownership
    }

    //copy assignment: not to be allowed
    UniqPtr& operator=(const UniqPtr<T>& copyAssignmentVar) = delete;

    //move assignment
    UniqPtr& operator=(UniqPtr<T>&& moveAssignmentVar){
        if(this != moveAssignmentVar){
            //handles the case of type "var1 = var1"
            if(resource){
                // resource already holds some memory, free before pointing it to something else
                delete resource;
            }
            resource = moveAssignmentVar.resource;
            moveAssignmentVar.resource = nullptr;
        }
    }

    //overload '->' operator
    T* operator->(){
        return resource;
    }

    T& operator*(){
        return *resource;
    }

    T* get(){
        return resource;
    }

    void reset (T* inputVar = nullptr){
        if(resource) delete resource;
        resource = inputVar;
    }

    ~UniqPtr(){
        if(resource){
            delete resource;
            resource = nullptr;
        }
        cout << "Destructor called\n";
    }

};


int main(){
    UniqPtr<int> ptr1(new int (10));
    //UniqPtr<int> ptr2(ptr1); // compilation error for parameterized constructor
    //UniqPtr<int> ptr3 = ptr1; // compilation error for copy assignment
    UniqPtr<int> ptr4 (new int (500));
    UniqPtr<int> ptr5 = move(ptr1);


    //ptr1->fun();
    cout << *(ptr1) << endl;
    ptr5.reset();

}