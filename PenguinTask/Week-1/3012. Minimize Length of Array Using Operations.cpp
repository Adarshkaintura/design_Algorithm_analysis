//wrong answer but 255 test cases were passed
class Solution {
public:
bool allSame(vector<int>& nums,int n){
    for(int i=1;i<n;i++){
        if(nums[i]!=nums[i-1]){
            return false;
        }
    }
    return true;
}
    int minimumArrayLength(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        bool flag=true;
        while(flag){
            if(allSame(nums,n)){
            flag=false;
           }
           if(flag){
              if(n%2==0){
            n=n/2;
           }else{
            n=(n/2)+1;
           }
           }
          
           
        }
        if(n%2==0){
            return min(n,1);
        }
        return min(n,2);
    }
};
//correct asnwer\
class Solution {
public:

    int minimumArrayLength(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
       int mini=nums[0];
       int first=nums[0];
int cnt=0;
       for(int i=0;i<n;i++){
        if(nums[i]==mini){
            cnt++;
        }
        if(nums[i]%mini!=0){
            int a=nums[i]%mini;
            if(a!=mini){
                return 1;
            }
            mini=min(a,mini);
        }
       }
       if(cnt==1){
        return 1;
       }else{
        return (cnt+1)/2;
       }
    }
};
