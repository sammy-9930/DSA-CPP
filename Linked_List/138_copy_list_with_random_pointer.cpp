/*
Brute force solution
time complexity: O(n) + O(n)
space complexity: O(n) + O(n)
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* tmp = head;
        unordered_map<Node*, Node*> map;
        // create dummy node and store in hashmap
        while(tmp != nullptr){
            Node* newNode = new Node(tmp->val);
            map[tmp] = newNode;
            tmp = tmp->next;
        }

        tmp = head;
        while(tmp != nullptr){
            Node* copyNode = map[tmp];
            copyNode->next = map[tmp->next];
            copyNode->random = map[tmp->random];
            tmp = tmp->next;
        }
        return map[head];   
    }
};

/*
Space optimized
time complexity: O(n)
space complexity: O(1), O(n) for output
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* tmp = head;
        while(tmp != nullptr){
            Node* newNode = new Node(tmp->val);
            newNode->next = tmp->next;
            tmp->next = newNode;
            tmp = tmp->next->next;
        }

        tmp = head;

        while(tmp != nullptr){
            Node* copyNode = tmp->next;
            if(tmp->random != nullptr)
                copyNode->random = tmp->random->next;
            tmp = tmp->next->next;
        }

        Node* dummy = new Node(-1);
        Node* res = dummy;
        tmp = head;
        while(tmp != nullptr){
            res->next = tmp->next;
            tmp->next = tmp->next->next;

            res = res->next;
            tmp = tmp->next;
        }
        return dummy->next;
    }
};
