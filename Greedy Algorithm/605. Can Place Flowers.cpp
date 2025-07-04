class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
      int i=0,s=flowerbed.size();
      while(n && i<flowerbed.size()){
        if(flowerbed[i]==0){
        bool lefte=(i==0 || flowerbed[i-1]==0);
        bool righte=(i==s-1 || flowerbed[i+1]==0);
         if(lefte && righte){
            flowerbed[i]=1;
            n--;
            if(n==0) return true;

            i++;
         }
        }
         i++;

      }
      return n<=0;
    }
};
