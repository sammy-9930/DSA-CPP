/*
Brute force
Time complexity: O(n)
Space complexity: O(n) 
*/
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;
        ListNode* cur = head;

        while(cur){
            nodes.push_back(cur);
            cur = cur->next;
        }

        int left = 0;
        int right = nodes.size() - 1;

        while(left < right){
            nodes[left]->next = nodes[right];
            left++;

            if(left == right){
                break;
            }

            nodes[right]->next = nodes[left];
            right--;
        }
        nodes[left]->next = nullptr;

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
