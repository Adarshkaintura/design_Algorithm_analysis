  public:
    void rearrange(vector<int> &arr) {
        int n=arr.size();
        vector<int> pos;
        vector<int> neg;
        for(int i=0;i<n;i++){
            if(arr[i]>=0){
                pos.push_back(arr[i]);
            }else{
                neg.push_back(arr[i]);
            }
            
        }
        int j=0;
        int k=0;
        int i=0;
        while(i<n && j<pos.size() && k<neg.size()){
            if(i%2==0){
                arr[i]=pos[j];
                j++;
            }
            else{
                arr[i]=neg[k];
                k++;
            }
            i++;
        }
    while(j<pos.size()){
        arr[i]=pos[j++];
        i++;
    }
    while(k<neg.size()){
        arr[i]=neg[k++];
        i++;
    }
    }
