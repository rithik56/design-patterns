#include<iostream>
using namespace std;

class Node {
    private:
        int val;
        Node* left;
        Node* right;
        Node* next;
        vector<Node*> neighbors;
    public:
        Node(int val) {
            this->val = val;
            this->left = nullptr;
            this->right = nullptr;
            this->next = nullptr;
        }
        void setLeft(Node* left) {
            this->left = left;
        }
        void setRight(Node* right) {
            this->right = right;
        }
        void setNext(Node* next) {
            this->next = next;
        }
        Node* getLeft() {
            return this->left;
        }
        Node* getRight() {
            return this->right;
        }
        Node* getNext() {
            return this->next;
        }
        int getVal() {
            return this->val;
        }
};

class NodeIterator {
    public:
        virtual Node* getNext() = 0;
        virtual bool hasNext() = 0;
};

class NodeCollection {
    public:
        virtual NodeIterator* getNodeIterator() = 0;
};

class PreOrderNodeIterator: public NodeIterator {
    private:
        stack<Node*> st;
    public:
        PreOrderNodeIterator(Node* root) {
            st.push(root);
            while (root->getLeft()) {
                st.push(root->getLeft());
                root = root->getLeft();
            }
        }
        Node* getNext() override {
            Node* ans = st.top();
            st.pop();
            if (ans->getRight()) {
                st.push(ans->getRight());
                if (ans->getRight()->getLeft()) {
                    Node* temp = ans->getRight();
                    while (temp->getLeft()) {
                        st.push(temp->getLeft());
                        temp = temp->getLeft();
                    }
                }
            }
            return ans;
        }
        bool hasNext() override{
            return !st.empty();
        }
};

class LinkedListNodeIterator: public NodeIterator {
    private:
        Node* curr;
    public:
       LinkedListNodeIterator(Node* head) {
            this->curr = head;
       }
       Node* getNext() override {
            Node* ans = this->curr;
            this->curr = this->curr->getNext();
            return ans;
       }
        bool hasNext() override {
            return curr != nullptr;
        }
};

int main() {
    Node* root = new Node(1);
    Node* node1 = new Node(2);
    Node* node2 = new Node(3);
    Node* node3 = new Node(4);
    Node* node4 = new Node(5);
    Node* node5 = new Node(6);
    Node* node6 = new Node(7);

    root->setLeft(node1);
    root->setRight(node2);

    node1->setLeft(node3);
    node1->setRight(node4);

    node2->setLeft(node5);
    node2->setRight(node6);

    Node* head = new Node(100);
    Node* first = new Node(101);
    Node* second = new Node(102);
    head->setNext(first);
    first->setNext(second);

    NodeIterator* preOrderIterator = new PreOrderNodeIterator(root);

    // 4 2 5 1 6 3 7 
    while (preOrderIterator->hasNext()) {
        cout << preOrderIterator->getNext()->getVal() << " ";
    }

    cout << endl;

    NodeIterator* linkedListIterator = new LinkedListNodeIterator(head);

    // 100 101 102 
    while (linkedListIterator->hasNext()) {
        cout << linkedListIterator->getNext()->getVal() << " ";
    }

    cout << endl;

    return 0;
}
