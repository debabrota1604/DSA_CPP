#include<bits/stdc++.h>
using namespace std;

constexpr size_t sz = 5;

// Creation of array in single line:
array<int, sz> c_arr = {3, 5, 2, 6, 1};

// Function to print vector elements
void printVector(const vector<int>& vec) {
    for (const auto &i : vec) 
        cout << i << ' ';
    cout << '\n';
}

void printVector_iterator(const vector<string>& vec) {
    // Accessing elements using iterators
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
	// Creation of vector in single line:
	vector<int> vec3(sz); //n-sized vector declaration
	vector<int> vec0(sz, 5); //n-sized vector initialized with X
	vector<int> arr = {3,2,5,3,1}; //initializer list
	vector<int> vec1 {34, 67, 98, 23, 56, 78, 12, 45, 67, 89, 10, 34, 67, 98, 23}; //initializer list w/o equal sign


    vector<int> vec10{3,5,4,7,1,8}; // 5 elements initialized to 10
	// Insertion and Deletion
    vec10.push_back(6);  // Inserting at the end
    vec10.pop_back();   // Removing from the end

    // Accessing Elements
    cout << "Front: " << vec10.front() << ", Back: " << vec10.back() << endl;
    
    // Minimum, Maximum and Sum of Vector Elements
    auto min_it = min_element(vec10.begin(), vec10.end());
    auto max_it = max_element(vec10.begin(), vec10.end());
    int sum = accumulate(vec10.begin(), vec10.end(), 0);
    
    cout << "Min: " << *min_it << ", Max: " << *max_it << ", Sum: " << sum << endl;

	// Finding the index
	int index1 = find(arr.begin(), arr.end(), 5) - arr.begin(); // O(n) time

	// Finding using lambda function
	int index2 = find_if(arr.begin(), arr.end(), [](int x) { return x == 5; }) - arr.begin(); // O(n) time

	// Finding in sorted vector using binary search
	int index3 = lower_bound(arr.begin(), arr.end(), 5) - arr.begin(); // O(log n) time

    // Reversing a vector
    reverse(arr.begin(), arr.end()); // O(n) time
    cout << "Reversed vector: ";
    printVector(arr);

    // Sorting a vector
    sort(arr.begin(), arr.end()); // O(n log n) time
    cout << "Sorted vector: ";
    printVector(arr);

    // Shuffling a vector
    shuffle(arr.begin(), arr.end(), default_random_engine()); // O(n) time
    cout << "Shuffled vector: ";
    printVector(arr);

	//Clear/Empty vector elements:
	vec3.clear(); //O(n) time
    vec1.erase(vec1.begin(), vec1.begin()+3); // Erases the range [first, last)

    // Resizing a vector
    vec1.resize(10); // Resizes the vector to 10 elements

    // Inserting an element at a specific position
    vec1.insert(vec1.begin() + 2, 5); // Inserts 5 at index 2

    // Erasing an element at a specific position
    vec1.erase(vec1.begin() + 2); // Erases the element at index 2

    // Checking if a vector is empty
    if (vec1.empty()) {
        cout << "Vector is empty" << endl;
    } else {
        cout << "Vector is not empty" << endl;
    }


    // Swap vectors
    vector<int> v1{1, 2, 3};
    vector<int> v2{4, 5, 6};
    swap(v1, v2); // Swaps the contents of v1 and v2

    // Size and capacity of vector
    cout << "Size of vec1: " << vec1.size() << endl;
    cout << "Capacity of vec1: " << vec1.capacity() << endl;

    // Reserving space in vector
    vec1.reserve(20); // Reserves space for at least 20 elements without initializing them.

    // Shrink to Fit: Reduces the capacity of the vector to fit its size
    // and destroys all elements beyond the original capacity.
    vec1.shrink_to_fit(); 

    // vec.substr
    // Suppose we have a string vector
    std::vector<std::string> vec = {"Hello", "World", "This", "Is", "C++"};

    // To get the subset from index 2 to 4 (0-based indexing)
    auto first = vec.begin() + 2; // points to "This"
    auto last = vec.begin() + 4; // points to "C++"
    std::vector<std::string> subVec(first, last); // creates a new vector with elements from "This" to "C++"
    cout << "Sub-vector1: ";
    for(auto str : subVec) {
        cout << str << " ";
    }
    cout << endl;


    // Suppose we have an integer vector
    std::vector<int> vec2 = {10, 20, 30, 40, 50};
    std::vector<int> subVec2(vec2.begin() + 1, vec2.begin() + 4); // creates a new vector with elements from "20" to "40"
    cout << "Sub-vector2: ";
    printVector(arr);

    // Using vector of vectors
    vector<vector<int>> vec2D = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // Accessing elements in 2D vector
    for (const auto& row : vec2D) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    // vector of pairs
    vector<pair<int, string>> vecPairs = {{1, "one"}, {2, "two"}, {3, "three"}};
    // Accessing elements in vector of pairs
    for (const auto& p : vecPairs) {
        cout << p.first << ": " << p.second << endl;
    }

    // vector of structs
    struct Point {
        int x;
        int y;
    };

    vector<Point> vecPoints = {{1, 2}, {3, 4}, {5, 6}};
    // Accessing elements in vector of structs
    for (const auto& p : vecPoints) {
        cout << "Point(" << p.x << ", " << p.y << ")" << endl;
    }

    // vector of strings
    vector<string> vecStrings = {"Hello", "World", "!"};
    // Accessing elements in vector of strings
    for (const auto& str : vecStrings) {
        cout << str << " ";
    }
    cout << endl;


    // vector of characters
    vector<char> vecChars = {'H', 'e', 'l', 'l', 'o'};
    // Accessing elements in vector of characters
    for (const auto& ch : vecChars) {
        cout << ch;
    }
    cout << endl;


    // vector of doubles
    vector<double> vecDoubles = {1.1, 2.2, 3.3};
    // Accessing elements in vector of doubles
    for (const auto& d : vecDoubles) {
        cout << d << " ";
    }
    cout << endl;


    // vector of floats
    vector<float> vecFloats = {1.1f, 2.2f, 3.3f};
    // Accessing elements in vector of floats
    for (const auto& f : vecFloats) {
        cout << f << " ";
    }
    cout << endl;


    // vector of long long integers
    vector<long long> vecLongLongs = {10000000000LL, 20000000000LL, 30000000000LL};
    // Accessing elements in vector of long long integers
    for (const auto& ll : vecLongLongs) {
        cout << ll << " ";
    }
    cout << endl;

	return 0;
}


