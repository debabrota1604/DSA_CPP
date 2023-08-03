#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;

template<typename T>
void disp(T t){ for(auto i:t) cout << i << " "; cout << endl;}


template<typename T>
void inorderSuccessor(T a,int key){
    if (a.find(key) == a.end()){ cout << "Key doesn't exist\n"; return;}  
    auto it = a.find(key); ++it; // get iterator of key and go to next element
  
    // Iterator points to NULL (Element does not exist)
    if (it == a.end()) { cout << "No successor\n";  return; }
    cout << "In-order successor of " << key << " is: "<<*(it) << "\n";
}

template<typename T>
void inorderPredecessor(T s,int key){
    if (s.find(key) == s.end()) { cout << "Key doesn't exist\n"; return; }
  
    auto it = s.find(key); // get iterator of key  
    // If iterator is at first position, it doesn't have predecessor
    if (it == s.begin()){ cout << "No predecessor\n"; return; }  

    auto it2 = s.rbegin();
    it2 = it; it2--; cout << *(it2) << endl;
    /*
    for(auto i = s.begin(), j=s.begin();i< s.end();i++){ 
        if(i== it){ it=j; break;} 
        j=i;
    }*/
    cout << "Predecessor of " << key << " is: " << *(it) << "\n";
}
  

/*              |     set             | unordered_set
---------------------------------------------------------
Ordering        | increasing  order   | no ordering
                | (by default)        |
Implementation  | Self balancing BST  | Hash Table
                | like Red-Black Tree |  
search time     | log(n)              | O(1) -> Average 
                |                     | O(n) -> Worst Case
Insertion time  | log(n) + Rebalance  | Same as search                      
Deletion time   | log(n) + Rebalance  | Same as search

Use set when:
    We need ordered data.
    We would have to print/access the data (in sorted order).
    We need predecessor/successor of elements.
    Since set is ordered, we can use functions like binary_search(), lower_bound() and upper_bound() on set elements. These functions cannot be used on unordered_set().
    See advantages of BST over Hash Table for more cases.
Use unordered_set when:
    We need to keep a set of distinct elements and no ordering is required.
    We need single element access i.e. no traversal.
*/


int main(){
    // empty set container
    set<int, greater<int> > s1;
 
    // insert elements in random order
    s1.emplace(40); cout << "insert(40): "; disp(s1);
    s1.emplace(30); cout << "insert(30): "; disp(s1);
    s1.emplace(60); cout << "insert(60): "; disp(s1);
    s1.emplace(20); cout << "insert(20): "; disp(s1);
    s1.emplace(50); cout << "insert(50): "; disp(s1);
 
    // only one 50 will be added to the set
    s1.emplace(10); cout << "insert(10): "; disp(s1);
    s1.emplace(50); cout << "insert(50): "; disp(s1);

    // assigning the elements from s1 to s2
    set<int> s2(s1.begin(), s1.end()); cout << "S2: "; disp(s2);
    
    // remove all elements up to 30 in s2
    cout << "\nS2 After removal of elements <=30: ";
    s2.erase(s2.begin(), ++(s2.find(30))); disp(s2);


    unordered_set<int> s;
    s.insert(5);
    s.insert(1);
    s.insert(6);
    s.insert(3);
    s.insert(7);
    s.insert(2);
  
    cout << "Elements of unordered_set: \n"; disp(s);

    s.insert(1);
    s.insert(5);
    s.insert(2);
    s.insert(9);
    s.insert(8);
  
    inorderPredecessor(s,5);
    inorderPredecessor(s,1);
    inorderPredecessor(s,8);
    inorderSuccessor(s,5);
    inorderSuccessor(s,2);
    inorderSuccessor(s,9);

    return 0;
}