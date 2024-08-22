class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;

        while (current != nullptr) {
            // Save the next node
            next = current->next;

            // Reverse the current node's pointer
            current->next = prev;

            // Move pointers one position ahead
            prev = current;
            current = next;
        }

        // At the end, prev will be the new head
        return prev;
    }

   
    ListNode* findK(ListNode* head,int k){
        if(head==nullptr){
            return head;
        }
        int i=1;
        while(i<k && head!=nullptr){
            head=head->next;
            i++;
        }
        if(head==nullptr){
            return nullptr;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr){
            return head;
        }
        ListNode* temp=head;
        ListNode* prevnode=nullptr;
        while(temp!=nullptr){
            ListNode* knode=findK(temp,k);
            if(knode==nullptr){
                if(prevnode){
                    prevnode->next=temp;
                }
                break;
            }
           ListNode* nextnode=knode->next;
            knode->next=nullptr;
            reverse(temp);
            if(temp==head){
                head=knode;
            }else{
                prevnode->next=knode;
            }
            prevnode=temp;
            temp=nextnode;
        }
        return head;
    }
};
