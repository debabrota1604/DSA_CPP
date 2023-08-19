#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<pair<int, int>, int> u;

    /*
    the default constructor of "std::unordered_map<std::pair<int, int>, int, std::hash<std::pair<int, int>>, 
    std::equal_to<std::pair<int, int>>, std::allocator<std::pair<const std::pair<int, int>, int>>>" cannot be referenced -- it is a deleted function


    It seems for pair as first element in unordered_map, the default constructor cannot provide a correct hash function. You can take help from:
    https://stackoverflow.com/questions/32685540/why-cant-i-compile-an-unordered-map-with-a-pair-as-key
    */

    pair<int, int> p(5,3);
    u(p) = 5;
    cout << u(p) <<endl;






    return 0;
}