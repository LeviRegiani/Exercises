#include<iostream>
#include<string>
#include<stack>

using namespace std;

// https://leetcode.com/problems/valid-parentheses/
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:
//     Open brackets must be closed by the same type of brackets.
//     Open brackets must be closed in the correct order.
 
// Example 1:
// Input: s = "()"
// Output: true

// Example 2:
// Input: s = "()[]{}"
// Output: true

// Example 3:
// Input: s = "(]"
// Output: false

// Constraints:
//     1 <= s.length <= 104
//     s consists of parentheses only '()[]{}'.

class Solution {
public:
	bool isValid(string s) {
		stack<char> stack;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
				stack.push(s[i]);
			} else if (stack.empty()) {
				return false;
			} else if ((stack.top() == '(') && (s[i] == ')')) {
				stack.pop();
			} else if ((stack.top() == '{') && (s[i] == '}')) {
				stack.pop();
			} else if ((stack.top() == '[') && (s[i] == ']')) {
				stack.pop();
			} else {
				return false;
			}
		}
		if (stack.size() == 0) {
			return true;
		}
		return false;
	}
};

int main() {
	Solution mySolution;
	string string = "{{}[][[[]]]}";
	cout << mySolution.isValid(string) << endl;
	return 0;
}