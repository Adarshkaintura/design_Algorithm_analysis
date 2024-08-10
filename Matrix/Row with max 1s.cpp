 int rowWithMax1s(vector<vector<int> > &arr) {
        int maxCount=0;
        int index=-1;
        for(int i=0;i<arr.size();i++){
            int l=0;
            int h=arr[i].size()-1;
            int count=0;
            while(l<=h){
                int m=(l+h)/2;
                if(arr[i][m]==1){
                    count=arr[i].size()-m;
                    h=m-1;
                }else{
                    l=m+1;
                }
            }
            if(count>maxCount){
                maxCount=count;
                index=i;
            }
        }
        return index;
    }
