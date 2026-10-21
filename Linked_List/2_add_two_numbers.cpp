/*
Time complexity: O(max(m,n))
Time complexity: O(max(m,n))
Where m is the length of l1 and n is the length of l2.
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        int carry = 0;
        while(t1 != nullptr || t2 != nullptr){
            int curTotal = carry;
            if (t1 != nullptr)
                curTotal += t1->val;
            if (t2 != nullptr)
                curTotal += t2->val;
            ListNode* newNode = new ListNode(curTotal % 10);
            carry = curTotal / 10;
            cur->next = newNode;
            cur = cur->next;
            if (t1 != nullptr)
                t1 = t1->next;
            if (t2 != nullptr)
                t2 = t2->next;
        }
        if (carry){
            ListNode* newNode = new ListNode(carry);
            cur->next = newNode;
        }
        return dummy->next;
    }
};
