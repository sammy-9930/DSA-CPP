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
