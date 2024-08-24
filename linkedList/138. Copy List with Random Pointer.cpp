# by own
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertNode(Node*& head, int value) {
        // Create the new node to be inserted
        Node* newNode = new Node(value);

        // If the list is empty, the new node becomes the head
        if (head == nullptr) {
            head = newNode;
        } else {
            // Traverse to the end of the list
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            // Append the new node at the end
            current->next = newNode;
        }
    }
    Node* copyRandomList(Node* head) {
        Node* h2 = nullptr;
        Node* temp = head;
        int count = 0;
        while (temp != nullptr) {
            insertNode(h2, temp->val);
            temp->val = count;
            temp=temp->next;
            count++;
        }
        temp = head;
        Node* t2 = h2;
        while (temp != nullptr) {
            if (temp->random != nullptr) {
                int c = temp->random->val;
                int i = head->val;
                Node* trav = h2;
                while (i < c) {
                    trav = trav->next;
                    i++;
                }
                t2->random = trav;
            }
            t2 = t2->next;
            temp = temp->next;
        }
        return h2;
    }
};
