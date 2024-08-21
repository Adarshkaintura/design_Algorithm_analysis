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
void mergesort(ListNode& start,ListNode* mid,int len){
    
}
    ListNode* sortList(ListNode* head) {
       if(head==nullptr){
        return head;
       }  
      int len=0;
      ListNode* temp=head;
      while(temp!=nullptr){
        len++;
        temp=temp->next;
      }
   vector<int> arr;
   temp=head;
   while(temp!=nullptr){
      arr.push_back(temp->val);
      temp=temp->next;
   }
   sort(arr.begin(),arr.end());
   temp=head;
   int i=0;
   while(temp!=nullptr){
    temp->val=arr[i++];
    temp=temp->next;
   }
       return head;
    }
};
