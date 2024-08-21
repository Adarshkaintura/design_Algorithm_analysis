 Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;  // Store next node
        current->next = prev;   // Reverse current node's pointer
        prev = current;         // Move pointers one position ahead
        current = next;
    }
    
    return prev;  // New head of the reversed list
}
    Node* addOne(Node* head) {
        if(head==NULL){
            return head;
        }
        Node* temp=head;
        temp=reverseList(temp);
        Node* temp1=temp;
        temp->data =temp->data+1;
      int carry=0;
      Node* prev=NULL;
        if(temp->data>9){
            prev=temp;
            temp->data=0;
            temp=temp->next;
            carry=1;
        }
        if(carry){
            
              while(temp!=NULL){
                  if(carry==0){
                      break;
                  }
            int a=temp->data;
            if(a==9){
                temp->data=0;
                carry=1;
            }else{
                temp->data += 1;
                carry=0;
            }
            prev=temp;
              temp=temp->next;
        }
        }
        if(carry==1){
            Node* newnode=new Node(1);
            prev->next=newnode;
        }
       
        head=reverseList(temp1);
        return head;
    }
