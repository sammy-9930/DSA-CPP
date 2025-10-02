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
/*
Iterative 
time : O(n)
space : O(1)
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        while (cur){
            auto nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
};

/*
Recursive 
time : O(n)
space : O(n)
*/
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
    void rHelper(ListNode*& head, ListNode* cur, ListNode* prev){
        if (cur != nullptr){
            rHelper(head, cur->next, cur);
            cur->next = prev;
        }
        else{
            head = prev;
        }
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        rHelper(head, cur, prev);
        return head;
    }
};