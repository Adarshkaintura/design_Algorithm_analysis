 void deleteAllOccurOfX(struct Node** head, int x) {
        if(*head==NULL){
            return;
        }
        Node* temp=*head;
        int n=0;
        Node* del=NULL;
        while(temp!=NULL){
            if(temp->data==x){
                if(temp== *head){
                    *head=(*head)->next;
                    del=temp;
                     temp=*head;
                    temp->prev=NULL;
                    delete del;
                   
                }else{
                    temp->prev->next=temp->next;
                    if(temp->next!=NULL){
                          temp->next->prev=temp->prev;
                    }
                  
                    del=temp;
                    temp=temp->next;
                    delete del;
                }
            }else{
                temp=temp->next;
            }
        }
        
    }
