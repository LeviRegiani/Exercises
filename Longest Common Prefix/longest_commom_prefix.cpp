#include<iostream>
#include<vector>
#include<string>

using namespace std;

// https://leetcode.com/problems/longest-common-prefix/
// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".


// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"

// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.


// Constraints:

//   1 <= strs.length <= 200
//   0 <= strs[i].length <= 200
//   strs[i] consists of only lower-case English letters.

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
	if (strs.size() == 0) return "";
	string prefix = strs[0];
	for (int i = 1; i < strs.size(); i++)
		while (strs[i].find(prefix) != 0) {
			prefix = prefix.substr(0, prefix.length() - 1);
			if (prefix.empty()) return "";
		}
	return prefix;
	}
};

int main() {
	Solution mySolution;
	vector<string> strs = {"flower","flow","flight"};
	string result = mySolution.longestCommonPrefix(strs);
	cout << result << "\n";
	return 0;
}