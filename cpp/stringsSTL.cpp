#include<iostream>
using namespace std;
int main(){
    cout << "C++ STL: Strings ..............................................." <<endl;
    //C++ String library: A powerful alternative for the char*
    string s0;                                       // s0 = “”
    string s1("Hello");                               // s1 = “Hello”
    string s2 (s1);                                  // s2 = “Hello”
    string s3 (s1, 1, 2);                            // s3 = “el”
    string s4 ("Hello World", 5);                     // s4 = “Hello”
    string s5 (5, '*');                              // s5 = “*****”
    string s6 (s1.begin(), s1.begin()+3);              // s6 = “Hel”
    cout << "s0: " << s0 <<endl
         << "s1: " << s1 <<endl
         << "s2: " << s2 <<endl
         << "s3: " << s3 <<endl
         << "s4: " << s4 <<endl
         << "s5: " << s5 <<endl
         << "s6: " << s6 <<endl
         << "-------------------"<<endl;
    
    //C++ string STL append works in O(n).
    s0="abcd";
    s1 = s0;
    s1=s1.append("efg");
    s2 = s1 + "ghi";
    cout << "s0: " << s0 <<endl
         << "s1: " << s1 <<endl
         << "s2: " << s2 <<endl
         << "-------------------"<<endl;
        

    cout << "*(s0.begin()): " << *(s0.begin()) << endl; //print value of iterator at s0.begin()

    cout << "s0[2]: " << s0[2] <<endl; //return char at pos 2

    cout << "s0.size(): " << s0.size() <<endl; //return size of s0
    
    //replace(__pos – Index of first character to replace,__n1 – Number of characters to be replaced, s – C string to insert.)
    cout << "s0.replace(0, 3,\"mno\"): "<< s0.replace(0, 3,"mno") << endl;
    cout << "s0.replace(0, 1,\"pqr\"): "<< s0.replace(0, 1,"pqr") << endl<<"----------------------------"<<endl;

    s0="pqrstuvwxyz";
    cout<<"s0: "<< s0 << "Endl"<<endl;
    s0.resize(15);
    cout << "s0.resize(15): " << s0<< "Endl" <<endl;
    s0.resize(10);
    cout << "s0.resize(10): " << s0<< "Endl" <<endl;

    cout<< "s0.substr(2,3): "<<s0.substr(2,3)<< "Endl" << endl << "---------------------------"<<endl; //returns a substring between start index to end index +1
    
    
    
    s0="aabbccdefgabc";
    cout<<"s0: "<< s0 << "Endl"<<endl;
    cout << "s0.find('a'): "<<s0.find('a') << endl;
    cout << "s0.find(\"bc\"): "<<s0.find("bc") << endl;
    cout << "s0.find(\"bc\",4): "<<s0.find("bc",4) << endl;
    cout << "s0.find(\"xyz\"): "<<s0.find("xyz") << endl;
    return 0;
}