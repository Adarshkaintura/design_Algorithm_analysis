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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;

        while (current != nullptr) {
            next = current->next; // Store the next node
            current->next = prev; // Reverse the current node's pointer
            prev = current;       // Move prev to current
            current = next;       // Move current to next node
        }

        return prev; // prev becomes the new head of the reversed list
    }
    ListNode* findK(ListNode* head, int k) {
        if (head == nullptr) {
            return head;
        }
        int i = 1;
        while (i < k && head != nullptr) {
            head = head->next;
            i++;
        }
        if (head == nullptr) {
            return nullptr;
        }
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr){
            return head;
        }
        int l = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            temp = temp->next;
            l++;
        }
        if (k >= l) {
            k = k % l;
        }
      k = l - k;
        temp = head;
        ListNode* nodek = findK(temp, k);
        ListNode* nextnode = nodek->next;
        nodek->next = nullptr;
        temp = head;
        reverseList(temp);
        head->next = reverseList(nextnode);
        head = nodek;
        head = reverseList(head);

        return head;
    }
};
