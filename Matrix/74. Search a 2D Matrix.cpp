class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int m = matrix.size();
        if (m == 0) return false;
        
        int n = matrix[0].size();
        if (n == 0) return false;

        int l=0;
        int h=(n*m)-1;
        while(l<=h){
            int md=(l+h)/2;
            int temp = matrix[md / n][md % n];
            if(temp==target){
                return true;
            }else if(temp<target){
                  l=md+1;
            }else{
                h=md-1;
            }
        }
        return false;
    }
};
