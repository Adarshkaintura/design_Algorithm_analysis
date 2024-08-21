class Solution {
 public:
 void insertNode(ListNode*& head, ListNode*& tail, int value) {
    ListNode* newNode = new ListNode(value);

    if (head == nullptr) {
        // If the list is empty, the new node becomes both head and tail
        head = newNode;
        tail = newNode;
    } else {
        // Append the new node to the tail and update the tail pointer
        tail->next = newNode;
        tail = newNode;
    }
}
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       if(l1==nullptr && l2==nullptr){
        return l1;
       }else if(l1==nullptr){
        return l2;
       }else if(l2==nullptr){
        return l1;
       }
       int carry=0;
       ListNode* head=nullptr;
       ListNode* tail=nullptr;
       while(l1!=nullptr || l2!=nullptr || carry){
           int num=carry;
           if(l1!=nullptr){
               num += l1->val;
               l1=l1->next;
           }
           if(l2!=nullptr){
            num += l2->val;
            l2=l2->next;
           }
         
           carry=num/10;
             num=num%10;
           insertNode(head,tail,num);
       }
       
       return head;
  }
};
