#include <iostream>

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int value){
            data = value;
            left = right = nullptr;
        }
}; 

class BinarySearchTree{
    private:
        Node* root;

        void inorderHelper(Node* root){
            if (root != nullptr)
            {
                inorderHelper(root->left);
                std::cout << root->data << " ";
                inorderHelper(root->right);
            }
        }

    public:
        BinarySearchTree(){
            root = nullptr;
        }

        Node* insertIterative(int key){
            if (root == nullptr){
                Node* newNode = new Node(key);
                root = newNode;
                return root;
            }
                
            Node* current = root;
            Node* parent = nullptr;

            while (current != nullptr){
                parent = current;
                if (current->data == key)
                    return root;
                else if (key < current->data)
                    current = current->left;
                else
                    current = current->right;
            }
            Node* newNode = new Node(key);
            if (key > parent->data)
                parent->right = newNode;
            else
                parent->left = newNode;
            return root;
        }

        bool searchIterative(int key){
            Node* current = root;
            while (current != nullptr){
                if (current->data == key){
                    return true;
                }
                else if (current->data < key){
                    current = current->right;
                }
                else{
                    current = current->left;
                }
            }
            return false;
        }

        void inorder(){
            inorderHelper(root);
        }
};

int main()
{
    BinarySearchTree bst;
    bst.insertIterative(30);
    bst.insertIterative(20);
    bst.insertIterative(25);
    int key = 30;
    if (bst.searchIterative(key))
        std::cout << "Found " << key << " in the BST.\n";
    else
        std::cout << key << " not found in the BST.\n";
    bst.inorder();
}