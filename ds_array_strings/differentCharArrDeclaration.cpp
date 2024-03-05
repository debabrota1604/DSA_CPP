#include <iostream>
using namespace std;

int main() {
    char a='a'; string str = "abc";
    const char *aa=str.c_str();
    char const *bb=str.c_str();
    char* const cc = str.c_str();
    cout << typeid(aa).name() << " " << typeid(bb).name()<< " " << typeid(cc).name() << endl;
    

    return 0;
}