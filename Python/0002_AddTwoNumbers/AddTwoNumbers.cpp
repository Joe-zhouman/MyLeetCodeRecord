#pragma once
#include <cstddef>

struct ListNode {
	int val;
	ListNode* next;

	ListNode(int x) : val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode(0);
		ListNode* ans = head;
		int carry = 0;
		int sumVal;
		while (l2 != NULL && l1 != NULL) {
			sumVal = l1->val + l2->val + carry;
			carry = sumVal >= 10;			
			ans->next = new ListNode(carry ? sumVal - 10 : sumVal);
			l1 = l1->next;
			l2 = l2->next;
			ans = ans->next;
		}
		ListNode* l3 = l1 == NULL ? l2 : l1;
		while (l3 != NULL) {
			sumVal = l3->val + carry;
			carry = sumVal >= 10;
			ans->next = new ListNode(carry ? sumVal - 10 : sumVal);
			l3 = l3->next;
			ans = ans->next;
		}
		if (carry)
			ans->next = new ListNode(1);
		return head->next;

	}
};
