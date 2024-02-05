#include <iostream>
#include <string>
#include <vector>
using namespace std;

int compress(vector<char>& chars);

int main() {
	// Given an array of characters chars, compress it using the following algorithm:

	// Begin with an empty string s. For each group of consecutive repeating characters in chars :

	// If the group's length is 1, append the character to s.
	// Otherwise, append the character followed by the group's length.
		// The compressed string s should not be returned separately, but instead, be stored in the input character array chars.
		// Note that group lengths that are 10 or longer will be split into multiple characters in chars.

		// After you are done modifying the input array, return the new length of the array.

		// You must write an algorithm that uses only constant extra space.
	vector<char> chars{ 'a', 'b', 'c', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b' };
	compress(chars);
	for (char element : chars) {
		cout << element;
	}

	return 0;
}

int compress(vector<char>& chars) {
	int length = chars.size();

	// Edge Cases
	if (length == 0 || length == 1) { return length; }
	
	// Use a two-pointer approach
	int write = 0, count = 1;

	for (int read = 1; read <= length; ++read) {
		// Check for consecutive duplicate chars
		if (read < length && chars[read] == chars[read - 1]) {
			++count;
		}
		else {
			chars[write++] = chars[read - 1];

			if (count > 1) {
				// Convert int count to a char
				for (char c : to_string(count)) {
					chars[write++] = c;
				}
			}

			// Reset the count and get next character
			count = 1;
		}
	}

	// Resize vector
	chars.resize(write);

	return write;
}
