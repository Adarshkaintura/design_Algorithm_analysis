 vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        Node* low=head;
        Node* high=NULL;
        int l=1;
        int h=0;
        while(low!=NULL){
            high=low;
            h++;
            low=low->next;
        }
        vector<pair<int,int>> ans;
        low=head;
        while(l<h){
            int a=low->data;
            int b=high->data;
            if(a+b == target){
                ans.push_back({a,b});
                low=low->next;
                high=high->prev;
                l++;
                h--;
            }else if(a+b > target){
                high=high->prev;
                h--;
            }else{
                low=low->next;
                l++;
            }
        }
        return ans;
    }
