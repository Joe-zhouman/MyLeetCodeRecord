#pragma once
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

};
class solution_0023 {
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKLists(lists, 0, lists.size() - 1);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists,int i,int j) {
        if(i == j)return lists[i];
        if(i > j) return nullptr;
        int mid = (i + j) >> 1;
        return mergeTwoLists(mergeKLists(lists, i, mid), mergeKLists(lists, mid+1, j));
    }
};

