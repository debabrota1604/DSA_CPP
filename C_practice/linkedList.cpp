#include<iostream>
#include<list>
#include<numeric>
using namespace std;

void disp(list<int> l){
    for (auto itx=l.begin(); itx!=l.end(); ++itx)
        cout << ' ' << *itx;
    cout << '\n';
}

int main(){
    cout << "C++ STL: List ..............................................." <<endl;
    /*
    list is a container that supports constant time insertion and removal of elements from anywhere in the container.
    Fast random access is not supported. It is usually implemented as a doubly-linked list. Compared to std::forward_list this container provides bidirectional iteration capability while being less space efficient.
    Adding, removing and moving the elements within the list or across several lists does not invalidate the iterators or references. An iterator is invalidated only when the corresponding element is deleted.
    */

    cout << "List (doubly linked list in C++ STL) operations:" <<endl;
    cout << "Declarations.........................." <<endl;
    list<int> l1, l2(5,100), l3= {11,12,13,14,15};
    disp(l1); disp(l2); disp(l3);

    cout << "Insertion..............................." <<endl;
    auto it0 = l1.begin(); //'auto' infers the type if ut is a declaration, in this case it is an integer list iterator

    //insert at the beginning of a list
    l1.emplace_front(2);  disp(l1);    //emplace_front() is faster than push_back()

    //insert at the end of a list
    l1.emplace_back(5);   disp(l1);     //push_back() is faster thqn push_front()

    //insert at any specific position through iterator
    advance(it0,2);
    l1.emplace(it0,99);   disp(l1);

    cout << "Merge two list......................... " <<endl;    
    auto l4=l3;
    l4.merge(l1); disp(l4);

    cout << "Remove................................."  <<endl;
    l4.remove(20); disp(l4);    //No error if item not found;
    l4.remove(11); disp(l4);    //Deletes 11


    cout << "Remove if:"  <<endl;
    l4.remove_if([](int x) { return x % 7 == 0; }); disp(l4);   //Removes all numbers divisible by 7, here it is 14

    cout << "Swap two lists..........................." << endl;
    cout << "Before:"; disp(l2); disp(l4);
    l2.swap(l4);
    cout << "After:"; disp(l2); disp(l4);

    cout << "Unique................................." <<endl; //list must be sorted
    l4.unique(); disp(l4);

    cout << "Sort............................" <<endl;
    l2.sort(); disp(l2);


    cout << "front() and back()......................" <<endl;
    cout<< "L2:" ; disp(l2);
    cout << "L2 front: " << l2.front() <<endl;
    cout << "L2 back: " << l2.back() <<endl;

    cout << "reverse()..............................." <<endl;
    l2.reverse(); disp(l2);

    cout << "Size and max-size:......................" <<endl;
    cout << "l2 size: " <<l2.size()<<endl;
    cout << "l2 maxSize: " <<l2.max_size() <<endl; //maximum values it can hold

    cout << "Clear and empty:......................" <<endl;
    cout << "l2 Emoty? " << l2.empty() << endl;
    l2.clear(); disp(l2);
    cout << "l2 Emoty? " << l2.empty() << endl;

    cout << "Numeric............................" <<endl;
    auto sum=0; disp(l2);
    cout << "Accumulate l4:" << accumulate(l2.begin(),l2.end(),sum) << " sum = " << sum << endl;  


    list<int> mylist;
    list<int>::iterator it1,it2,itx;


    // set some values:
    for (int i=0; i<10; ++i) mylist.push_back(10*i);

    cout << "\nmylist contains:";   disp(mylist);

                                // 10 20 30 40 50 60 70 80 90
    it1 = it2 = mylist.begin(); // ^^
    advance (it2,6);            // ^                 ^
    ++it1;                      //    ^              ^

    it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90
                                //    ^           ^

    it2 = mylist.erase (it2);   // 10 30 40 50 60 80 90
                                //    ^           ^

    ++it1;                      //       ^        ^
    --it2;                      //       ^     ^

    mylist.erase (it1,it2);     // 10 30 60 80 90

    cout << "\nmylist contains:";  disp(mylist);

    // NOTE: it1 still points to 40, and 60 is not deleted
    cout << endl << *it1 << "\t" << *it2 <<endl;

    // This will print an unexpected value
    it1++;
    //cout << *it1; seg fault

    cout << "\nmylist now contains:";   disp(mylist);








    return 0;
}