#pragma once
/*****************************************************************//**
 * \file   solution_0021.h
 * \brief  合并两个升序链表
 * 
 * \author Administrator
 * \date   March 2023
 *********************************************************************/
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};
class solution_0021 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        if(list1->val > list2->val) {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
};

