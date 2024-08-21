/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (headA == nullptr || headB == nullptr) {
        return nullptr;
    }

    std::stack<ListNode*> s1;
    std::stack<ListNode*> s2;

    // Push all nodes of list A onto stack s1
    ListNode* l1 = headA;
    while (l1 != nullptr) {
        s1.push(l1);
        l1 = l1->next;
    }

    // Push all nodes of list B onto stack s2
    ListNode* l2 = headB;
    while (l2 != nullptr) {
        s2.push(l2);
        l2 = l2->next;
    }

    ListNode* ans = nullptr;

    // Compare nodes from the end
    while (!s1.empty() && !s2.empty()) {
        ListNode* a = s1.top();
        ListNode* b = s2.top();
        s1.pop();
        s2.pop();

        // If nodes are the same, update the answer
        if (a == b) {
            ans = a;
        } else {
            break;
        }
    }

    return ans;  // The intersection node or nullptr if no intersection
}

};
