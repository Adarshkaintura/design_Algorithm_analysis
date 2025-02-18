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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Custom comparator for min-heap
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val; // Min-heap (smallest value at the top)
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        // Push only head nodes into heap
        for (auto list : lists) {
            if (list) pq.push(list);  // Ensure list is not null
        }

        ListNode* dummy = new ListNode(); // Dummy node to track head
        ListNode* tail = dummy;

        while (!pq.empty()) {
            ListNode* minNode = pq.top();
            pq.pop();
            
            tail->next = minNode;
            tail = minNode;

            if (minNode->next) pq.push(minNode->next);
        }

        return dummy->next;
    }
};
