## Introduction

This project presents an efficient algorithm for compressing a sequence of characters in-place, using a two-pointer technique. It's designed for scenarios where minimizing memory usage is critical, such as embedded systems or high-performance computing environments. The algorithm takes a vector of characters, compresses it by consolidating consecutive duplicate characters into a single character followed by the count of repetitions, and updates the vector in place to reflect the compressed sequence.

## Algorithms

### **1. Character Compression**

#### Logic

- The algorithm iterates through the array of characters, using a two-pointer technique to efficiently compress consecutive repeating characters. For each group of consecutive characters, it appends the character and, if the group's length is greater than one, also appends the count of the repetitions. This process is performed in-place, directly modifying the input vector of characters.

#### Complexity Analysis

- **Time Complexity:** O(n), where n is the number of characters in the input vector. The algorithm needs to iterate over all characters exactly once.
- **Space Complexity:** O(1), as the compression is done in place with only a constant amount of extra space needed for counters and temporary storage, independent of the input size.

### Code Snippet

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int compress(vector<char>& chars);

int main() {
	vector<char> chars{ 'a', 'b', 'c', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b' };
	compress(chars);
	for (char element : chars) {
		cout << element;
	}
	return 0;
}

int compress(vector<char>& chars) {
	int length = chars.size();
	if (length == 0 || length == 1) { return length; }
	int write = 0, count = 1;
	for (int read = 1; read <= length; ++read) {
		if (read < length && chars[read] == chars[read - 1]) {
			++count;
		} else {
			chars[write++] = chars[read - 1];
			if (count > 1) {
				for (char c : to_string(count)) {
					chars[write++] = c;
				}
			}
			count = 1;
		}
	}
	chars.resize(write);
	return write;
}
```