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
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* p = slow->next;
        slow->next = nullptr;
        ListNode* q = nullptr;
        ListNode* r = nullptr;
        while(p != nullptr){
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }

        ListNode* a = head;
        ListNode* b = q;
        while(a != nullptr && b != nullptr){
            ListNode* c = a->next;
            a->next = b;
            a = c;
            ListNode* d = b->next;
            b->next = a;
            b = d;
        }

    }
};
