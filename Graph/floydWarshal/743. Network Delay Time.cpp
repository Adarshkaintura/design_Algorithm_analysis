class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> dist(n+1,vector<int>(n+1,INT_MAX));
        for(auto& it:times){
            dist[it[0]][it[1]]=it[2];
          
        }
        for(int i=1;i<=n;i++){
            dist[i][i]=0;
        }
        for(int via=1;via<=n;via++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(dist[via][j]!=INT_MAX && dist[i][via]!=INT_MAX ){
                        dist[i][j]=min(dist[i][j],dist[via][j]+dist[i][via]);
                    }
                }
            }
        }
int max_dist=0;
for(int i=1;i<=n;i++){
    max_dist=max(max_dist,dist[k][i]);
}
if(max_dist==INT_MAX){
    return -1;
}
return max_dist;
    }
};
