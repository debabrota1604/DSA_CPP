#include<iostream>
#include <cstdlib> // for atoi
#include<bits/stdc++.h>
using namespace std;


/* Few basic functions


*/
void reverseStr(string& s) // Function to reverse a string
{  
    int n = s.length();
    for (int i = 0; i < n/2; i++)
        swap(s[i], s[n-i-1]);
}


string returnFloatingPart(string str)// returns floating point part of a number-string
{
    int pos = str.find(".");
    if (pos == string::npos)
        return "";
    else
        return str.substr(pos + 1);
}

bool containsOnlyDigit(string str)// checks whether a string contains all digit or not
{
    int l = str.length();
    for (int i = 0; i < l; i++)
    {
        if (str.at(i) < '0' || str.at(i) > '9')
            return false;
    }
    return true;//  if we reach here all character are digits
}

string replaceBlankWith20(string str) //replaces all single space by '%20' Used in URLS
{
    string replaceby = "%20";
    int n = 0;
  
    while ((n = str.find(" ", n)) != string::npos ){ // loop till all space are replaced
        str.replace(n, 1, replaceby);
        n += replaceby.length();
    }
    return str;
}

int my_atoi(const char *p) { // converts decimal str to int
    int k = 0;
    while (*p) {
        k = k*10 + (*p++) - '0';
     }
     return k;
}

int my_strtol(const char *p){ //converts binary str to int
    //char* start = &binaryCharArray[0];
    int total = 0;
    while (*p){
        total <<= 1; //total *= 2;
        if (*p++ == '1') total^=1; //total += 1;
    }
    return total;
}



int main(){
    /*
    In C++, in addition to character array, there exist a similar kind of way to implement string, 
    that is using string class which is a part of C++ standard library. To implement string using 
    string class, we need to add header file. 

    Basic difference between character array and a string is, in case of character array, the size
    has to be allotted at the time of declaration, i.e all memory once allocated is fixed and 
    cannot be altered at run time. Whereas, for string, there is no need to specify the size and 
    to allocate fixed memory at the time of declaration.

    Few interesting features of string class:
        1. Can allocate/change strings dynamically:
            push_back(): str1.push_back('a')
            pop_back(): char ch = str1.pop_back()
            getline(): getline(cin, str1)

        2. Capacity functions:
            capacity(): returns the capacity allocated to the string, which can be equal to or more
                than the size of the string. Additional space is to efficiently allocate new chars.
            resize(): changes the size of the string, the size can be increased or decreased. eg:
                    str1.resize(5); // changes the string size to 5.
            length(): returns the actual length of the string. a synonymous function is size()
            shrink_to_fit(): decreases the capacity of the string and makes it equal to the minimum 
                capacity of the string. This operation is useful to save additional memory if we are 
                sure that no further addition of characters has to be made. Eg:
                    str1.shrink_to_fit(); //changes the string size to minimum that allocate all chars
        
        3. Iterator functions: begin(), end(), rbegin(), rend().

        4. Manipulating functions:
            copy("char array", len, pos): copies the substring in the target character array mentioned
                in its arguments. works on already initialized strings (cannot resize for copying)

            swap(): This function swaps one string with other. Eg:
                    str1.swap(str2) //str2 contents come to str1 and vice-versa

            clear(): Delete all characters from string. eg,
                    str1.clear()

            empty(): Tests whether the string is empty. This function return a Boolean value.

            erase(a, b): Deletes b characters at index a. Eg,
                    str6.erase(7,4); or str6.erase(str6.begin() + 5, str6.end() - 3);

            replace(p, q, str): replaces q characters from index p by str.
                    str6.replace(2, 7, "ese are test");
            
            insert(pos_to_begin,string_to_insert): This function inserts the given substring in the 
                string. It takes two arguments, first the position from which you want 
                to insert the substring and second the substring.

            reverse(str.begin(), str.end())
        
        5. Access functions
            at() or []: access a particular position in string using at() or the '[]' operator

            front() and back(): returns the first and last character. Eg:
                char ch = str6.front();  // Same as "ch = str6[0];"
                char ch2 = str6.back();   // Same as "ch2 = str6[str6.length() - 1];"

            append(): add the argument string at the end. Eg:
                str6.append(" extension"); // same as str6 += " extension"
                str4.append(str6, 0, 6);  // at 0th position 6 character

            find(): returns the index where the pattern is found. eg:
                if (str6.find(str4) != string.length())
                    cout << "str4 found in str6 at " << str6.find(str4) << " pos" << endl;

            find_first_of(“string”): Searches the string for the first character that 
                matches any of the characters specified in its arguments. It returns 
                the position of the first character that matches.
            
            find_last_of(“string”): Searches the string for the last character that 
                matches any of the characters specified in its arguments. It returns 
                the position of the last character that matches.

            rfind(“string”): Searches the string for the last occurrence of the 
                substring specified in arguments. It returns the position of the last 
                occurrence of substring

            substr(p,q): returns a substring of q length starting from index p. Eg:
                cout << str6.substr(7, 3);


    */


    //-----------------------------------------------------------Input a string
    //declare a string
    string str1("Just A String...");

    //initialization by another string
    string str2(str1);
    //initialization from another string part
    string str3(str1, 2, 8);
    //initialization from another string part with iterators
    string str4(str1.begin(), str1.begin()+8);
    //initialization from another string part with iterators
    string str5(str1.rbegin(), str1.rend()); //str5.copy("An example C-string for copying to a string variable...",5,10);

    //initialization by char with occurences
    string str6(5, '$');

    //initialization from std input
    string str7; cout << "Enter a string: ";getline(cin, str7);

    cout << "The strings are: " << endl <<
        "str1: " << str1 << endl <<
        "str2: " << str2 << endl <<
        "str3: " << str3 << endl <<
        "str4: " << str4 << endl <<
        "str5: " << str5 << endl <<
        "str6: " << str6 << endl <<
        "str7: " << str7 << endl;

    //---------------------------------------------------------------size, capacity, resize, length
    cout << "\nSizes: " << endl <<
        "str1: " << str1.size() << endl <<
        "str2: " << str2.size() << endl <<
        "str3: " << str3.size() << endl <<
        "str4: " << str4.size() << endl <<
        "str5: " << str5.size() << endl <<
        "str6: " << str6.size() << endl <<
        "str7: " << str7.size() << endl;

    cout << "\nCapacities: " << endl <<
        "str1: " << str1.capacity() << endl <<
        "str2: " << str2.capacity() << endl <<
        "str3: " << str3.capacity() << endl <<
        "str4: " << str4.capacity() << endl <<
        "str5: " << str5.capacity() << endl <<
        "str6: " << str6.capacity() << endl <<
        "str7: " << str7.capacity() << endl;

    cout << "\nLength: " << endl <<
        "str1: " << str1.length() << endl <<
        "str2: " << str2.length() << endl <<
        "str3: " << str3.length() << endl <<
        "str4: " << str4.length() << endl <<
        "str5: " << str5.length() << endl <<
        "str6: " << str6.length() << endl <<
        "str7: " << str7.length() << endl;

    str1.resize(10); 
    cout << "\nPost resize capacity: " << endl <<
        "str1: " << str1.length() << endl;
        
    //------------------------------------------------------------------array of strings
    cout << "\nArray of strings..................\n";
    //method 1: array of pointers: Works on BOTH C and C++
        const char *colour[4] = { "Blue", "Red", "Orange", "Yellow" };
    
        // Printing Strings stored in 2D array
        cout << "Printing Strings stored in array of pointers: ";
        for (int i = 0; i < 4; i++)
            cout << colour[i] << " ";
        cout << endl;

    //method 2: Using 2D array: Works on BOTH C and C++
    /*
        This method is useful when the length of all strings is known and a particular memory 
        footprint is desired. Space for strings will be allocated in a single block.
    */
        // Initialize 2D array
        char colour2[4][10] = { "Blue", "Red", "Orange",
                            "Yellow" };
    
        // Printing Strings stored in 2D array
        cout << "Printing Strings stored in 2D char array: ";
        for (int i = 0; i < 4; i++)
            cout << colour2[i] << " ";
        cout << endl;
    
    //method 3: Using the string class: supported ONLY in C++, as C does not have classes
    /*
        The STL string class may be used to create an array of mutable strings. The size of 
        the string is not fixed, and the strings can be changed. 
    */
        // Initialize String Array
        string colour3[4] = { "Blue", "Red","Orange", "Yellow" };
    
        // Print Strings
        cout << "Printing Strings stored in C++ String Array: ";
        for (int i = 0; i < 4; i++)
            cout << colour3[i] << " ";
        cout << endl;

    //method 4: Using the vector class
    /*
        The STL container Vector can be used to dynamically allocate an array that can vary in size.
        This is only usable in C++, as C does not have classes. Note that the initializer-list 
        syntax here requires a compiler that supports the 2011 C++ standard, and though it is 
        quite likely your compiler does, it is something to be aware of.
    */
        // Declaring Vector of String type
        // Values can be added here using initializer-list syntax
        vector<string> colour4 {"Blue", "Red", "Orange"};
    
        // Strings can be added at any time with push_back
        colour4.push_back("Yellow");
    
        // Print Strings stored in Vector
        cout << "Printing Strings stored in C++ Vector<string>: ";
        for (int i = 0; i < colour4.size(); i++)
            cout << colour4[i] << " ";
        cout << endl;

    //----------------------------------------------------------------- String to integer and vice-versa
    //method 1: String conversion using stoi() or atoi().
    cout << "\nString to integer......................\n";
    string str10 = "11.23"; cout << "Incremented " << str10  << " is: " << stoi(str10)+1 << endl;

    cout << "Printing string version of integer 11.2456: " << to_string(11.2456) << endl;

    const char* str11 = "42";
    const char* str12 = "3.14159";
    const char* str13 = "31337 geek";
    const char* str14 = "10011";
 
    int num1 = atoi(str11);
    int num2 = atoi(str12);
    int num3 = atof(str12);
    int num4 = atoi(str13);
 
    cout << "atoi(\"" << str11 << "\") is " << num1 << '\n';
    cout << "atoi(\"" << str12 << "\") is " << num2 << '\n';
    cout << "atof(\"" << str12 << "\") is " << num3 << '\n';
    cout << "atoi(\"" << str13 << "\") is " << num4 << '\n';


    cout << "my_atoi(\"" << str11 << "\") is " << my_atoi(str11) << '\n';
    cout << "my_strtol(\"" << str14 << "\") is " << my_strtol(str14) << '\n';

}