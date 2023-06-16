#include<iostream>
#include "linkedList.cpp"
using namespace std;


int main(){
    int op1, op2, op3; linkedList l;


    cout << "1. Insert\n2. Delete\n3. Search\n4. Print\n5. Extra Features\nExit if option <1 or option >5"; 
    cout << "\nChoose one: "; cin>> op1;

    while (op1>0 && op1<6){
        //construct a menu
        if (op1==1){ //insert
<<<<<<< HEAD
            cout << "  1. Insert at beginning\n  2. Insert at end\n  3. Insert at position\n  4. Load list from file\n  5.Print list\nYour choice: ";
=======
            cout << "  1. Insert at beginning\n  2. Insert at end\n  3. Insert at position\n  4. Print list\nYour choice: ";
>>>>>>> 645a4859a03730492de7d40b5c50da6ad927f396
            cin >> op1;
            if (op1 ==1){
                cout << "Data: "; cin >> op2;
                l.insertAtBeg(op2); l.disp();
            }
            else if (op1==2){
                cout << "Data: "; cin >> op2;
                l.insertAtEnd(op2); l.disp();
            }
            else if (op1==3){
                cout << "Data: "; cin >> op2;
                cout << "Position: "; cin >> op3;
                l.insertAtPos(op2, op3); l.disp();
            }
<<<<<<< HEAD
            else if (op1==4){
                string fName;
                cout << "input fileName with extension: "; cin >> fName;
                l.insertFromFile(fName); l.disp();
            }
            else if (op1==5) l.disp();
=======
            else if (op1==4) l.disp();
>>>>>>> 645a4859a03730492de7d40b5c50da6ad927f396
        }
        else if (op1==2){ //delete
            cout << "  1. Delete from beginning\n  2. Delete from end\n  3. Delete from position\n  4. Print list\nYour choice: ";
            cin >> op1;
            if (op1 ==1){
                l.deleteByPos(1); l.disp();
            }
            else if (op1==2){
                l.deleteByPos(l.getSize()); l.disp();
            }
            else if (op1==3){
                cout << "Position: "; cin >> op3;
                l.deleteByPos(op3); l.disp();
            }
            else if (op1==4) l.disp();
        }
        else if (op1==3){ //search
        }
        else if (op1==4){ //print
            l.disp();
        }
        else if (op1==5){ // extra features

        }
        cout << "1. Insert\n2. Delete\n3. Search\n4. Print\n5. Extra Features\nExit if option <1 or option >5"; 
        cout << "\nChoose one: "; cin>> op1;
    }
    // linkedList l(5);
    // l.disp();

    // l.insertAtBeg(10);
    // l.disp();

    // l.insertAtEnd(11);
    // l.disp();


    // l.insertAtPos(19,3);
    // l.disp();

    // l.deleteByPos(1);
    // l.disp();

    // l.deleteByPos(l.getSize());
    // l.disp();









    return 0;
}