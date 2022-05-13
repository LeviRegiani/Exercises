#include<iostream>

using namespace std;

// https://leetcode.com/problems/merge-two-sorted-lists/
// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.

// Example 1:

// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]

// Example 2:

// Input: list1 = [], list2 = []
// Output: []

// Example 3:

// Input: list1 = [], list2 = [0]
// Output: [0]

// Constraints:

// 	The number of nodes in both lists is in the range [0, 50].
// 	-100 <= Node.val <= 100
// 	Both list1 and list2 are sorted in non-decreasing order.


// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		if (list1 == NULL) {
			return list2;
		} else if (list2 == NULL) {
			return list1;
		}
		ListNode *result = list1;
		if (list1->val > list2->val) {
			result = list2;
			list2 = list2->next;
		} else {
			list1 = list1->next;
		}
		
		ListNode *curr = result;
		
		while (list1 && list2) {
			if (list1->val < list2->val) {
				curr->next = list1;
				list1 = list1->next;
			} else {
				curr->next = list2;
				list2 = list2->next;
			}
			curr = curr->next;
		}
		
		if (!list1)
			curr->next = list2;
		else
			curr->next = list1;
		
		return result;
	}
};

// Try out some different lists combinations!
int main() {
	Solution mySolution;
	ListNode a(1);
	ListNode b(3);
	a.next = &b;
	ListNode c(5);
	b.next = &c;
	ListNode d(2);
	ListNode e(5);
	d.next = &e;
	ListNode f(7);
	e.next = &f;
	ListNode *result = mySolution.mergeTwoLists(&a, &d);
	ListNode *iterr = result;
	while (iterr) {
		cout << iterr->val << ' ';
		iterr = iterr->next;
	}
	cout << '\n';
	return 0;
}