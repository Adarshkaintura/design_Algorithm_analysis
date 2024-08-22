   Node* removeDuplicates(Node* head) {
    if (head == NULL) {
        return head;
    }
    
    Node* temp = head;
    
    while (temp != NULL && temp->next != NULL) {
        if (temp->data == temp->next->data) {
    
            Node* duplicate = temp->next;
            if(duplicate->next!=NULL){
               duplicate->next->prev=temp;   
            }
            temp->next = temp->next->next;
            delete duplicate;
        } else {
            temp = temp->next;
        }
    }
    
    return head;
}
