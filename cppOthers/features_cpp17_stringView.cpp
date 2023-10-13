#include <iostream>
#include <string>
#include <string_view>

/*
std::string_view is a class introduced in C++17 to provide a non-owning, lightweight view of a string, making it easier and more efficient to work with strings without the need for unnecessary copying or memory allocation. It allows you to operate on sequences of characters without owning the underlying data.
*/

int main() {
    // Create string_views from different sources
    std::string str = "Hello, World!";
    const char* cstr = "Goodbye, Universe!";
    std::string_view sv_literal("Literal View");
    std::string_view sv_string(str);
    std::string_view sv_cstr(cstr);

    // Accessing data and length
    const char* data = sv_string.data();
    std::size_t length = sv_cstr.size();

    std::cout << "sv_literal: " << sv_literal << std::endl;
    std::cout << "sv_string: " << sv_string << std::endl;
    std::cout << "sv_cstr: " << sv_cstr << std::endl;
    std::cout << "sv_literal length: " << sv_literal.size() << std::endl;

    // Viewing substrings
    std::string_view substr = sv_string.substr(0, 5); // "Hello"
    std::cout << "Substring of sv_string: " << substr << std::endl;

    // Comparison
    bool areEqual = (sv_string == sv_cstr);
    bool isLess = (sv_literal < sv_string);
    std::cout << "sv_string is equal to sv_cstr: " << std::boolalpha << areEqual << std::endl;
    std::cout << "sv_literal is less than sv_string: " << std::boolalpha << isLess << std::endl;

    // Conversion to std::string
    std::string converted_str(sv_literal);
    std::cout << "Converted string: " << converted_str << std::endl;

    // Usage in functions
    void printString(std::string_view str) {
        std::cout << "Function output: " << str << std::endl;
    }

    printString(sv_literal);
    printString(sv_string);

    return 0;
}


/*
std::string_view is valuable for string handling, especially when dealing with large strings or when performance optimization is important. It helps in reducing the overhead of creating temporary strings and enhances the efficiency of string-related operations.
*/