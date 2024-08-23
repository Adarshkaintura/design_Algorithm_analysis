 Node *flatten(Node *root) {
        if(root==NULL){
            return root;
        }
     priority_queue<Node*,vector<Node*>,comparatornode> pq;
     Node* temp=root;
     while(temp!=NULL){
         Node* flow=temp;
         while(flow!=NULL){
             pq.push(flow);
             flow=flow->bottom;
         }
         temp=temp->next;
     }
    Node* dummy = new Node(0);
    Node* current = dummy;
    
    // Reconstruct the flattened list
    while (!pq.empty()) {
        temp = pq.top();
        pq.pop();
        
        current->bottom = temp;
        current = current->bottom;
    }
    current->bottom=NULL;
    
    // The head of the flattened list is dummy->bottom
    return dummy->bottom;
     
    }
