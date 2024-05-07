//brute but didn't work in all test cases run time error because of space 
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
    ListNode* doubleIt(ListNode* head) {
      if(head!=nullptr){
           string s="";
           ListNode* temp=head;
           while(temp!=NULL){
            s+=to_string(temp->val);
            temp=temp->next;
           }
           long long a = stoll(s);
           a+=a;
           if(a==0){
            return head;
           }
           temp=nullptr;
           ListNode* head2=nullptr;
            while(a!=0){
                int t=a%10;
                ListNode* newnode=new ListNode(t);
                a=a/10;
                
                    newnode->next=temp;
                    temp=newnode;
                
            }
            head2=temp;
            
            temp = head;
            while (temp != nullptr) {
                ListNode* nextNode = temp->next;
                delete temp;
                temp = nextNode;
            }
            return head2;
      }
return head;
    }
};
//optimized
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
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        
        while (curr != nullptr) {
            next = curr->next; // Save next node
            curr->next = prev; // Reverse the link
            prev = curr;       // Move pointers one step ahead
            curr = next;
        }
        
        return prev; // New head is prev
    }
    ListNode* doubleIt(ListNode* head) {
      if(head!=nullptr){
         
         head=reverseList(head);
         ListNode* temp=head;
         int carry=0;
         ListNode* prev=nullptr;
         while(temp!=nullptr){
            int num = temp->val * 2 + carry;
                temp->val = num % 10;
                carry = num / 10;
                prev=temp;
                temp = temp->next;
         }
         if(carry){
            ListNode* newnode=new ListNode(1);
            prev->next=newnode;

         } 
         head=reverseList(head);
return head;
      }
return head;
    }
};
