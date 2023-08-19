#include<iostream>
#include <forward_list>
using namespace std;

void disp(forward_list<int> l){
    //for (auto itx=l.begin(); itx!=l.end(); ++itx)
    for (auto itx=l.begin(); itx!=l.end(); ++itx)
        cout << ' ' << *itx;
    cout << '\n';
}


int main(){

    forward_list<int> f1={3,2,1,4,5,8,6};
    disp(f1);
    cout << "Is the list empty? " << f1.empty() << endl;
    cout << "Max elements this forward-list can hold: " << f1.max_size() << endl;

    cout << "Front element is: " << f1.front() <<endl;
    cout << "Inserting 9 after the 3rd element: "; 
    auto l= f1.begin(); advance(l,3); f1.insert_after(l,9); disp(f1);
    f1.sort();
    cout << "Sorted list is:" << endl; disp(f1);






    return 0;
}