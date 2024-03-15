#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to check if the given word can be broken
// down into words from the wordList
bool WordBreak(const vector<string>& wordList,
			const string& word)
{
	// If the word is empty, it can be broken down into
	// an empty list of words
	if (word.empty())
		return true;

	int wordLen = word.length();

	// Check if the word can be broken down into
	// words from the wordList
	for (int i = 1; i <= wordLen; ++i) {
		string prefix = word.substr(0, i);

		if (find(wordList.begin(), wordList.end(), prefix)
				!= wordList.end()
			&& WordBreak(wordList, word.substr(i))) {
			return true;
		}
	}

	return false;
}

int main()
{
	vector<string> wordList
		= { "mobile", "samsung", "sam", "sung", "man",
			"mango", "icecream", "and", "go", "i",
			"like", "ice",	 "cream" };

	bool result = WordBreak(wordList, "ilikesamsung");

	cout << boolalpha << result << endl; // Output: true

	return 0;
}
