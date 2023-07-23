#include<bits/stdc++.h>
using namespace std;

void printList(string msg, list<int> l){
    cout << msg ;
    
    auto iter = l.begin();
    while(iter != l.end()){
        cout << *iter << " ";
        iter++;
    }
    cout << endl;
}

int main(){
    // Splice operation is used to transfer some/all elements of one list to another
    // Splice op is called from destination list

    /*
        1. Transfer all the elements of list x into another list at some position.
                Syntax: OutList.splice (OutListIterPos, inpListName)

        2. Transfer only the element pointed by i from list x into the list at some position.
                Syntax: OutList.splice (OutListIterPos, inpListName, inpListIterator)

        3. Transfers the range [first, last) from list x into another list at some position.
                Syntax: OutList.splice (OutListIterPos, inpListName, inpListIteratorBegin, inpListIteratorBegin)
    */
    list<int> inp1, inp2, inp3, out1, out2, out3;

    //Example 1:
    inp1 = {4, 5, 6};
    out1 = {7, 0};
    cout << "\n\nExample 1: Before Splice\n";
    printList("Input List: ", inp1);
    printList("Output List: ", out1);

    out1.splice(out1.begin(), inp1);

    cout << "Example 1: After Splice\n";
    printList("Input List: ", inp1);
    printList("Output List: ", out1);

    //Example 2:
    inp2 = {4, 5, 6};
    out2 = {7, 0};

    //take an iterator pointing to 5
    auto inpIter2 = inp2.begin();
    inpIter2++;

    cout << "\n\nExample 2: Before Splice\n";
    printList("Input List: ", inp2);
    printList("Output List: ", out2);

    out2.splice(out2.end(), inp2, inpIter2);

    cout << "Example 2: After Splice\n";
    printList("Input List: ", inp2);
    printList("Output List: ", out2);


    //Example 3:
    inp3 = {4, 5, 6, 9};
    out3 = {7, 0};

    //take an iterator pointing to 5
    auto inpIter3_beg = inp3.begin(), inpIter3_end = inp3.begin();
    inpIter3_end++; //points to 5
    inpIter3_end++; // points to 6

    cout << "\n\nExample 3: Before Splice\n";
    printList("Input List: ", inp3);
    printList("Output List: ", out3);

    out3.splice(out3.begin(), inp3, inpIter3_beg, inpIter3_end);

    cout << "Example 3: After Splice\n";
    printList("Input List: ", inp3);
    printList("Output List: ", out3);
    cout << "In Example 3, the splice operation copies elements till before the last iterator. Hence we can pass end() iterator also.\n\n";

}