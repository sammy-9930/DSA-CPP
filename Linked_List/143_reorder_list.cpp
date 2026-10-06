/*
Brute force
Time complexity: O(n)
Space complexity: O(n) 
*/
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr)
            return; 

        vector<ListNode*> nodes;
        ListNode* cur = head;

        while(cur){
            nodes.push_back(cur);
            cur = cur->next;
        }

        int i=0;
        int j=nodes.size()-1;

        while (i < j){
            nodes[i]->next = nodes[j];
            i++; 

            if(i >= j) break;

            nodes[j]->next = nodes[i];
            j--;
        }
        nodes[i]->next = nullptr;
    }
};


/*
Reverse and Merge 
Time complexity: O(n)
Space complexity: O(1)
*/
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next; 
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* tmp1 = nullptr;
        ListNode* tmp2 = nullptr;
        ListNode* tmp = slow->next;
        slow->next = nullptr;

        while(tmp){
            tmp2 = tmp1;
            tmp1 = tmp;
            tmp = tmp->next;
            tmp1->next = tmp2;
        }

        ListNode* first = head;
        ListNode* second = tmp1;
        while(second != nullptr){
            ListNode* tmp3 = first->next;
            ListNode* tmp4 = second->next;
            first->next = second;
            second->next = tmp3;
            first = tmp3;
            second = tmp4;
        }
    }
};
