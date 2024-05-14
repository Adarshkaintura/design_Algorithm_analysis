typedef pair<int,pair<int,int>> pt;
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        priority_queue<pt,vector<pt>,greater<pt>> pq;
        int cols=columns;
         vector<vector<int>> dist(rows,vector<int>(cols,INT_MAX));
        pq.push({0,{0,0}});
        dist[0][0] = 0;
        while(!pq.empty()){
           auto temp=pq.top();
           pq.pop();
           int a=temp.first;
           int row=temp.second.first;
           int col=temp.second.second;
           if(row==rows-1 && col==cols-1){
               return a;
           }
           int rown=row+1;
           int coln=col;
           if(rown<rows && coln<cols && rown>=0 && coln>=0){
               int b=abs(heights[row][col]-heights[rown][coln]);
           b=max(b,a);
           if(b<dist[rown][coln]){
               dist[rown][coln]=b;
                pq.push({b,{rown,coln}});
           }
          
           }
           
           rown=row;
           coln=col+1;
           if(rown<rows && coln<cols && rown>=0 && coln>=0){
           int c=abs(heights[row][col]-heights[rown][coln]);
            c=max(c,a);
           if(c<dist[rown][coln]){
               dist[rown][coln]=c;
                pq.push({c,{rown,coln}});
           }
            
           }
           rown=row;
           coln=col-1;
           if(rown<rows && coln<cols && rown>=0 && coln>=0){
           int c=abs(heights[row][col]-heights[rown][coln]);
            c=max(c,a);
           if(c<dist[rown][coln]){
               dist[rown][coln]=c;
                pq.push({c,{rown,coln}});
           }
            
           }
           rown=row-1;
           coln=col;
           if(rown<rows && coln<cols && rown>=0 && coln>=0){
           int c=abs(heights[row][col]-heights[rown][coln]);
            c=max(c,a);
           if(c<dist[rown][coln]){
               dist[rown][coln]=c;
                pq.push({c,{rown,coln}});
           }
            
           }
           
        }
        dist[rows-1][cols-1];
        
    }
