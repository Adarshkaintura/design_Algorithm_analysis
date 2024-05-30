//brute
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int count=0;
        for(int i=0;i<arr.size();i++){
            int xor1 = 0;
            for(int j=i;j<arr.size();j++){
               xor1 ^= arr[j];
               int xor2 = 0;
                for(int k=j+1;k<arr.size();k++){
                   xor2 ^= arr[k];
                     if(xor2==xor1){
                       count++;
                }
                }
              
            }
        }
        return count;
    }
};
