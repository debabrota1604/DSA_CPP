
// C++ program to demonstrate the use of a stringstream (via sstream header in c++)
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

/*
A stringstream associates a string object with a stream allowing you to read from the string as if it were a stream (like cin). To use stringstream, we need to include sstream header file. The stringstream class is extremely useful in parsing input. 

Basic methods are:
    clear()- To clear the stream.
    str()- To get and set string object whose content is present in the stream. 
    operator <<- Add a string to the stringstream object. 
    operator >>- Read something from the stringstream object.
*/

void convert_to_int()
{
	string s = "12345";

	// object from the class stringstream
	stringstream geek;

	// inserting string s in geek stream
	geek << s;

	// The object has the value 12345
	// and stream it to the integer x
	int x = 0;
	geek >> x; //x contains 12345

	// Now the variable x holds the value 12345
	cout << "Value of x + 1 : " << x + 1 << endl;
}

void convert_to_string()
{
	int val=123;

	// object from the class stringstream
	stringstream geek;

	// inserting integer val in geek stream
	geek << val;

	// The object has the value 123
	// and stream it to the string x
	string x;
	geek >> x;

	// Now the string x holds the
	// value 123
	cout<< "Value of int to string conversion: " << x+"4" <<endl;
}


// Tokenizing a string using stringstream

void tokenize()
{
	string line = "GeeksForGeeks is a must try";
	
	// stringstream class check1
	stringstream check1(line);
	
	string intermediate;
	
	// Vector of string to save tokens
	vector<string> tokens;
	
	// Tokenizing w.r.t. space ' '
	while(getline(check1, intermediate, ' '))
	{
		tokens.push_back(intermediate);
	}
	
	// Printing the token vector
    cout << "Tokens from the string \"" << line << "\" are: ";
    
	for(int i = 0; i < tokens.size(); i++)
		cout << "[" << tokens[i] << "] ";
    cout << endl;
}


int main(){
    convert_to_int();

    convert_to_string();

    tokenize();

    return 0;
}



