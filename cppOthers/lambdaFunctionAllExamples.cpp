#include<iostream>
#include<cmath>
using namespace std;

auto goodMorning = [](){
    cout << "Good Morning!" << endl;
};

// return type as int is not working.
auto getSquare = [](int num) ->int {
    return num*num;
};

int main(){
    /*   C++ 11 lambda features */
    //Example 11.1: No parameter
    cout << "Lambda function (C++11): " << endl;
    goodMorning();

    //Example 11.2: One parameter
    cout << "parameter capture (C++11): " << endl;
    int num =5;
    cout << "Square of " << num << ": " << getSquare(num)  << endl;;

    //Example 11.3: Implicit parameter capture
    cout << "Implicit parameter capture by reference (C++11):" << endl;
    int x = 10;
    auto getSquareImplicitly = [x](){
        cout << "Square of " << x << ": " << x*x << endl;
    };
    getSquareImplicitly();


    // Example 11.4: parameter capture by reference
    cout << "Parameter capture by reference (C++11):" << endl;
    int y = 11;
    cout << "y is: " << y << endl;
    auto getSquareReference = [&y](){
        y = y*y;
    };
    getSquareReference();
    cout << "y is: " << y << endl;
    getSquareReference();
    cout << "y is: " << y << endl;


    /*   C++ 14 lambda features */
    //Example 14.1: generic lambda
    auto calculateSum = [](auto x, auto y){
        return x+y;
    };
    cout << "generic lambda example (C++14): " << x << " " << y << " " << calculateSum(x,y) << endl;

    float p=2.13, q= 3.14;
    cout << "generic lambda example (C++14): " << p << " " << q << " " << calculateSum(x,y) << endl;


    //Example 14.2: auto type deduction
    auto calculateRoot = [](int x){
        return sqrt(x);
    };
    cout << "auto type deduction lambda example (C++14): " << x << " " << calculateRoot(x) << endl;

    //Example 14.3:Lambda with init-capture
    int t = 42;
    auto lambda_initCapture = [s = t + 10]() {
        std::cout << "Captured and initialized s (C++14): " << s << std::endl;
    };

    lambda_initCapture();



    /* C++17 lambda features*/
    // Feature 17.1: Structured Bindings in Lambda Return (C++17)
    auto getPair = []() {
        return std::make_pair(42, "Hello");
    };
    auto [number, text] = getPair();
    std::cout << "Structured Bindings in Lambda Return (C++17): " << number << ", " << text << std::endl;

    // Feature 17.2: if with Initialization (C++17)
    int value, condition=1;
    auto lambda_if = [condition]() -> int {
        if (condition == 1) {
            int value = 50;
            return value;
        } else {
            int value = 100;
            return value;
        }
    };
    cout << "If with initialization (C++17): " << lambda_if() << endl;




    /*  C++20 features*/
    int m = 42, n = 10;
    auto lambda_flexible = [a = m, &b = n] {
        // 'a' is captured by value, 'b' is captured by reference
        //a++; //cannot be done.
        b++;
    };
    cout << "Combine multiple captures:  (C++20)" << endl;
    cout << m << " " << n << endl;
    lambda_flexible();
    cout << m << " " << n << endl;


}