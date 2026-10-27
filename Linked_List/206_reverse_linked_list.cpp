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

// Recursive approach 
class Solution {
public:
    ListNode* helper(ListNode* prev, ListNode* cur){
        if(cur == nullptr)
            return prev;
        
        ListNode* next = cur->next;
        cur->next = prev;

        return helper(cur, next);
    }

    ListNode* reverseList(ListNode* head) {
        return helper(nullptr, head);
    }
};
