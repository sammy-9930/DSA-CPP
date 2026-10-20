/*
Brute force solution 
Time : O(n + n) 
Space : O(1)
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp = head;
        int totalCount = 0;
        while(tmp != nullptr){
            tmp = tmp->next;
            totalCount++;
        }

        int removeIdx = totalCount - n;

        if(removeIdx == 0){
            ListNode* dummy = head;
            head = head->next;
            delete dummy;
            return head;
        }

        tmp = head;

        for(int i = 0; i < removeIdx; i++){
            if(i == removeIdx - 1){
                ListNode* dummy = tmp->next;
                tmp->next = tmp->next->next;
                delete dummy;
                break;
            }
            tmp = tmp->next;
        }
        return head;
    }
};

// time : O(n) 
// space : O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        for(int i=0; i<n; i++){
            fast = fast->next;
        }

        if(fast == nullptr){
            ListNode* dummy = head;
            head = head->next;
            delete dummy;
            return head;
        }

        ListNode* slow = head;

        while(fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* dummy = slow->next;
        slow->next = slow->next->next;
        delete dummy;
        return head;
    }
};
