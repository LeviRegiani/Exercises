#include<iostream>

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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode *tmp = list1;
		ListNode *result = nullptr;
		if (list1 == NULL) {
			return list2;
		} else if (list2 == NULL) {
			return list1;
		}
		if (list1->val <= list2->val) {
			result = list1;
			list1 = list1->next;
			result->next = list2;
			tmp = result->next;
		} else {
			result = list2;
			list2 = list2->next;
			result->next = list1;
			tmp = result->next;
		}
		while ((list1->next != NULL) && (list2->next != NULL)) {
			if ((list1->val <= list2->val) && (list2->val < list1->next->val)) {
				list1 = list1->next;
				tmp->next = list2;
				tmp = tmp->next;
			} else {
				list2 = list2->next;
				tmp->next = list1;
				tmp = tmp->next;
			}
		}
		if (list1->val <= list2->val) {
			list1->next = list2;
		} else {
			list2->next = list1;
		}
		return result;
	}
};