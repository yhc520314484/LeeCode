/* 
   Leecode 20 Merge Two Sorted Lists
   Level: Simple

   Author: JackWilliam
   Date: 9, May, 2020
*/

/*
    Version 0.1   
       关键引入头节点，然后新建另一个节点指针用于链表合并
       暴力做法
    12ms  7.1MB
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *newHead = new ListNode(-1);         //key:引入头节点
        ListNode *prev = newHead;                     //key:新建一个新的指针用于节点合并


        while(l1 != nullptr && l2 != nullptr){
            if(l1->val < l2->val){
                prev->next = l1;
                l1 = l1->next;
            }
            else
            {
                prev->next = l2;   
                l2 = l2->next;             
            }
            prev = prev->next;
        }
        if(l1 == nullptr) prev->next = l2;
        else prev->next = l1;
        
        return newHead->next;
    }
};

/*
    Other Solution
    Key Point:将大问题分解成小问题，然后通过递归求解

    Source: LeetCode
    Author: LeetCode-Solution
    Url: https://leetcode-cn.com/problems/merge-two-sorted-lists/solution/he-bing-liang-ge-you-xu-lian-biao-by-leetcode-solu/
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        } else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
