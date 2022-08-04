#include<iostream>
#include<string>
#include<math.h> 

// https://leetcode.com/problems/palindrome-number/
// Given an integer x, return true if x is palindrome integer.
// An integer is a palindrome when it reads the same backward as forward.
// 	For example, 121 is a palindrome while 123 is not.

// Example 1:

// Input: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.

// Example 2:

// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

// Example 3:

// Input: x = 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.


// Constraints:
// 	-231 <= x <= 231 - 1

// Follow up: Could you solve it without converting the integer to a string?

class Solution {
public:
	bool isPalindrome(int x) {
		std::string xString = std::to_string(x);
		for (int i = 0; i <= floor((xString.length() - 1) / 2); i++) {
			if (xString[i] != xString[xString.length() - i - 1]) {
				return 0;
			}
		}
		return 1;
	}

	bool isPalindromeNum(int x ) {
		if (x < 0 || (x % 10 == 0 && x != 0)) {
			return 0;
		}
		int revNum = 0;
		while (x > revNum) {
			revNum = revNum * 10 + x % 10;
			x /= 10;
		}
		return x == revNum || x == revNum / 10;
	}
};

int main() {
	Solution mySolution;
	int x = 101;
	bool result = mySolution.isPalindromeNum(x);
	std::cout << result << '\n';
	return 0;
}