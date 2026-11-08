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
Time complexity - O(m + n)  m - length of list1, n - length of list2 
Space complexity - O(1) 
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* tmp1 = list1;
        ListNode* tmp2 = list2;
        ListNode* dummy(-1);
        ListNode* tmp3 = &dummy;

        while(tmp1 && tmp2){
            if(tmp1->val < tmp2->val){
                tmp3->next = tmp1;
                tmp1 = tmp1->next;
            }
            else{
                tmp3->next = tmp2;
                tmp2 = tmp2->next;
            }
            tmp3 = tmp3->next;
        }

        if(tmp1){
            tmp3->next = tmp1;
        }

        if(tmp2){
            tmp3->next = tmp2;
        }
        return dummy->next;
    }
};

