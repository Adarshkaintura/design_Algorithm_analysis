  Node* segregate(Node* head) {

   if(head==NULL){
       return head;
   }
   Node* temp=head;
   int n=0;
   while(temp!=nullptr){
       temp=temp->next;
       n++;
   }
        vector<int> arr(n,3);
        temp=head;
        int i=0;
        int h=n-1;
        while(temp!=NULL){
          if(temp->data==2){
              arr[h--]=2;
          }else if(temp->data==0){
              arr[i++]=0;
          }
          temp=temp->next;
        }
       temp=head;
        i=0;
       while(temp!=NULL){
           if(arr[i]==3){
               temp->data=1;
           }else{
               temp->data=arr[i];
           }
           i++;
           temp=temp->next;
       }
       return head;
    }
