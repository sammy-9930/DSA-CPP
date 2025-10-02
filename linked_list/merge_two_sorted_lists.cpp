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
Recursive approach 
time: O(n+m)
space: O(n+m)
where n and m are the lengths of the two lists
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1){
            return list2;
        }

        if (!list2){
            return list1;
        }

        if (list1->val <= list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else{
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

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
Iterative approach 
time: O(n+m)
space: O(1)
where n and m are the lengths of the two lists
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* temp = &dummy;
        while (list1 && list2){
            if (list1->val <= list2->val){
                temp->next = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        if (list1){
            temp->next = list1;
        }
        else{
            temp->next = list2;
        }
        return dummy.next;
    }
};