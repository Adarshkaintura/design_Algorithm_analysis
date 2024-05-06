//brute
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
    ListNode* removeNodes(ListNode* head) {
     ListNode* head2=nullptr;
     ListNode* temp=head;
     ListNode* h2=nullptr;
     
     while(temp!=NULL){
        int flag=1;
        ListNode* tryl=temp->next;
        while(tryl!=nullptr){
            if(tryl->val>temp->val){
                flag=0;
            }
            tryl=tryl->next;
        }
        if(flag){
            ListNode* newnode=new ListNode(temp->val);
            if(head2==nullptr){
                head2=newnode;
                h2=newnode;
            }else{
                h2->next=newnode;
                h2=h2->next;
            }
           
        }
        temp=temp->next;
     }
    return head2;
    }
};
//a bit space optimized 
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
    ListNode* removeNodes(ListNode* head) {
     ListNode* head2=nullptr;
     ListNode* temp=head;
     ListNode* h2=nullptr;
     
     while(temp!=NULL){
        int flag=1;
        ListNode* tryl=temp->next;
        while(tryl!=nullptr){
            if(tryl->val>temp->val){
                flag=0;
            }
            tryl=tryl->next;
        }
        if(flag){
            ListNode* newnode=temp;
            if(head2==nullptr){
                head2=newnode;
                h2=newnode;
            }else{
                h2->next=newnode;
                h2=h2->next;
            }
           
        }
        temp=temp->next;
     }
    return head2;
    }
};
//optimization of time but space in n
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
    ListNode* removeNodes(ListNode* head) {
     stack<ListNode*> s;
     ListNode* temp=head;
     while(temp!=nullptr){
        s.push(temp);
        temp=temp->next;
     }
     int maxi=INT_MIN;
     ListNode* newhead=nullptr;
     ListNode* new2=nullptr;
     while(!s.empty()){
        ListNode* curr=s.top();
        s.pop();
        if(curr->val>=maxi){
            maxi=curr->val;
           if(newhead==nullptr){
            newhead=curr;
            newhead->next=nullptr;
            new2=curr;
           }else{
               curr->next=new2;
               new2=curr;
           }
        }
     }
     return new2;
    }
  
};
//it can further optimized by just reversing the list i am doing the code becuase it can be done 


